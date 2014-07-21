/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
 int dir = 0;
 int x = 2;
 int y = 1;
 int z = 1;

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
  digitalWrite(2, LOW);
  digitalWrite(9, HIGH);
  delay(20);
  
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(12, HIGH);
  delay(20);
  
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(13, HIGH);
  delay(20);
  /*
  int tmpX = x;
  int tmpY = y;
  int tmpZ = z;
  
  int newdir = random(0,8);
  
  if(newdir == 0)
  
  if(dir == 0)  x = (x + 3) % 3 - 1;
  else if(dir == 1)  x = (x + 2) % 3 - 1;
  else if(dir == 2)  y = (y + 3) % 3 - 1;
  else if(dir == 3)  y = (y + 2) % 3 - 1;
  else if(dir == 4)  z = (z + 3) % 3 - 1;
  else if(dir == 5)  z = (z + 2) % 3 - 1;
  
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
  
  delay(500);
  */
}
