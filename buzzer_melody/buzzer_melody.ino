const int buzzer = 10;
void setup()
{
  pinMode(buzzer, OUTPUT);
  int melody[] = {200,100,600,200,500,600,100,300,100,180,170,500};                         // initializing variables for playing melody
}

void loop()
{
  for(int i = 0;i < 12;i++ )
  {
    tone(buzzer,i);
    delay(20);
    noTone(buzzer);
    delay(20);
  }
}
