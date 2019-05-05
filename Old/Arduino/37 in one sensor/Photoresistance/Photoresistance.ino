int pinPR=A0; //pin de connexion pour la photorésistance
void setup() {
  Serial.begin(9600);
}

void loop() {
  int valeur=analogRead(pinPR); // on lit la valeur transmise par la photorésistance
  Serial.println(valeur); // on l'affiche
}
