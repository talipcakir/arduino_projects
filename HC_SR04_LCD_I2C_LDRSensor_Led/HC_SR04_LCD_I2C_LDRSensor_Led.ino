//In this project, the distance data from the hc-sr04 sensor is sent to the LCD screen as output.
//Arguments used:
//-HC-SR04 sensor
//-16 * 2 LCD (I2C module integrated)
// (Module Pin = Arduino Pin)
//HC-SR sensor:
//  VCC = 5v
//  Trig = 3 (Digital)
//  Echo = 2 (Digital)
//  GND = GND
//  
//I2C Module:
//  GND = GND
//  VCC = 5v
//  SDA = A4 (Analog)
//  SDL = A5 (Analog)

//If you want 'Serial' code at the beginning of the '//' signs can be removed from the serial monitor data.
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>  // I2C lib

// Define Trig and Echo pin:
#define trigPin 2
#define echoPin 3
//Const Led and Ldr pin
const int ledPin = 13;
const int ldrPin = A0;
// Define variables:
long duration;
int distance;

LiquidCrystal_I2C lcd(0x27,16,2); 

void setup()
{
 lcd.begin();                      // LCD start
  // Define inputs and outputs:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT); //led
  pinMode(ldrPin, INPUT);  //ldr sensor
  //Begin Serial communication at a baudrate of 9600:
  Serial.begin(9600);
   lcd.backlight();
   lcd.setCursor(0,0);
   lcd.print("Start System!");
   lcd.setCursor(0,1);
   lcd.print("Sensor is Ready...");
   delay(4000);
}
void loop()
{
  // Clear the trigPin by setting it LOW:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  // Trigger the sensor by setting the trigPin high for 10 microseconds:
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Read the echoPin, pulseIn() returns the duration (length of the pulse) in microseconds:
  duration = pulseIn(echoPin, HIGH);
  // Calculate the distance:
  distance= duration*0.034/2; //for cm.
  // Print the distance on the Serial Monitor (Ctrl+Shift+M):
  //Serial.print("Distance = ");
  //Serial.print(distance);
  //Serial.println(" cm");
  lcd.clear(); //lcd screen clear
  lcd.setCursor(0,0);
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print("cm");
  lcd.setCursor(0,1); 
  int ldrStatus = analogRead(ldrPin);
  //Light rating of the room with the ldr sensor
  if(ldrStatus>760)
      lcd.print("Room: Darkness");
  else if(ldrStatus>550)
      lcd.print("Room: Shadowy");
  else if(ldrStatus>330)
      lcd.print("Room: Daylight");
  else if(ldrStatus>180)
      lcd.print("Room: Lighting");
  else
      lcd.print("Room: Spotlight");
      //led open/close
  if (ldrStatus >=600) 
    digitalWrite(ledPin, HIGH);
  else 
  {
    digitalWrite(ledPin, LOW);
  }
Serial.print(analogRead(ldrPin));
  delay(3000); //stop time
}
