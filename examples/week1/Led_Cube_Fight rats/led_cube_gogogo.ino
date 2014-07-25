/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:

int delay1=30;
int delay2=140;
int delay3=100;

int led[9]={2,3,4,7,8,10,9,5,6};

// led[0] = 2;
// led[1] = 3;
// led[2] = 6;
// led[3] = 9;
// led[4] = 10;
// led[5] = 1;
// led[6] = 8;
// led[7] = 9;
// led[8] = 10;
 

int layer1=11;
int layer2=12;
int layer3=13;

// the setup routine runs once when you press reset:
void setup() {               
 for(int i=0;i<=8;i++)
  {
    
    
     pinMode(led[i], OUTPUT); 
  } 
  // initialize the digital pin as an output.
 
  ; 
 
  pinMode(layer1, OUTPUT); 
  pinMode(layer2, OUTPUT); 
  pinMode(layer3, OUTPUT);  
  
 
}

// the loop routine runs over and over again forever:
void loop() {
 
 digitalWrite(layer1, HIGH);
   digitalWrite(layer2, HIGH);
    digitalWrite(layer3, HIGH);
    for(int i=0;i<=8;i++)
{
  digitalWrite(led[i], LOW); 
}

 for(int i=0;i<=3;i++)
{ for(int i=0;i<=8;i++)
{
    digitalWrite(layer1, LOW);
    digitalWrite(led[i], HIGH); 
    delay(delay1);               // wait for a second
     // 
    digitalWrite(led[i], LOW);    //  //   // turn the LED off by making the voltage LOW
   digitalWrite(layer1, HIGH);
    
     delay(delay1);
}


for(int i=0;i<=8;i++)
{
    digitalWrite(layer2, LOW);
    digitalWrite(led[i], HIGH); 
    delay(delay1);               // wait for a second
     // 
    digitalWrite(led[i], LOW);    //  //   // turn the LED off by making the voltage LOW
 digitalWrite(layer2, HIGH);
  delay(delay1);
}    

for(int i=0;i<=8;i++)
{
   digitalWrite(layer3, LOW);
    digitalWrite(led[i], HIGH); 
    delay(delay1);               // wait for a second
     
    digitalWrite(led[i], LOW);    //  //   // turn the LED off by making the voltage LOW
    digitalWrite(layer3, HIGH);
    delay(delay1);
}

}






for(int i=0;i<=3;i++)
  {
     digitalWrite(layer1, LOW);
     digitalWrite(layer2, HIGH);
     digitalWrite(layer3, HIGH);
     for(int i=0;i<=8;i++)
      {
         digitalWrite(led[i], HIGH); 
      }
      delay(delay2);               // wait for a second
   
     for(int i=0;i<=8;i++)
      {
         digitalWrite(led[i], LOW); 
      }
      
      digitalWrite(layer1, HIGH);
     digitalWrite(layer2, LOW);
     digitalWrite(layer3, HIGH);
     for(int i=0;i<=8;i++)
      {
         digitalWrite(led[i], HIGH); 
      }
      delay(delay2);               // wait for a second
     for(int i=0;i<=8;i++)
      {
         digitalWrite(led[i], LOW); 
      }
      
      digitalWrite(layer1, HIGH);
     digitalWrite(layer2, HIGH);
     digitalWrite(layer3, LOW);
     for(int i=0;i<=8;i++)
      {
         digitalWrite(led[i], HIGH); 
      }
      delay(delay2);               // wait for a second
     for(int i=0;i<=8;i++)
      {
         digitalWrite(led[i], LOW); 
      }
}


for(int i=0;i<=3;i++)
  { 
      for(int i=0;i<=8;i++)
      {
         digitalWrite(led[i], LOW); 
      }
       delay(delay2);
       digitalWrite(layer1, LOW);
     digitalWrite(layer2, LOW);
     digitalWrite(layer3, LOW);
     
     digitalWrite(led[0], HIGH);
    digitalWrite(led[1], HIGH);
     digitalWrite(led[2], HIGH); 
     
      delay(delay2);
      
     
      
       digitalWrite(led[3], HIGH);
    digitalWrite(led[7], HIGH);
     digitalWrite(led[8], HIGH); 
     
      delay(delay2);
      
      
        digitalWrite(led[6], HIGH);
    digitalWrite(led[4], HIGH);
     digitalWrite(led[5], HIGH); 
     
      delay(delay2);
    
  }


   for(int i=0;i<=3;i++)
   {
     for(int i=0;i<=8;i++)
      {
         digitalWrite(led[i], LOW); 
      }
       delay(delay3);

       digitalWrite(layer1,HIGH);
       digitalWrite(layer2, LOW);
       digitalWrite(layer3,HIGH);
       digitalWrite(led[8], HIGH);
       delay(delay3);
       digitalWrite(led[8], LOW);
       delay(delay3);
       digitalWrite(layer1,LOW);
       digitalWrite(layer2,HIGH);
       digitalWrite(layer3,LOW);
        digitalWrite(led[0], HIGH);
        digitalWrite(led[2], HIGH);
        digitalWrite(led[4], HIGH);
        digitalWrite(led[6], HIGH);
 delay(delay3);
       
        digitalWrite(led[0], LOW);
        digitalWrite(led[2], LOW);
        digitalWrite(led[4], LOW);
        digitalWrite(led[6], LOW);
        delay(delay3);
        
        
        digitalWrite(layer1,LOW);
       digitalWrite(layer2,HIGH);
       digitalWrite(layer3,LOW);
        digitalWrite(led[1], HIGH);
        digitalWrite(led[3], HIGH);
        digitalWrite(led[5], HIGH);
        digitalWrite(led[7], HIGH);
 delay(delay3);
       
        digitalWrite(led[1], LOW);
        digitalWrite(led[3], LOW);
        digitalWrite(led[5], LOW);
        digitalWrite(led[7], LOW);
        delay(delay3);
        
        digitalWrite(layer1,LOW);
       digitalWrite(layer2,LOW);
       digitalWrite(layer3,LOW);
        digitalWrite(led[1], HIGH);
        digitalWrite(led[3], HIGH);
        digitalWrite(led[5], HIGH);
        digitalWrite(led[7], HIGH);
        digitalWrite(led[0], HIGH);
        digitalWrite(led[2], HIGH);
        digitalWrite(led[4], HIGH);
        digitalWrite(led[6], HIGH);
        digitalWrite(led[8], HIGH);
        
 delay(delay3);
       
        digitalWrite(led[1], LOW);
        digitalWrite(led[3], LOW);
        digitalWrite(led[5], LOW);
        digitalWrite(led[7], LOW);
        digitalWrite(led[0], LOW);
        digitalWrite(led[2], LOW);
        digitalWrite(led[4], LOW);
        digitalWrite(led[6], LOW);
        digitalWrite(led[8], LOW);
        delay(delay3);
   }
   
//   
  
   
   



 for(int i=0;i<=3;i++)
   {
     
       for(int i=0;i<=8;i++)
      {
         digitalWrite(led[i], LOW); 
      }
       
   digitalWrite(layer1,LOW);
   digitalWrite(layer2,LOW);
   digitalWrite(layer3,LOW);
   delay(delay2);
    digitalWrite(led[0], HIGH);
     delay(delay2);
    
     
     digitalWrite(led[1], HIGH);
      digitalWrite(led[7], HIGH);
     delay(delay2);
     
      digitalWrite(led[2], HIGH);
      digitalWrite(led[8], HIGH);
       digitalWrite(led[6], HIGH);
     delay(delay2);
     
      digitalWrite(led[3], HIGH);
      digitalWrite(led[5], HIGH);
     delay(delay2);
     
     
      digitalWrite(led[4], HIGH);
     delay(delay2);
     
     
      digitalWrite(led[0], LOW);
     delay(delay2);
    
     
     digitalWrite(led[1], LOW);
      digitalWrite(led[7], LOW);
     delay(delay2);
     
      digitalWrite(led[2], LOW);
      digitalWrite(led[8], LOW);
       digitalWrite(led[6], LOW);
     delay(delay2);
     
      digitalWrite(led[3], LOW);
      digitalWrite(led[5], LOW);
     delay(delay2);
     
     
      digitalWrite(led[4], LOW);
     delay(delay2);
     
   
      }
      
      
      
      for(int i=0;i<=3;i++)
      {
         for(int i=0;i<=8;i++)
      {
         digitalWrite(led[i], HIGH); 
      }
       
         digitalWrite(layer1,LOW);
         digitalWrite(layer2,LOW);
         digitalWrite(layer3,LOW);
          
       for(int i=0;i<=7;i++)
       {
        digitalWrite(led[i], LOW);
        delay(delay2);
        digitalWrite(led[i], HIGH);
        
       }
     }
}
