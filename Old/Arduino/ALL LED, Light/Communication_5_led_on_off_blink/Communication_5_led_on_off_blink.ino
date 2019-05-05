int pins[5] = {2, 3, 4, 5, 6}; //tableau qui stocke les pins des LED
char comportements[5] = {0, 0, 0, 0, 0}; //tableau des comportements. 0 pour éteint, 1 pour allumé, 2 pour clignotant
boolean etats[5] = {0, 0, 0, 0, 0}; // tableau des états. 0 pour éteint, 1 pour allumé
unsigned long tempsDepart; // variable pour stocker le temps à un instant donné
int duree = 200; // variable pour stocker la durée de clignotement en ms

void setup() {
  Serial.begin (9600); // initialisation de la communication série
  // initialisation des LED et mise à LOW
  for (int l = 0; l < 5; l++) {
    pinMode(pins[l], OUTPUT);
    digitalWrite(pins[l], LOW);
  }
  //titre de présentation (c'est toujours plus sympa !)
  Serial.println("******************");
  Serial.println("* Gestion de LED *");
  Serial.println("******************");
  Serial.println("> start");//message de début de programme
  tempsDepart = millis(); //initialisation du temps de départ sur le temps actuel
}

void loop() {
  decodage(); //appel de la fonction de décodage
  timer(); // appel de la fonction de gestion du temps
  allumage(); // appel de la fonction d'allumage des LED
}

//------------------------fonctions
void decodage() {
  if (Serial.available()) {// teste s'il reste des données en attente
    String reception = "";
    while (Serial.available()) { //tant que des données sont en attente
      char c = Serial.read(); // lecture
      reception += String(c); //on ajoute à l'objet reception
      delay(10); //petite attente
    }
    reception.trim(); //on enlève le superflu en début et fin de chaîne
    reception = reception.substring(0, 5); // ne prend que les caractères de 0 à 4 (soit 5 caractères)
    Serial.print ("> Etat : ");
    //boucle de test par caractère
    for (int c = 0; c < 5; c++) {
      switch (reception.charAt(c)) {
        case 'a':
          Serial.print("\tON");
          comportements[c] = 1; //mise à jour du tableau des comportements
          break;
        case 'e':
          Serial.print("\tOFF");
          comportements[c] = 0; //mise à jour du tableau des comportements
          break;
        case 'c':
          Serial.print("\tCLI");
          comportements[c] = 2; //mise à jour du tableau des comportements
          break;
        default :
          comportements[c] = 0; //mise à jour du tableau des comportements par défaut à 0
          Serial.print("\t???");
      }
    }
    Serial.println(); // saut de ligne
    // boucle de mise à jour du tableau des états en fonction du tableau des comportements
    for (int l = 0; l < 5; l++) {
      if (!comportements[l]) {
        etats[l] = 0;
      }
      else {
        etats[l] = 1; // on allume aussi les lED clignotantes
      }
    }
  }
}
void timer() {
  unsigned long tempsActuel = millis(); //récupération du temps Arduino
  if (tempsActuel - tempsDepart >= duree) { //test si temps écoulé
    for (int l = 0; l < 5; l++) {
      if (comportements[l] == 2) { //test si comportement clignotant
        etats[l] = !etats[l]; //passe de 0 à 1 ou de 1 à 0
      }
    }
    tempsDepart = tempsActuel; //initialisation du temps de départ
  }
}

void allumage() {
  for (int l = 0; l < 5; l++) {
    digitalWrite(pins[l], etats[l]); //allumage des LED en fonction du tableau des Etats
  }
}

