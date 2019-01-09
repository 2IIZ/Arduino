const int CONNEXION=13;

void setup()
{
    pinMode(CONNEXION,HIGH);  //Signale à l’Arduino que la connexion 13 doit pouvoir envoyer du courant
}

void loop()
{
  digitalWrite(CONNEXION,HIGH);
  delay(1000);
  digitalWrite(13,LOW);
  delay(1000);
}
