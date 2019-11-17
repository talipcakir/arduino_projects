#include <Wire.h> 
#include <LiquidCrystal_I2C.h>  // I2C lib

// Define Trig and Echo pin:
#define trigPin 2
#define echoPin 3
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
  //Begin Serial communication at a baudrate of 9600: (for sensor control)
  Serial.begin(9600);

}
void loop()
{
   lcd.backlight();
   lcd.setCursor(0,0);
   lcd.print("Start System!");
   lcd.setCursor(0,1);
   lcd.print("Sensor is Ready...");
   delay(4000);
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
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Distance:");
  lcd.setCursor(0,1);
  lcd.print(distance);
  lcd.print("cm");
   
  delay(4000); //stop time
}
