int pinLed[3]={2,4,6};
int temps = 1000;
void setup() 
{
  for (int i=0; i<3; i++)
  {
  pinMode(pinLed[i], OUTPUT);
  }
  
  for (int i=0; i<3; i++)
  {
  digitalWrite(pinLed[i], LOW);
  }

}

void loop() 
{
  for (int i=0; i<3; i++)
  {
  digitalWrite(pinLed[i], HIGH);
  delay(50);
  }  
  delay(temps);
  for (int i=0; i<3; i++)
  {
  digitalWrite(pinLed[i], LOW);
  delay(50);
  }
  digitalWrite(pinLed[2], HIGH);
  delay(temps); 
  digitalWrite(pinLed[2], LOW);
  digitalWrite(pinLed[1], HIGH);
  delay(temps);
  digitalWrite(pinLed[1], LOW);
  digitalWrite(pinLed[0], HIGH); 
  delay(temps);
  digitalWrite(pinLed[0], LOW);
  delay(200);
  temps-=100;
  

}
