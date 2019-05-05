#include <SPI.h>
#include <SD.h>
File myFile;

void setup() {
  Serial.begin(9600); 

  Serial.println("Reading the sd card ...");
    if (!SD.begin(4)) //teste la communication avec la carte(pin 4)
    {
      Serial.println("Communication Impossible to the sd card");
      return;
    }
  Serial.println("Communication OK!");

  randomSeed(analogRead(A0));
  
  Serial.println("Openning File");
  
  File myFile = SD.open("rdm.iiz", FILE_WRITE);
  
    if (!myFile)
    {
      Serial.println("Error, Can't open the file");
      return;
    }
  Serial.println("File open");

    for(int n=0; n<10;n++)
    {
      int rNumber=random(0,1000);
      Serial.println("Writing number "+ String(rNumber));
      myFile.print(rNumber);
      myFile.close(); 
      Serial.println("File closed");
      }

}

  
void loop() {
  // put your main code here, to run repeatedly:

}
