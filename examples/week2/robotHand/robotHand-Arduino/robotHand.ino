

void setup(){
     pinMode(3,OUTPUT);
     pinMode(4,OUTPUT);
     pinMode(5,OUTPUT);     
     pinMode(6,OUTPUT);          
     
     Serial.begin(9600);

}
char switchMotor;
int angel = 180;
void ServoMotor(int angel){
          if(angel == 180){
       for(int i=0;i<250;i++){
     digitalWrite(3,HIGH);
     digitalWrite(4,HIGH);     
     digitalWrite(5,HIGH);          
     digitalWrite(6,HIGH);          
     delayMicroseconds(2200);
     digitalWrite(3,LOW); 
     digitalWrite(4,LOW);     
     digitalWrite(6,LOW);            
     digitalWrite(5,LOW);     
     delayMicroseconds(17800);    
     
   
   }  
 
  }else if(angel == 135){
   for(int i=0;i<150;i++){
     digitalWrite(3,HIGH);
     delayMicroseconds(2200);
     digitalWrite(3,LOW);            
     delayMicroseconds(17800);    
   }
    
  }else if(angel == 90){
   for(int i=0;i<150;i++){
     digitalWrite(3,HIGH);
     delayMicroseconds(1700);
     digitalWrite(3,LOW);            
     delayMicroseconds(18300);    
   }
    
  }else if(angel == 45){
    for(int i=0;i<150;i++){
     digitalWrite(3,HIGH);
     delayMicroseconds(1200);
     digitalWrite(3,LOW);            
     delayMicroseconds(18800);    
     }    
    }else if(angel == 0){
    for(int i=0;i<250;i++){
   	 digitalWrite(3,HIGH);
     digitalWrite(4,HIGH);        
     digitalWrite(5,HIGH);          
     digitalWrite(6,HIGH);          

     delayMicroseconds(500);
     digitalWrite(6,LOW);            
     digitalWrite(5,LOW);            
          digitalWrite(4,LOW);     
     digitalWrite(3,LOW);            
     delayMicroseconds(19500);
    }
  }


    


}

void loop(){
   for(int i=0;i<250;i++){
     digitalWrite(4,HIGH);     
     digitalWrite(5,HIGH);          
     delayMicroseconds(2200);
     digitalWrite(4,LOW); 
     digitalWrite(5,LOW);            
     delayMicroseconds(17800);    
   }
   for(int i=0;i<250;i++){
     digitalWrite(3,HIGH);
     digitalWrite(4,HIGH);     
     digitalWrite(5,HIGH);          
     digitalWrite(6,HIGH);       
     delayMicroseconds(2200);
     digitalWrite(3,LOW);
     digitalWrite(4,LOW);     
     digitalWrite(5,LOW);               
     digitalWrite(6,LOW);            
     delayMicroseconds(17800);    
   }   
   
   
   
    for(int i=0;i<250;i++){
     digitalWrite(3,HIGH);
     digitalWrite(4,HIGH);        
     digitalWrite(5,HIGH);          
     digitalWrite(6,HIGH);          

     delayMicroseconds(500);
     digitalWrite(6,LOW);            
     digitalWrite(5,LOW);            
     digitalWrite(4,LOW);     
     digitalWrite(3,LOW);            
     delayMicroseconds(19500);   
    }
    
//    
//    ServoMotor(180);
//    ServoMotor(0);
//    ServoMotor(180);
//    ServoMotor(0);    
//    ServoMotor(180);
//    ServoMotor(0);    
//    ServoMotor(180);    
//    ServoMotor(0);    
}
