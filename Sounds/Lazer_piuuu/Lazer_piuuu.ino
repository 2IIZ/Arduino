int plop=12;

int p=10; // on prépare une variable pour la période
void setup() {
  pinMode(plop,OUTPUT); //on prépare le pin en mode sortie
}
void loop() {
    p++; // on incémente p à chaque boucle de loop();
    if (p>500){ // teste la limite de p
      p=10; // on le remet à 10
      delay(500); // on attend un peu
    }
    digitalWrite(plop,0); // état bas
    delayMicroseconds(p); //on attend p milli-secondes
    digitalWrite(plop,1); // état haut
    delayMicroseconds(p); // on attend p millisecondes
}
