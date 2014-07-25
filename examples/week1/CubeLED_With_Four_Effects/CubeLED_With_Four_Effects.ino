/*  2014/07/13  3*3 Cube LED  */
 
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:

int delay1=30;
int delay2=140;
int delay3=100;

int led[9]={2,3,4,5,6,7,8,9,10};

// led[0] = 2;
// led[1] = 3;
// led[2] = 4;
// led[3] = 5;
// led[4] = 6;
// led[5] = 7;
// led[6] = 8;
// led[7] = 9;
// led[8] = 10;
 

int LayerBottom = 11;
int LayerMiddle = 12;
int LayerTop = 13;

// the setup routine runs once when you press reset:
void setup() 
{               
 for(int i=0;i<=8;i++)
  {   
     pinMode(led[i], OUTPUT); 
  } 
  // initialize the digital pin as an output. 
 
  pinMode(LayerBottom, OUTPUT); 
  pinMode(LayerMiddle, OUTPUT); 
  pinMode(LayerTop, OUTPUT);  
  
 
}

// the loop routine runs over and over again forever:
void loop() 
{
 //如果要該層亮起來的話要讓他是low
 digitalWrite(LayerBottom, HIGH);
 digitalWrite(LayerMiddle, HIGH);
 digitalWrite(LayerTop, HIGH);
//效果一 ：一顆一顆亮
  for(int i=11;i<=13;i++)
  {
    if(i==11)//最底層亮
    {
        digitalWrite(i, LOW); 
        digitalWrite(i+1, HIGH); 
        digitalWrite(i+2, HIGH);
           
        digitalWrite(led[0], HIGH); 
        delay(100);
        digitalWrite(led[0], LOW);
        digitalWrite(led[1], HIGH); 
        delay(100);
        digitalWrite(led[1], LOW);
        digitalWrite(led[2], HIGH); 
        delay(100);
        digitalWrite(led[2], LOW);
        digitalWrite(led[5], HIGH); 
        delay(100);
        digitalWrite(led[5], LOW);
        digitalWrite(led[8], HIGH); 
        delay(100);
        digitalWrite(led[8], LOW);
        digitalWrite(led[7], HIGH); 
        delay(100);
        digitalWrite(led[7], LOW);
        digitalWrite(led[6], HIGH); 
        delay(100);
        digitalWrite(led[6], LOW);
        digitalWrite(led[3], HIGH); 
        delay(100);
        digitalWrite(led[3], LOW);
        digitalWrite(led[4], HIGH); 
        delay(100);
        digitalWrite(led[4], LOW);      
    }
    else if(i==12)//中間層亮
    {
        digitalWrite(i, LOW); 
        digitalWrite(i-1, HIGH); 
        digitalWrite(i+1, HIGH);
           
        digitalWrite(led[4], HIGH); 
        delay(100);
        digitalWrite(led[4], LOW);
        digitalWrite(led[3], HIGH); 
        delay(100);
        digitalWrite(led[3], LOW);
        digitalWrite(led[6], HIGH); 
        delay(100);
        digitalWrite(led[6], LOW);
        digitalWrite(led[7], HIGH); 
        delay(100);
        digitalWrite(led[7], LOW);
        digitalWrite(led[8], HIGH); 
        delay(100);
        digitalWrite(led[8], LOW);
        digitalWrite(led[5], HIGH); 
        delay(100);
        digitalWrite(led[5], LOW);
        digitalWrite(led[2], HIGH); 
        delay(100);
        digitalWrite(led[2], LOW);
        digitalWrite(led[1], HIGH); 
        delay(100);
        digitalWrite(led[1], LOW);
        digitalWrite(led[0], HIGH); 
        delay(100);
        digitalWrite(led[0], LOW);      
    }
    else//最上層亮
    {
        digitalWrite(i, LOW); 
        digitalWrite(i-1, HIGH); 
        digitalWrite(i-2, HIGH);
           
        digitalWrite(led[0], HIGH); 
        delay(100);
        digitalWrite(led[0], LOW);
        digitalWrite(led[1], HIGH); 
        delay(100);
        digitalWrite(led[1], LOW);
        digitalWrite(led[2], HIGH); 
        delay(100);
        digitalWrite(led[2], LOW);
        digitalWrite(led[5], HIGH); 
        delay(100);
        digitalWrite(led[5], LOW);
        digitalWrite(led[8], HIGH); 
        delay(100);
        digitalWrite(led[8], LOW);
        digitalWrite(led[7], HIGH); 
        delay(100);
        digitalWrite(led[7], LOW);
        digitalWrite(led[6], HIGH); 
        delay(100);
        digitalWrite(led[6], LOW);
        digitalWrite(led[3], HIGH); 
        delay(100);
        digitalWrite(led[3], LOW);
        digitalWrite(led[4], HIGH); 
        delay(100);
        digitalWrite(led[4], LOW);      
    }
     
    
  }//end for
     digitalWrite(LayerBottom, LOW);
     digitalWrite(LayerMiddle, LOW);
     digitalWrite(LayerTop, LOW);
     for(int i=1;i<=5;i++)
     {
         digitalWrite(led[4], HIGH); 
         delay(100);
         digitalWrite(led[4], LOW); 
         delay(100);
     }
//效果二 ：一排一排亮越亮越快
     int timer[25] = {800,600,400,400,300,300,200,200,150,150,100,100,100,100,100,70,70,70,50,50,50,50,50,50,50};
     for(int q=0;q<25;q++)
     {
       for(int j=11;j<=13;j++)
       {
         digitalWrite(LayerBottom, HIGH);
         digitalWrite(LayerMiddle,HIGH);
         digitalWrite(LayerTop, HIGH);
         digitalWrite(j, LOW);
         digitalWrite(led[0], HIGH); 
         digitalWrite(led[1], HIGH); 
         digitalWrite(led[2], HIGH); 
         digitalWrite(led[3], HIGH); 
         digitalWrite(led[4], HIGH); 
         digitalWrite(led[5], HIGH); 
         digitalWrite(led[6], HIGH); 
         digitalWrite(led[7], HIGH); 
         digitalWrite(led[8], HIGH); 
         delay(timer[q]);                
       }       
    }
    
    //效果三 ：炫耀藍色ＬＥＤ燈
    
    
       for(int j=1;j<=50;j++)
       {
         digitalWrite(LayerBottom,LOW);
         digitalWrite(LayerMiddle,LOW);
         digitalWrite(LayerTop, LOW);  
         digitalWrite(led[4], HIGH);       
         delay(100);    
         digitalWrite(led[4], LOW);        
         delay(100);            
       }    
    
    //效果四 ：聖誕樹
    
    
       for(int j=1;j<=50;j++)
       {
      
         digitalWrite(LayerBottom,HIGH);
         digitalWrite(LayerMiddle,HIGH);
         digitalWrite(LayerTop, HIGH);  
         digitalWrite(random(11,14), LOW); //LAYER
         int randomLED = random(2,10);
         digitalWrite(randomLED, HIGH);       
         delay(500);   
        digitalWrite(randomLED, LOW);       
         delay(500);   
         
      
       }       
    
}//end loop


