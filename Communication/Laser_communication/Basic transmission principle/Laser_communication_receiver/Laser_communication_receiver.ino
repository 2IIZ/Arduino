#define SOLARPIN A0

#define NUM_SAMPLES 10
#define THRESHOLD 120
#define BITS 4
//#define FREQUENCY_CLOCK 20
#define FREQUENCY_CLOCK 50 // With Serial.print() // Debug

// Resistances used : 10K Omh for the ground and 100kk Ohm connected to the signal A0
// IF 1111 or 0000 ->  threshold may be too high or too low
// if a 0 is read as a 1
//    - Threshold to low, not enough ambient light 
//    - After a 1 bit, the photoresistor seems to take a little time for going down
// 120 seems a good threshold for the photoresistor of 0,5cm
// 
// testes speed : 
// 100ms ✔
// 80ms ✔
// 60ms ✔ 
// 50ms ✔ = 250ms for 4 bits
// 40ms ✔
// 30ms ✔ 
// 20ms ✔ without Serial.print() = 120ms for 4 bits
//
// Max ambientLight light should be 170 units
//  TODO : Make a led warning light
// ⚠No Direct LED Light at sensor. Error in transmission.
// Works at 213cm


int ambientLight = 0;
int averageLight;
int bits[BITS];
int readingA0;

void setup() {
  pinMode(SOLARPIN, INPUT);
  Serial.begin(9600);

  ambientLight = analogRead(SOLARPIN);
  Serial.print("Ambien Light : ");
  Serial.println(ambientLight);
  averageLight = ambientLight;
  
}

void loop() {
  readingA0 = analogRead(SOLARPIN);
 
  // listen to the start bit
  if(readingA0 > averageLight + THRESHOLD){
    Serial.println("Start bit found");
    delay(FREQUENCY_CLOCK);
    if(readingA0 > averageLight + THRESHOLD){
      for(int i = 0; i < BITS; i++) {
        readingA0 = analogRead(SOLARPIN);
        // Comment this for 20ms response
        Serial.print("AVERAGE : ");
        Serial.println(averageLight);
        Serial.print("readingA0 : ");
        Serial.println(readingA0);
        // ============================
        if(readingA0 > averageLight + THRESHOLD){
          bits[i] = 1;
          Serial.println("Bit 1 Received");
        }
        else {
          bits[i] = 0;
          Serial.println("Bit 0 received");

        }
        delay(FREQUENCY_CLOCK);
      }
    }

//    Serial.print("AVERAGE : ");
//    Serial.println(averageLight);
//    Serial.print("readingA0 : ");
//    Serial.println(readingA0);
  
    Serial.print("BITS RECEIVED : ");
    for (int i =0; i < BITS; i++) {
      Serial.print(bits[i]);
    }
    Serial.println("");
    
    if(bits[0] == 0 && bits[1] == 0 && bits[2] == 0 && bits[3] == 1){
      Serial.print("Player 1 hit the target");
    }
  }

  // Reseting bytes 
//  for (int i =0; i < BITS; i++) {
//    bits[i] = 0;
//  }


  averageLight = approxRollingAverage(averageLight, readingA0);
}


int approxRollingAverage(int avg, int new_sample) {

  avg -= avg / NUM_SAMPLES;
  avg += new_sample / NUM_SAMPLES;

  return avg;
}
