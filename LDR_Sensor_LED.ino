/*
In this application, the ldr sensor measures the light degree of the room and provides us information from the LCD screen.
I2C Module:
  GND = GND
  VCC = 5v
  SDA = A4 (Analog)
  SDL = A5 (Analog)

LDR Sensor:
  (Have 2 pin)
  Pin 1 = GND
  Pin 2  (parallel connect)
      5V (use 10k OHM resistor for 5v connection) 
      A0 (Analog)
  LDR Connection
  https://fritzing.org/media/fritzing-repo/projects/l/light-dependant-resistor-sensor/images/LDR_bb.png
  LDR + LED connection
  http://www.theorycircuit.com/wp-content/uploads/2015/12/Photocell-arduino.jpg
*/
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>  // I2C lib
//Const Led and Ldr pin
const int ledPin = 13;
const int ldrPin = A0;

LiquidCrystal_I2C lcd(0x27,16,2); 

void setup()
{
 lcd.begin();                      // LCD start
  // Define inputs and outputs:
  pinMode(ledPin, OUTPUT); //led
  pinMode(ldrPin, INPUT);  //ldr sensor
  //Begin Serial communication at a baudrate of 9600:
  //Serial.begin(9600);
   lcd.backlight();
   lcd.setCursor(0,0);
   lcd.print("Start System!");
   lcd.setCursor(0,1);
   lcd.print("Sensor is Ready...");
   delay(4000);
}
void loop()
{
  lcd.clear(); //lcd screen clear
  lcd.setCursor(0,0);
  int ldrStatus = analogRead(ldrPin);
  //Light rating of the room with the ldr sensor
  if(ldrStatus>760)
      lcd.print("Room: Darkness");
  else if(ldrStatus>550)
      lcd.print("Room: Shadowy");
  else if(ldrStatus>300)
      lcd.print("Room: Daylight");
  else if(ldrStatus>180)
      lcd.print("Room: Lighting");
  else
      lcd.print("Room: Spotlight");
      //led open/close
  if (ldrStatus >=600) 
    digitalWrite(ledPin, HIGH);
  else 
    digitalWrite(ledPin, LOW);
  lcd.setCursor(0,1);
  lcd.print("Light Range: ");
  lcd.print(ldrStatus);
//Serial.print(analogRead(ldrPin));
  delay(1000); //stop time
}
