#define DEMODULATOR 7

#define NUM_SAMPLES 10
#define BITS 4
//#define FREQUENCY_CLOCK 20
#define FREQUENCY_CLOCK 50 // With Serial.print() // Debug

// 5ms ✔

int bits[BITS];

void setup() {
  // put your setup code here, to run once:
  pinMode(DEMODULATOR, INPUT);
  Serial.begin(9600);
}

void loop() {
  int readingFromDemodulator = digitalRead(DEMODULATOR);

  // listen to the start bit
  if(readingFromDemodulator == HIGH){
    Serial.println("Start bit found");
    delay(FREQUENCY_CLOCK);
    for(int i = 0; i < BITS; i++) {
      readingFromDemodulator = digitalRead(DEMODULATOR);
      // ============================
      if(readingFromDemodulator == HIGH)
      {
        bits[i] = 1;
        Serial.println("Bit 1 Received");
      }else{
        bits[i] = 0;
        Serial.println("Bit 0 received");
      }
      delay(FREQUENCY_CLOCK);
    }
  }
}
