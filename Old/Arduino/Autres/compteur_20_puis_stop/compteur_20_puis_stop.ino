boolean affichage; //variable pour stopper l'affichage
int numPin;

void setup()
{
    numPin=13;
    pinMode(numPin,OUTPUT);
    Serial.begin(9600);
    affichage=true; //initialisation de la variable à true
    Serial.println("*** Debut du programme ***");
}

void loop()
{
    if (affichage)
    {
        for (int compteur=1;compteur<=20;compteur ++)
        {
            Serial.println(compteur);
            for (int nbClignote=0;nbClignote<compteur;nbClignote ++)
            {   
                digitalWrite(numPin,HIGH);
                delay(250);
                digitalWrite(numPin,LOW);
                delay(250);
            }
            delay(500);
        }
        affichage=false;
        Serial.println("*** Ayé ! ***");
    }
}
