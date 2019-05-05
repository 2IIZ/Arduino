  int button=8;
  int led[5]={2,3,4,5,6};


//_______________________________ fonction allumage des dé
 void showZero()
    {
      digitalWrite(led[0], LOW);
      digitalWrite(led[1], LOW);
      digitalWrite(led[2], LOW);
      digitalWrite(led[3], LOW);
      digitalWrite(led[4], LOW);
    }
    void showOne()
    {
      digitalWrite(led[0], LOW);
      digitalWrite(led[1], LOW);
      digitalWrite(led[2], HIGH);
      digitalWrite(led[3], LOW);
      digitalWrite(led[4], LOW);
    }
    void showTwo()
    {
      digitalWrite(led[0], HIGH);
      digitalWrite(led[1], LOW);
      digitalWrite(led[2], LOW);
      digitalWrite(led[3], LOW);
      digitalWrite(led[4], HIGH);
    }
    void showThree()
    {
      digitalWrite(led[0], LOW);
      digitalWrite(led[1], HIGH);
      digitalWrite(led[2], HIGH);
      digitalWrite(led[3], HIGH);
      digitalWrite(led[4], LOW);
    }
    void showFour()
    {
      digitalWrite(led[0], HIGH);
      digitalWrite(led[1], HIGH);
      digitalWrite(led[2], LOW);
      digitalWrite(led[3], HIGH);
      digitalWrite(led[4], HIGH);
    }
    void showFive(){
      digitalWrite(led[0], HIGH);
      digitalWrite(led[1], HIGH);
      digitalWrite(led[2], HIGH);
      digitalWrite(led[3], HIGH);
      digitalWrite(led[4], HIGH);
    }
//______________________________ End


void setup() { //___________________________________
  Serial.begin(9600);
  randomSeed(analogRead(0));
  
  
  delay(1000);

  pinMode(led[0], OUTPUT);
  pinMode(led[1], OUTPUT);
  pinMode(led[2], OUTPUT);
  pinMode(led[3], OUTPUT);
  pinMode(led[4], OUTPUT);
  pinMode(button, INPUT_PULLUP);
                    
} //_________________________________________________

void loop() {
  int randomNumb = random(6);
  bool buttonState=digitalRead(button);
  Serial.println(buttonState);

//________________________ appelle des fonction pour allumer leds
if(buttonState==LOW)
{
  int wait=100;
  for (int i=0; i<5; i++)
  {
    showOne();
    delay(wait);
    showTwo();
    delay(wait);
    showThree();
    delay(wait);
    showFour();
    delay(wait);
    showFive();
    delay(wait);
    wait +=100;
  }

  if(randomNumb == 0)
  {
    showZero();
    delay(1000);
  }
  else if(randomNumb == 1)
  {
    showOne();
    delay(1000);
  }
  else if (randomNumb ==2)
  {
    showTwo();
    delay(1000);
  }
  else if(randomNumb ==3)
  {
    showThree();
    delay(1000);
  }
  else if(randomNumb ==4)
  {
    showFour();
    delay(1000);
  }
  else if(randomNumb ==5)
  {
    showFive();
    delay(1000);
  }
}
//________________________End
   
   delay(10);




}
