int pinMoteur=10; //pin de commande relié au transistor

void setup() {
  pinMode(pinMoteur,OUTPUT); // pin de commande en mode sortie
}

void loop() {
  for (int pourcentage=0;pourcentage<=100;pourcentage+=25){//boucle de variation en %
    int valeur=map(pourcentage,0,100,0,255); //conversion en valeur
    analogWrite(pinMoteur,valeur); // pin de commande en mode impulsion
    delay (3000); // attente de 3 secondes
  }
}
