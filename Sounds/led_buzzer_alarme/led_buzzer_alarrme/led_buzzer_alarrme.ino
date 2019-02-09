char DIO_Buzzer = 7;

void setup() {
  // put your setup code here, to run once:

}

void loop() {

  for(int note=700;note<2000;note++){
  tone(DIO_Buzzer, note, 125);
  delay(1);
  }
  // put your main code here, to run repeatedly:
  for(int note=2000;note>=700;note--){
    tone(DIO_Buzzer, note, 125);
    delay(1);
  }
  
}
