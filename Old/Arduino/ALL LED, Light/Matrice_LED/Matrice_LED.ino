
boolean matrice[3][3] = {
  0, 0, 1,
  0, 0, 0,
  1, 0, 0
};
byte ligne[3] = {4, 3, 2};
byte colonne[3] = {5, 6, 7};

void setup() {
  //initialisation des pins en OUTPUT et mise à l'état LOW
  for (int l = 2; l < 8; l++) {
    pinMode(l, OUTPUT);
    if (l > 1 && l < 4)
      digitalWrite(l, LOW);
    else
      digitalWrite(l, HIGH);
  }
}

void loop() {
  affiche(); //appel de la fonction d'affichage
}
// fonction d'affichage
void affiche() {
  for (byte l = 0; l < 3; l++) { //on parcourt les lignes
    digitalWrite(ligne[l], HIGH); //on prépare la ligne à l'affichage
    for (byte c = 0; c < 3; c++) { //on parcourt chaque case de la ligne (colonne)
      if (matrice[l][c]) { //on teste si affichage dans matrice
        digitalWrite(colonne[c], LOW); //on allume
        delay(2); //avec un delai
        digitalWrite(colonne[c], HIGH); //on éteint
      }
    }
    digitalWrite(ligne[l], LOW); //on arrête la ligne
  }
}

