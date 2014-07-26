int motorPin1 = 8;
int motorPin2 = 9;
int motorPin3 = 10;
int motorPin4 = 11;
int delayTime = 1900;

int count = 0;
int dir = 0;

void setup() {
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  
  pinMode(2, INPUT);  
  pinMode(7, OUTPUT); 

  Serial.begin(9600);  
  gohome();
}

void gohome()
{
  for(int i=0;i<100;i++)
    {
      digitalWrite(7, HIGH);   // turn the LED on (HIGH is the voltage level)
      delayMicroseconds(500);  
      digitalWrite(7, LOW);    // turn the LED off by making the voltage LOW
      delay(20);               // wait for a second
    }
}

void loop() {
  
  int buttonState = digitalRead(2);
  Serial.println(buttonState);
  if(buttonState == 1)
  {
    go();
  }
  
  if(dir == 1)
  {
    Clockwise();
  }
  else
  {
    CounterClockwise();
  }
  
  if(++count > 1100)
  {
    count = 0;
    dir = (dir+1)%2;
  }
  
  if(dir == 0)  Serial.println(count);
  else Serial.println(1100-count);
}

void go()
{
    for(int i=0;i<180;i++)
    {
      digitalWrite(7, HIGH);   // turn the LED on (HIGH is the voltage level)
      delayMicroseconds(2400);  
      digitalWrite(7, LOW);    // turn the LED off by making the voltage LOW
      delay(20);               // wait for a second
    }
    
    for(int i=0;i<200;i++)
    {
      digitalWrite(7, HIGH);   // turn the LED on (HIGH is the voltage level)
      delayMicroseconds(500);  
      digitalWrite(7, LOW);    // turn the LED off by making the voltage LOW
      delay(20);               // wait for a second
    }
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



