/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
 int dir = 0;
 int x = 2;
 int y = 1;
 int z = 1;
 
int buttonState1 = 0; 
int buttonState2 = 0; 
int buttonState3 = 0; 
int buttonState4 = 0; 

int ifactive = 0;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(2, OUTPUT); 
  pinMode(3, OUTPUT); 
  pinMode(4, OUTPUT); 
  pinMode(5, OUTPUT); 
  pinMode(6, OUTPUT); 
  pinMode(7, OUTPUT); 
  pinMode(8, OUTPUT); 
  pinMode(9, OUTPUT); 
  pinMode(10, OUTPUT); 
  pinMode(11, OUTPUT); 
  pinMode(12, OUTPUT); 
  pinMode(13, OUTPUT);
  
  Serial.begin(9600);
}

void clearAll()
{
  for(int i=2;i<5;i++)
    digitalWrite(i, HIGH);
    
   for(int i=5;i<14;i++)
    digitalWrite(i, LOW);
}


// the loop routine runs over and over again forever:
void loop() 
{
  int tmpX = x;
  int tmpY = y;
  int tmpZ = z;
  
  int active1 = 0;
  int active2 = 0;
  int active3 = 0;
  int active4 = 0;
  
  for(int i=0;i<1000;i++)
  {
    buttonState1 = analogRead(0);
    buttonState2 = analogRead(1);
    buttonState3 = analogRead(2);
    buttonState4 = analogRead(3);
    
    if(ifactive == 0)
    {
      if(buttonState1 > 800) {
        active1 = 1;
        ifactive = 1;
      } else if(buttonState2 > 800) {
        active2 = 1;
        ifactive = 1;
      } else if(buttonState3 > 800) {
        active3 = 1;
        ifactive = 1;
      } else if(buttonState4 > 800) {
        active4 = 1;
        ifactive = 1;
      }
    }
    
    delayMicroseconds(50);
  }
  
  if(ifactive > 0)  ifactive--;

  if(x != -1 && y != -1 && z != -1)
  {
    if(dir == 0)
    {
      if(active1 == 1) dir = 4;
      else if(active2 == 1) dir = 5;
      else if(active3 == 1) dir = 2;
      else if(active4 == 1) dir = 3;
    }
    else if(dir == 1)
    {
      if(active1 == 1) dir = 5;
      else if(active2 == 1) dir = 4;
      else if(active3 == 1) dir = 3;
      else if(active4 == 1) dir = 2;
    }
    else if(dir == 2)
    {
      if(active1 == 1) dir = 4;
      else if(active2 == 1) dir = 5;
      else if(active3 == 1) dir = 1;
      else if(active4 == 1) dir = 0;
    }
    else if(dir == 3)
    {
      if(active1 == 1) dir = 5;
      else if(active2 == 1) dir = 4;
      else if(active3 == 1) dir = 0;
      else if(active4 == 1) dir = 1;
    }
    else if(dir == 4)
    {
      if(active1 == 1) dir = 1;
      else if(active2 == 1) dir = 0;
      else if(active3 == 1) dir = 2;
      else if(active4 == 1) dir = 3;
    }
    else if(dir == 5)
    {
      if(active1 == 1) dir = 0;
      else if(active2 == 1) dir = 1;
      else if(active3 == 1) dir = 3;
      else if(active4 == 1) dir = 2;
    }
  }
  
  if(dir == 0)  x = (x + 2) % 4 - 1;
  else if(dir == 1)  x = (x + 4) % 4 - 1;
  else if(dir == 2)  y = (y + 2) % 4 - 1;
  else if(dir == 3)  y = (y + 4) % 4 - 1;
  else if(dir == 4)  z = (z + 2) % 4 - 1;
  else if(dir == 5)  z = (z + 4) % 4 - 1;
  
  clearAll();
  
  if(dir == 4 || dir == 5)
  {
    if(x != -1 && y != -1 && x != 3 && y != 3)  digitalWrite((x+y*3)+5, HIGH);
    if(z != -1 && z != 3)  digitalWrite(z+2, LOW);
    if(tmpZ != -1 && tmpZ != 3)  digitalWrite(tmpZ+2, LOW);
  }
  else
  {
    if(x != -1 && y != -1 && x != 3 && y != 3)  digitalWrite((x+y*3)+5, HIGH);
    if(tmpX != -1 && tmpY != -1 && tmpX != 3 && tmpY != 3)  digitalWrite((tmpX+tmpY*3)+5, HIGH);
    if(z != -1 && z != 3)  digitalWrite(z+2, LOW);
  }

}
