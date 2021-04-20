#define LASERPIN 6
#define BITS 4
//#define FREQUENCY_CLOCK 20
#define FREQUENCY_CLOCK 50 // With Serial.print() // Debug

// simulate player one
int bits[] = {1, 0, 1, 0};

void setup() {
  pinMode(LASERPIN, OUTPUT);
  digitalWrite(LASERPIN, LOW);
}

void loop() {

  // First bit
  digitalWrite(LASERPIN, HIGH);
  delay(FREQUENCY_CLOCK);
  digitalWrite(LASERPIN, LOW);

  for(int i =0; i<BITS; i++) {
    digitalWrite(LASERPIN, bits[i]);
    delay(FREQUENCY_CLOCK);
  }

  digitalWrite(LASERPIN, LOW);

  delay(3000); // attendre 1 seconde. 1000ms = 1s
}
