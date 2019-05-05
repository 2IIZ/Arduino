  int button=8;
  int led[5]={2,3,4,5,6};
  boolean affichage[36][5]={1,0,0,0,0,
                            0,1,0,0,0,
                            0,0,1,0,0,
                            0,0,0,1,0,
                            0,0,0,0,1,
                            0,0,0,1,0,
                            0,0,1,0,0,
                            0,1,0,0,0,
                            1,0,0,0,0,
                            0,1,0,0,0, 
                            0,0,1,0,0, 
                            0,0,0,1,0, 
                            0,0,0,0,1, 
                            0,0,0,1,0,
                            0,0,1,0,0,
                            0,1,0,0,0,
                            0,0,0,0,0,  // _____________ Value 1º Led [16][0]
                            0,1,0,0,0,                              
                            0,0,1,0,0,
                            0,0,0,1,0,
                            0,0,0,0,1,
                            0,0,0,1,0,
                            0,0,1,0,0,
                            0,0,0,0,0, // _____________ Value 2º Led [22][1]
                            0,0,1,0,0,                             
                            0,0,0,1,0,
                            0,0,0,0,1,
                            0,0,0,1,0,
                            0,0,0,0,0, // _____________ Value 3º Led [28][2]
                            0,0,0,1,0,
                            0,0,0,0,1,
                            0,0,0,0,0, // _____________ Value 4º Led [30][3]
                            0,0,0,0,0}; // ____________Value 5º Led [31][4]



//_______________________________ fonction
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


void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  showOne();

  pinMode(led[0], OUTPUT);
  pinMode(led[1], OUTPUT);
  pinMode(led[2], OUTPUT);
  pinMode(led[3], OUTPUT);
  pinMode(led[4], OUTPUT);
  pinMode(button, INPUT_PULLUP);


  
}

void loop() { //________________________________________________________
  int randomNumb = random(6);
  bool buttonState=digitalRead(button);
  Serial.println(randomNumb);

//________________________ appelle des fonction pour allumer leds

if(buttonState==LOW)
{

  if(randomNumb == 0) //_____________________________________dice0
  {
    for(int i=16; i<33; i++)
    {
      affichage[i][0]=0;      //Led 1
    }
    for(int i=22; i<33; i++)
    {
      affichage[i][1]=0;      //LED 2
    }
    for(int i=28; i<33; i++)
    {
      affichage[i][2]=0;      //LED 3
    }
    for(int i=30; i<33; i++)
    {
      affichage[i][3]=0;      //LED 4
    }
    affichage[31][4]=0;       //LED 5
    delay(1000);
  }
  else if(randomNumb == 1) //___________________________________dice1
  {
    for(int i=16; i<33; i++)
    {
      affichage[i][0]=0;      //Led 1
    }
    for(int i=22; i<33; i++)
    {
      affichage[i][1]=0;      //LED 2
    }
    for(int i=28; i<33; i++)
    {
      affichage[i][2]=1;      //LED 3
    }
    for(int i=30; i<33; i++)
    {
      affichage[i][3]=0;      //LED 4
    }
    affichage[31][4]=0;       //LED 5
    delay(1000);
  }
  else if (randomNumb ==2) //_________________________________dice2
  {
    for(int i=16; i<33; i++)
    {
      affichage[i][0]=1;      //Led 1
    }
    for(int i=22; i<33; i++)
    {
      affichage[i][1]=0;      //LED 2
    }
    for(int i=28; i<33; i++)
    {
      affichage[i][2]=0;      //LED 3
    }
    for(int i=30; i<33; i++)
    {
      affichage[i][3]=0;      //LED 4
    }
    affichage[31][4]=1;       //LED 5
    delay(1000);
  }
  else if(randomNumb ==3) //_________________________________dice3
  {
    for(int i=16; i<33; i++)
    {
      affichage[i][0]=0;      //Led 1
    }
    for(int i=22; i<33; i++)
    {
      affichage[i][1]=1;      //LED 2
    }
    for(int i=28; i<33; i++)
    {
      affichage[i][2]=1;      //LED 3
    }
    for(int i=30; i<33; i++)
    {
      affichage[i][3]=1;      //LED 4
    }
    affichage[31][4]=0;       //LED 5
    delay(1000);
  }
  else if(randomNumb ==4) //________________________________dice4
  {
    for(int i=16; i<33; i++)
    {
      affichage[i][0]=1;      //Led 1
    }
    for(int i=22; i<33; i++)
    {
      affichage[i][1]=1;      //LED 2
    }
    for(int i=28; i<33; i++)
    {
      affichage[i][2]=0;      //LED 3
    }
    for(int i=30; i<33; i++)
    {
      affichage[i][3]=1;      //LED 4
    }
    affichage[31][4]=1;       //LED 5
    delay(1000);
  }
  else if(randomNumb ==5) //________________________________dice5
  {
   for(int i=16; i<33; i++)
    {
      affichage[i][0]=1;      //Led 1
    }
    for(int i=22; i<33; i++)
    {
      affichage[i][1]=1;      //LED 2
    }
    for(int i=28; i<33; i++)
    {
      affichage[i][2]=1;      //LED 3
    }
    for(int i=30; i<33; i++)
    {
      affichage[i][3]=1;      //LED 4
    }
    affichage[31][4]=1;       //LED 5
    delay(1000);
  }

    for (int i=0; i<33; i++)
  {
    int wait=200;
      for (int p=0; p<5; p++)
      { 
       digitalWrite(led[p],affichage[i][p]);
      }
    delay(wait);
  }
}
//________________________End
   
   delay(10);




}
