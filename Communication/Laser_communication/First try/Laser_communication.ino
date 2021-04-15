#define SOLARPIN A1
#define THRESHOLD 20
#define FREQUENCY_CLOCK 15

int ambientLight = 0;

void setup() {
  pinMode(SOLARPIN, INPUT);
  Serial.begin(9600);

  ambientLight = analogRead(SOLARPIN);
}

void loop() {
  int readingSolarPanel = analogRead(SOLARPIN);
  int bits [8];

  // listen to the start bit
  if(readingSolarPanel > ambientLight + THRESHOLD){
    Serial.println("Start bit found");
    for(int i = 0; i < 8; i++) {
      if(analogRead(SOLARPIN) > ambientLight + THRESHOLD){
        bits[i] = 1;
      }
      else {
        bits[i] = 0;
      }
      delay(FREQUENCY_CLOCK);
    }

    for (int i =0; i < 8; i++) {
      Serial.print(bits[i]);
    }
    Serial.println("");
  }
}
