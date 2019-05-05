int work=1; 

void setup()
{
    Serial.begin(9600);
    Serial.println("*** Debut du programme ***");
    pinMode(13,OUTPUT);
}

void loop()
{
    if (work=1)
    {
        for (int compteur=0;compteur<=20;compteur++)
        {
            Serial.println(compteur);
            digitalWrite(13,HIGH);
            delay (250);
            digitalWrite(13,LOW);

        }
        delay (1000);
       
    }
}
