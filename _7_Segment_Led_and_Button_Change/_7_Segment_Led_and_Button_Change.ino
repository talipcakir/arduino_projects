int E=2; int D=3; int C=4; int P=5;
int B=6;int A=7; int F=8; int G=9;

int buttonStat = 0;

void setup() 
  {
    //Serial.begin(9600);
    pinMode(E, OUTPUT); pinMode(D, OUTPUT); pinMode(C, OUTPUT);
    pinMode(A, OUTPUT); pinMode(B, OUTPUT); pinMode(F, OUTPUT); 
    pinMode(G, OUTPUT); pinMode(P, OUTPUT); 
    //button pin:
    pinMode(12,INPUT_PULLUP);
  }
void loop() 
  {
    int i = 0;
    while(i < 10)
    {
      buttonStat = digitalRead(12);
      if(buttonStat == HIGH)
      i = i + buttonStat;
      RakamYaz(i);
      delay(190);
    }
  }
void RakamYaz(int rakam)
{
switch(rakam)
{
case 0 :
digitalWrite(E,HIGH);
digitalWrite(D,HIGH); 
digitalWrite(C,HIGH); 
digitalWrite(B,HIGH); 
digitalWrite(A,HIGH); 
digitalWrite(F,HIGH); 
digitalWrite(G,LOW); 
break;
case 1:
digitalWrite(E,LOW);
digitalWrite(D,LOW); 
digitalWrite(C,HIGH); 
digitalWrite(B,HIGH); 
digitalWrite(A,LOW); 
digitalWrite(F,LOW); 
digitalWrite(G,LOW); 
break;
case 2:
digitalWrite(E,HIGH);
digitalWrite(D,HIGH); 
digitalWrite(C,LOW); 
digitalWrite(B,HIGH); 
digitalWrite(A,HIGH); 
digitalWrite(F,LOW); 
digitalWrite(G,HIGH); 
break;
case 3:
digitalWrite(E,LOW);
digitalWrite(D,HIGH); 
digitalWrite(C,HIGH); 
digitalWrite(B,HIGH); 
digitalWrite(A,HIGH); 
digitalWrite(F,LOW); 
digitalWrite(G,HIGH); 
break;
case 4:
digitalWrite(E,LOW);
digitalWrite(D,LOW); 
digitalWrite(C,HIGH); 
digitalWrite(B,HIGH); 
digitalWrite(A,LOW); 
digitalWrite(F,HIGH); 
digitalWrite(G,HIGH); 
break;
case 5:
digitalWrite(E,LOW);
digitalWrite(D,HIGH); 
digitalWrite(C,HIGH); 
digitalWrite(B,LOW); 
digitalWrite(A,HIGH); 
digitalWrite(F,HIGH); 
digitalWrite(G,HIGH); 
break;
case 6:
digitalWrite(E,HIGH);
digitalWrite(D,HIGH); 
digitalWrite(C,HIGH); 
digitalWrite(B,LOW); 
digitalWrite(A,HIGH); 
digitalWrite(F,HIGH); 
digitalWrite(G,HIGH); 
break;
case 7:
digitalWrite(E,LOW);
digitalWrite(D,LOW); 
digitalWrite(C,HIGH); 
digitalWrite(B,HIGH); 
digitalWrite(A,HIGH); 
digitalWrite(F,LOW); 
digitalWrite(G,LOW); 
break;
case 8:
digitalWrite(E,HIGH);
digitalWrite(D,HIGH); 
digitalWrite(C,HIGH); 
digitalWrite(B,HIGH); 
digitalWrite(A,HIGH); 
digitalWrite(F,HIGH); 
digitalWrite(G,HIGH); 
break;
case 9:
digitalWrite(E,LOW);
digitalWrite(D,HIGH); 
digitalWrite(C,HIGH); 
digitalWrite(B,HIGH); 
digitalWrite(A,HIGH); 
digitalWrite(F,HIGH); 
digitalWrite(G,HIGH); 
break;
}
}
