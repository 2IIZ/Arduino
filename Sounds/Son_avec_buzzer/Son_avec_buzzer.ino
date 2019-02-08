int plop=12;

void setup() {
  pinMode(plop,OUTPUT); //on prépare le pin plop en mode sortie  fréquence(Hz)=1/période(s)﻿
                            //donc 1/440=0,002272 secondes soit 2272 microsecondes. Ceci pour un aller-retour. Donc un aller ou un retour donne 2272/2=1136 microsecondes.
}
void loop() {
    digitalWrite(plop,0); // état bas
    delayMicroseconds(1136); //on attend 1136 milli-secondes
    digitalWrite(plop,1); // état haut
    delayMicroseconds(1136); // on attend 1136 millisecondes
}
