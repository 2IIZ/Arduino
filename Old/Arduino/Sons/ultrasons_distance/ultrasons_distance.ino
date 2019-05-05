#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

const char DOUT_TRIGGER = 7;
const char DIN_ECHO = 6;
float distance;

void setup()
  {
    lcd.begin(16,2);
    pinMode(DOUT_TRIGGER, OUTPUT);
    pinMode(DIN_ECHO, INPUT);
  }
void loop()
  {
    digitalWrite(DOUT_TRIGGER, LOW);
    delayMicroseconds(2);
    digitalWrite(DOUT_TRIGGER, HIGH);
    delayMicroseconds(10);
    digitalWrite(DOUT_TRIGGER, LOW);
    
    distance= pulseIn(DIN_ECHO, HIGH) / 58.0;
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Distance");
    lcd.setCursor(0,1);
    lcd.print(distance);
    lcd.print(" cm");
    delay(1000);
  }
