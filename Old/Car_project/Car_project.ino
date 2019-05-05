#include <Wire.h>
#include <Adafruit_MotorShield.h>

#define ECHOPIN 2                            // Pin to receive echo pulse
#define TRIGPIN 3                            // Pin to send trigger pulse


  Adafruit_MotorShield carMotors = Adafruit_MotorShield(); 
  Adafruit_DCMotor *front = carMotors.getMotor(4);
  Adafruit_DCMotor *rear = carMotors.getMotor(1); 
  int pinObjectDetect = 6;

void setup(){
  Serial.begin(9600);
  
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(pinObjectDetect, OUTPUT);
  
  carMotors.begin();
  front->setSpeed(255);
}

void loop(){ 

  int distance = echo();
  if(distance > 50)
  {
    front->run(RELEASE);
    rear->setSpeed(150);
    rear->run(FORWARD);
    digitalWrite(pinObjectDetect, LOW);
  }
  else if(distance < 45)
  {
 // rear->setSpeed(255); //freinage
 // rear->run(BACKWARD); //
 // delay(100);          //

    rear->setSpeed(150);
    rear->run(BACKWARD);
    front->run(BACKWARD);
    digitalWrite(pinObjectDetect, HIGH);
    delay(50);
    digitalWrite(pinObjectDetect, LOW);
    delay(50);
    digitalWrite(pinObjectDetect, HIGH);
    
    
  } 
}

int echo()
{
  digitalWrite(TRIGPIN, LOW);                   // Set the trigger pin to low for 2uS
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);                  // Send a 10uS high to trigger ranging
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);                   // Send pin low again
  int distance = pulseIn(ECHOPIN, HIGH);        // Read in times pulse
  distance= distance/58;                        // Calculate distance from time of pulse
  Serial.println(distance);                     
  delay(50);                                    // Wait 50mS before next ranging
  return distance;
}

