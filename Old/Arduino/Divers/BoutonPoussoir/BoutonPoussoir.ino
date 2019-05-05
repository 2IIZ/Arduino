int pinBouton;
int ledOne;
int ledTwo;

void setup() {
  Serial.begin(9600);
  pinBouton=2;
  ledOne=4;
  ledTwo=6;
  pinMode(pinBouton, INPUT);
  pinMode(ledOne, OUTPUT);
  pinMode(ledTwo, OUTPUT);
}

void loop() {
  
  boolean etatBouton=digitalRead(pinBouton);
  Serial.println(etatBouton);

  if(etatBouton==HIGH)
  {
      digitalWrite(ledOne, HIGH);
      digitalWrite(ledTwo, LOW);
  }
  if(etatBouton==LOW)
  {
    digitalWrite(ledTwo,HIGH);
    digitalWrite(ledOne, LOW);
  }
}
