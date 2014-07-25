/*  2014/07/18  Motor Project Auto Door*/
const int echopin=11; // echo接3端口
const int trigpin=12; // trig接2端口


int servo = 9;

int angle;
int pwm;
int perDegreeNeedTime = 11; // 300/180 約11  一度約需要11ms
boolean OpenDoor = 1; //false=close  true=open

void setup()
{
  Serial.begin(9600);  
   pinMode(servo, OUTPUT);
  pinMode(echopin,INPUT); //设定echo为输入模式
  pinMode(trigpin,OUTPUT);//设定trig为输出模式
  
}
void loop()
{
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW); //发一个10ms的高脉冲去触发TrigPin
  float distance = pulseIn(echopin,HIGH);//接收高电平时间
  distance = distance/58.0;//计算距离
  Serial.print(distance);  //输出距离
  Serial.println("cm");  //输出单位
  
  Serial.println(OpenDoor);  //输出距离
  //Serial.println("cm");  //输出单位
  if(distance<=14 )
  {
   // for (angle = 0; angle <= 90; angle += 5)  
    {
        angle =0;
        pwm = (angle*perDegreeNeedTime) + 500 ; //脈衝時間為 欲轉角度*每角度所需時間   0 degree need 500us  為了算impluse     
        digitalWrite(servo, HIGH);
        delayMicroseconds(pwm);
        digitalWrite(servo, LOW);    
        delay(150);  
      //  OpenDoor = 0;
    }
  }
  else if(distance>14 )
  {  
  //delay(3000);  
   //for (angle = 90; angle >= 0; angle -= 5)  
    {
        angle=90;
        pwm = (angle*perDegreeNeedTime) + 500 ; //脈衝時間為 欲轉角度*每角度所需時間   0 degree need 500us  為了算impluse     
        digitalWrite(servo, HIGH);
        delayMicroseconds(pwm);
        digitalWrite(servo, LOW);       
       delay(50);  
    }
//OpenDoor =1;
  }  
  
  delay(60);   //循环间隔60uS
//OpenDoor =1;
}
