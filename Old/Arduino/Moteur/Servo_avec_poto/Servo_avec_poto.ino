#include <Servo.h>
 
Servo monServo;  
 
const char AN_POTENTIOMETRE = 0;  
const char PWM_SERVO = 9;   

int positionDuServo = 0;
 
void setup()
{
  monServo.attach(9);  
}
 
void loop()
{
  positionDuServo = analogRead(AN_POTENTIOMETRE);           
  positionDuServo = map(positionDuServo, 0, 1023, 0, 180);     
  monServo.write(positionDuServo);              
  delay(15);                          
}
