#include <Wire.h>
#include <Adafruit_MotorShield.h>

  Adafruit_MotorShield monShield = Adafruit_MotorShield();
  Adafruit_DCMotor *monMoteur = monShield.getMotor(1);
  Adafruit_DCMotor *monMoteur4 = monShield.getMotor(4);
  
void setup() {

monShield.begin();
monMoteur->setSpeed(250);
monMoteur4->setSpeed(250);
monMoteur->run(FORWARD);
monMoteur4->run(FORWARD);

}

void loop() {
  // put your main code here, to run repeatedly:

}
