#include <Wire.h> 
#include <LiquidCrystal_I2C.h>  // I2C kütüphanesini verdiğim linkten indirip   include edebilirsiniz
LiquidCrystal_I2C lcd(0x27,16,2); 
void setup()
{
 lcd.begin();                      // LCD yi başlatma
 
 lcd.backlight();                 // lcd nin arka ışıgını açar
 lcd.print("Napion!");
 lcd.setCursor(0,1);
 lcd.print("test");
}
void loop()
{
}
