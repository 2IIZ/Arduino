int pinMoteur=7;
void setup(){
    pinMode(pinMoteur,OUTPUT);
}
void loop(){
    digitalWrite(pinMoteur,HIGH); //le moteur se lance
    delay(1000);
    digitalWrite(pinMoteur,LOW); //le moteur s'arrête
    delay(1000);
}
