int numPin;
const int multiplicateur=7;

void setup()
{
  numPin = 13;
  pinMode(numPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("TAble De Multiplication");
  for (int compteur = 0; compteur <= 11; compteur++)
  {
    Serial.println(compteur * multiplicateur);
    //boucle de clignotement
    //compteur sert de limite à la boucle
    //donc le nombre de clignotements augmente à chaque tour
    for (int nbClignote = 0; nbClignote < compteur; nbClignote++)
    {
      digitalWrite(numPin, HIGH);
      delay(50);
      digitalWrite(numPin, LOW);
      delay(50);
    }
    delay(1000); //attente de 1s
  }
  Serial.println("*** Ayé ! ***");
}

void loop()
{

}
