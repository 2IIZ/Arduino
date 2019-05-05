int ligne[2]={2,3}; //tableau pour stocker les pins des lignes
int colonne[2]={4,5}; //tableau pour stocker les pins des colonnes

void setup() {
//mise en OUTPUT et LOW des lignes et INPUT des colonnes
for (int i=0;i<2;i++){
pinMode(ligne[i], OUTPUT);
digitalWrite(ligne[i],LOW);
pinMode(colonne[i], INPUT);
}
Serial.begin(9600); //communication série
}

void loop() {
test(); //appel de la fonction test
}
//fonction de test des états des boutons

void test(){
for (int l = 1; l >=0; l--) { //boucle qui parcourt le tableau des lignes
digitalWrite(ligne[l], HIGH); //on place la ligne en HIGH
for (int c = 1; c >=0; c--) { //boucle qui parcourt le tableau des colonnes
boolean etat=digitalRead(colonne[c]); //on lit le résultat
if (etat) { // si etat==1
Serial.print(" D "); //on écrit D pour down
}
else { //sinon
Serial.print(" U "); //on écrit U pour up
}
}
digitalWrite(ligne[l], LOW); //on place la ligne en LOW
}
Serial.println(); //saut de ligne
delay(100); //petite attente
}
