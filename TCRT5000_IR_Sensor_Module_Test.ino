const int pinDig = 8;   //digital pin
const int pinAna = A0;   //analog pin
const int pinLED = 9;    //for sensor led
int anaValue = 0;
int digiValue = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(pinDig, INPUT);
  pinMode(pinAna, INPUT);
  pinMode(pinLED, OUTPUT);
}

void loop()
{
  Serial.print("Analog Reading=");
  Serial.print(anaValue);
  Serial.print("\t Digital Reading=");
  Serial.print(digiValue);
  Serial.print("\n");
  delay(1000);
  
  anaValue = analogRead(pinAna);
  digiValue = digitalRead(pinDig);
}
//TCRT500 IR sensor modele
//4 pin
//VCC = 5V
//GND = GND
//D0 = 9 (Digital IN pin if change. Dont forget code change pin number)
//A0 = A0 (Analog IN. Look code and pin no.)
