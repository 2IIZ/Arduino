#include <Wire.h> //bibliothèque pour la communication I2C
#include <Adafruit_MotorShield.h> //bibliothèque pour le shield
Adafruit_MotorShield monShield = Adafruit_MotorShield(); //création de l'objet shield
Adafruit_DCMotor *moteurGauche = monShield.getMotor(1); //création de l'objet moteurGauche par pointeur et repérage du numéro
Adafruit_DCMotor *moteurDroite = monShield.getMotor(2); //création de l'objet moteurDroite par pointeur et repérage du numéro
void setup() {
  monShield.begin(); //On lance la communication avec le shield
  moteurGauche->setSpeed(255); //On définit la vitesse de rotation
  moteurDroite->setSpeed(255); //des deux moteurs
  
}
void loop() {
  arret();
  delay(1000);
  avance(255);
  delay(1000);
  recule(255);
  delay(1000);
  tourneDroite(255);
  delay(1000);
  tourneGauche(255);
  delay(1000);
}
void arret(){
  //fonction d'arrêt des deux moteurs
  moteurGauche->run(RELEASE);
  moteurDroite->run(RELEASE);
}
void defVitesse(int v){
  moteurGauche->setSpeed(v); //on redéfinit la vitesse
  moteurDroite->setSpeed(v); //des deux moteurs
}
void avance(int v){
  //fonction de marche avant
  defVitesse(v); //appel de la fonction pour définir la vitesse
  moteurGauche->run(FORWARD);
  moteurDroite->run(FORWARD);
}
void recule(int v){
  //fonction de marche arrière
  defVitesse(v);
  moteurGauche->run(BACKWARD);
  moteurDroite->run(BACKWARD);
}
void tourneDroite(int v){
  //fonction pour tourner à droite sur place
  defVitesse(v);
  moteurGauche->run(FORWARD);
  moteurDroite->run(BACKWARD);
}
void tourneGauche(int v){
  //fonction pour tourner à gauche sur place
  defVitesse(v);
  moteurGauche->run(BACKWARD);
  moteurDroite->run(FORWARD);
}


