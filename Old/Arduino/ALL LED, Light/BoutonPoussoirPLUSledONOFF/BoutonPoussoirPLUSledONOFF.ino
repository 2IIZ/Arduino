int pinBouton;
int ledOne;
int ledTwo;
int testZero=0;

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

  if(etatBouton==LOW)
  {
    testZero=1;
  }
  if(etatBouton==HIGH)
  {
    testZero=0;
  }

  if(testZero==0)
  {
    digitalWrite(ledOne, HIGH);
    digitalWrite(ledTwo, LOW);
  }
  if(testZero==1)
  {
    digitalWrite(ledTwo,HIGH);
    digitalWrite(ledOne, LOW);
  }
}

