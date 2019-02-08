int pinHP = 11;
int sens = 1;
int note = 1000;
void setup() {
 pinMode(pinHP, OUTPUT);
}
void loop() {
 if (note > 2000 || note < 500) {
   sens *= -1;
 }
 note += sens;
 tone(pinHP, note);
}
