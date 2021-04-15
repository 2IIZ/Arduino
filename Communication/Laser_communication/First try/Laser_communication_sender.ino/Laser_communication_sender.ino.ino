#define LASERPIN 2
#define FREQUENCY_CLOCK 15

void setup() {
  pinMode(LASERPIN, OUTPUT);

}

void loop() {
  // 1. 0101 1010 -> 1010 1101 
  // 2. 1000 0001 -> 10000000 + 11000000
  int bits[] = {HIGH, LOW, LOW, LOW, LOW, LOW, LOW, HIGH};

  digitalWrite(LASERPIN, HIGH);
  delay(FREQUENCY_CLOCK);
  digitalWrite(LASERPIN, LOW);

  for(int i =0; i<8; i++) {
    digitalWrite(LASERPIN, bits[i]);
    delay(FREQUENCY_CLOCK);
  }

  digitalWrite(LASERPIN, LOW);

  delay(1000);
}
