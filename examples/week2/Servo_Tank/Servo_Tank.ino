 int servoPin1 = 5;
  int servoPin2 = 6;
int TimePre , TimeNow;
int countD=20;
int zero=1380;
int a120=2033;
int a90=1650;
int a60=1267;
int full=2100;
int count=0;
int TimeInterval=1000;
int scale=100;
int duration=20000;
int x;
int timepre , timenow , angle;
void setup(){
  pinMode(servoPin1 ,OUTPUT);
  pinMode(servoPin2 ,OUTPUT);
  Serial.begin(9600);
  /*while(1){
    if (Serial.available() > 0){
      break;
    }
  }*/
  
  TimePre=millis();
  timepre=micros();
  
}

void loop(){


          digitalWrite(servoPin1 , HIGH);
          digitalWrite(servoPin2 , HIGH);
          delayMicroseconds(1350);
          digitalWrite(servoPin2 , LOW);
          delayMicroseconds(300);
          digitalWrite(servoPin1 , LOW);
          
          x=duration-1350-300;
          delayMicroseconds(x);
             
      
      
     // delay(1000);
      // 180
     /* while (1){
        timenow=millis();  
        if (timenow-timepre >=TimeInterval){
          timepre=millis();
          break;
        }
        else{
          digitalWrite(servoPin , HIGH);
          delayMicroseconds(full);
          digitalWrite(servoPin , LOW);
          x=duration-full;
          delayMicroseconds(x);
        }         
      }*/
      
 }
  







