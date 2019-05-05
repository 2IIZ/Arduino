int valPot=0; 
int led=2;

void setup() {
  Serial.begin(9600); //Initialisation de la communication avec la console
  pinMode(led,OUTPUT);
}

void loop() {
  valPot=analogRead(A0); //lit la tension, la convertit en valeur numérique et la stocke dans valeurPot

  Serial.println(valPot);
  
  int valInter=int(valPot*5/1024)+1;
  int attente = int(1000/valInter/2);
  digitalWrite(led,HIGH);
  delay (attente);
  digitalWrite(led,LOW);
  delay(attente);
  
}
