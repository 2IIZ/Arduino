const int CONNEXION=13;
int temps = 150;

void setup()
{
    pinMode(CONNEXION,HIGH); 
}

void loop()
{
  digitalWrite(CONNEXION,HIGH);
  delay(temps);
  digitalWrite(CONNEXION,LOW);
  delay(temps);
  temps-=1;
}
