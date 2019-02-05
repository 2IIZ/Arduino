long portPotentiometre = A0;
long valeurPotentiometre;

void setup() {
  Serial.begin(9600);

}

void loop() {
  valeurPotentiometre = analogRead(portPotentiometre);
  Serial.println(valeurPotentiometre);
  delay(1);

}
