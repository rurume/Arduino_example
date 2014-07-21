int clock1 = 2;
int latch1 = 3;
int data1 = 4; 
int clock2 = 5;
int latch2 = 6;
int data2 = 7; 
int clock3 = 8;
int latch3 = 9;
int data3 = 10; 
int count =0; 
int s=63;

void setup()
{
  pinMode(data1, OUTPUT);
  pinMode(clock1, OUTPUT);  
  pinMode(latch1, OUTPUT); 
   pinMode(data2, OUTPUT);
  pinMode(clock2, OUTPUT);  
  pinMode(latch2, OUTPUT); 
   pinMode(data3, OUTPUT);
  pinMode(clock3, OUTPUT);  
  pinMode(latch3, OUTPUT); 
  
}
void loop()
{

  int delayTime = 50;
  int d=100;

   updateLED1(1);
   updateLED2(0);
   updateLED3(0);  
   delay(delayTime);    
   updateLED1(0);
   updateLED2(1);
   updateLED3(0);  
   delay(delayTime);    
   updateLED1(0);
   updateLED2(0);
   updateLED3(1);  
   delay(delayTime); 
   updateLED1(0);
   updateLED2(0);
   updateLED3(32);  
   delay(delayTime);   
   updateLED1(0);
   updateLED2(0);
   updateLED3(16);  
   delay(delayTime); 
   updateLED1(0);
   updateLED2(0);
   updateLED3(8);  
   delay(delayTime);
   updateLED1(0);
   updateLED2(8);
   updateLED3(0);  
   delay(delayTime);
   updateLED1(8);
   updateLED2(0);
   updateLED3(0);  
   delay(delayTime);
   updateLED1(4);
   updateLED2(0);
   updateLED3(0);  
   delay(delayTime);
   updateLED1(2);
   updateLED2(0);
   updateLED3(0);  
   delay(delayTime);
   count=count+1;
 if (count==5){
   for ( int i=1 ; i<=10 ; i++){
   updateLED1(15);
   updateLED2(9);
   updateLED3(49);  
   delay(d);
   updateLED1(0);
   updateLED2(0);
   updateLED3(0);  
   delay(d);
 }
   count=0;
 }  

}

void updateLED1(int value){
  digitalWrite(latch1, LOW);
  shiftOut(data1, clock1, MSBFIRST, value); 
  digitalWrite(latch1, HIGH);
}

void updateLED2(int value){
  digitalWrite(latch2, LOW);
  shiftOut(data2, clock2, MSBFIRST, value); 
  digitalWrite(latch2, HIGH);
}

void updateLED3(int value){
  digitalWrite(latch3, LOW);
  shiftOut(data3, clock3, MSBFIRST, value); 
  digitalWrite(latch3, HIGH);
}
