#define LASERPIN 6
#define TRIGGERPIN 9
#define BITS 3
#define FREQUENCY_CLOCK 20
//#define FREQUENCY_CLOCK 50 // With Serial.print() // Debug Analog (LDR)


// simulate player one
//int bits[] = {0, 0, 1};

// simulate player Two
int bits[] = {0, 1, 0};

bool triggered = 0;

void setup() {
  pinMode(LASERPIN, OUTPUT);
  digitalWrite(LASERPIN, LOW);
  pinMode(TRIGGERPIN, INPUT);
  Serial.begin(9600);
}

void loop() {

  triggered = digitalRead(TRIGGERPIN);

  if(triggered){
    Serial.println("Player pressed the trigger");
    // Code inside when finally done
  }
  Serial.println(triggered);

  // TO PUT INSIDE THE IF 
  // First bit
  digitalWrite(LASERPIN, HIGH);
  delay(FREQUENCY_CLOCK);
  digitalWrite(LASERPIN, LOW);

  for(int i =0; i<BITS; i++) {
    digitalWrite(LASERPIN, bits[i]);
    delay(FREQUENCY_CLOCK);
  }
  //  ====================
  digitalWrite(LASERPIN, LOW);

//  delay(1000); // attendre 1 seconde. 1000ms = 1s
}
