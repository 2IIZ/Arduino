#include <Wire.h>
#include <Adafruit_MotorShield.h>

  Adafruit_MotorShield monShield = Adafruit_MotorShield();
  Adafruit_DCMotor *monMoteur = monShield.getMotor(1);
  
void setup() {

monShield.begin();
monMoteur->setSpeed(255);
monMoteur->run(FORWARD);

}

void loop() {
  // put your main code here, to run repeatedly:

}
