int delay1=30;
int delay2=140;
int delay3=1000;

int led[9]={2,3,4,7,8,10,9,5,6};

int layer1=11;
int layer2=12;
int layer3=13;

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


void loop() 

{
  
  for(int i=0;i<=10000;i++)
  {
  digitalWrite(layer1, LOW);
   digitalWrite(layer2, HIGH);
    digitalWrite(layer3, HIGH);
    
     digitalWrite(led[1], HIGH);
     digitalWrite(led[1], LOW);
     
     digitalWrite(layer1, HIGH);
   digitalWrite(layer2, LOW);
    digitalWrite(layer3, HIGH);
    
     digitalWrite(led[3], HIGH);
     digitalWrite(led[3], LOW);
     
      digitalWrite(layer1, HIGH);
   digitalWrite(layer2, HIGH);
    digitalWrite(layer3, LOW);
    
     digitalWrite(led[5], HIGH);
     digitalWrite(led[5], LOW);
    
  }
  
//  
//   for(int i=0;i<=10000;i++)
//  {
//  digitalWrite(layer1, LOW);
//   digitalWrite(layer2, HIGH);
//    digitalWrite(layer3, HIGH);
//    
//     digitalWrite(led[2], HIGH);
//     digitalWrite(led[2], LOW);
//     
//     digitalWrite(layer1, HIGH);
//   digitalWrite(layer2, LOW);
//    digitalWrite(layer3, HIGH);
//    
//     digitalWrite(led[6], HIGH);
//     digitalWrite(led[6], LOW);
//     
//      digitalWrite(layer1, HIGH);
//   digitalWrite(layer2, HIGH);
//    digitalWrite(layer3, LOW);
//    
//     digitalWrite(led[7], HIGH);
//     digitalWrite(led[7], LOW);
//  }
//  
//  for(int i=0;i<=10000;i++)
//  {
//  digitalWrite(layer1, LOW);
//   digitalWrite(layer2, HIGH);
//    digitalWrite(layer3, HIGH);
//    
//     digitalWrite(led[8], HIGH);
//     digitalWrite(led[8], LOW);
//     
//     digitalWrite(layer1, HIGH);
//   digitalWrite(layer2, LOW);
//    digitalWrite(layer3, HIGH);
//    
//   digitalWrite(led[1], HIGH);
//     digitalWrite(led[1], LOW);
//     digitalWrite(led[3], HIGH);
//     digitalWrite(led[3], LOW);
//     digitalWrite(led[7], HIGH);
//     digitalWrite(led[7], LOW);
//     
//      digitalWrite(layer1, HIGH);
//   digitalWrite(layer2, HIGH);
//    digitalWrite(layer3, LOW);
//    
//     digitalWrite(led[8], HIGH);
//     digitalWrite(led[8], LOW);
//  }
//  
//  
//  
//  for(int i=0;i<=10000;i++)
//  {
//  digitalWrite(layer1, HIGH);
//   digitalWrite(layer2, HIGH);
//    digitalWrite(layer3, LOW);
//    
//     digitalWrite(led[2], HIGH);
//     digitalWrite(led[1], HIGH);
//     digitalWrite(led[2], LOW);
//     digitalWrite(led[1], LOW);
//     
//     digitalWrite(layer1, HIGH);
//   digitalWrite(layer2, LOW);
//    digitalWrite(layer3, HIGH);
//    
//     digitalWrite(led[1], HIGH);
//     digitalWrite(led[1], LOW);
//     
//     
//  }
}

