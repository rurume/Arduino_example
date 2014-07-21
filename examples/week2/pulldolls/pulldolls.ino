int motorPin1 = 8;
int motorPin2 = 9;
int motorPin3 = 10;
int motorPin4 = 11;
int delayTime = 2500;

int count = 0;
int dir = 0;

void setup() {
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  for(int i=0;i<160;i++)
    {
      digitalWrite(3, HIGH);   // turn the LED on (HIGH is the voltage level)
      delayMicroseconds(500);  
      digitalWrite(3, LOW);    // turn the LED off by making the voltage LOW
      delay(20);               // wait for a second
    }
  pinMode(2, INPUT);  
  pinMode(3, OUTPUT);     
}


void loop() {
  /*
  int buttonState = digitalRead(2);
  if (buttonState == HIGH) 
  {     
    for(int i=0;i<160;i++)
    {
      digitalWrite(3, HIGH);   // turn the LED on (HIGH is the voltage level)
      delayMicroseconds(2400);  
      digitalWrite(3, LOW);    // turn the LED off by making the voltage LOW
      delay(20);               // wait for a second
    }
    
    for(int i=0;i<160;i++)
    {
      digitalWrite(3, HIGH);   // turn the LED on (HIGH is the voltage level)
      delayMicroseconds(500);  
      digitalWrite(3, LOW);    // turn the LED off by making the voltage LOW
      delay(20);               // wait for a second
    }
  } 
  
  count++;
  if(dir == 0)
    CounterClockwise();
  else
    Clockwise();
   
   if(count > 1100)
   {
     count = 0;
     dir = (dir+1)%2;
   }
  */
}

void Clockwise()
{
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  //delay(delayTime);
  delayMicroseconds(delayTime);
  
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  //delay(delayTime);
  delayMicroseconds(delayTime);
  
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  //delay(delayTime);
  delayMicroseconds(delayTime);
  
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, HIGH);
  //delay(delayTime);
  delayMicroseconds(delayTime);
}

void CounterClockwise()
{
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  //delay(delayTime);
  delayMicroseconds(delayTime);
  
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, HIGH);
  //delay(delayTime);
  delayMicroseconds(delayTime);

  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  //delay(delayTime);
  delayMicroseconds(delayTime);
  
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  //delay(delayTime);
  delayMicroseconds(delayTime);
}


