int p1 = 2;//orange wire
int p2 = 3;//yellow wire
int p3 = 4;//pink wire
int p4 = 5;//blue wire
/*********************************/
int second_p1 = 9;//second motor orange wire
int second_p2 = 10;//second motor yellow wire
int second_p3 = 11;//second motor pink wire
int second_p4 = 12;//second motor blue wire
/*********************************/
int btn3 = 8;// 2F
int btn2 = 7;// 1F
int btn1 = 6;// ground
///////////////////////////////////
int now_position = 1;//first elevator stop layer
int now_position_second = 1;// second elevator stop layer
int ground = 0;// 2F flag
int floor1 = 0;// 1F flag
int floor2 = 0;// ground flag
//////////////////////////////
//int inside_1 = 12;
//int inside_2 = 13;
//int led1 = 7;
//int led2 = 6;
//int led3 = 11;
void setup(){
  pinMode(p1, OUTPUT);
  pinMode(p2, OUTPUT);
  pinMode(p3, OUTPUT);
  pinMode(p4, OUTPUT);
  pinMode(btn3,INPUT_PULLUP);
  pinMode(btn2,INPUT_PULLUP);
  pinMode(btn1,INPUT_PULLUP);
  pinMode(second_p1, OUTPUT);
  pinMode(second_p2, OUTPUT);
  pinMode(second_p3, OUTPUT);
  pinMode(second_p4, OUTPUT);
  Serial.begin(9600);
}
unsigned long int t;// time(millis)
void loop(){ 
  int ran_num = random(0, 2);
  //Serial.println(ran_num);
  if(digitalRead(btn1) == LOW && now_position != 1 && now_position_second != 1){
    ground = 1;Serial.println("go to 1");
    //digitalWrite(led1, HIGH);
  }
  if(digitalRead(btn2) == LOW && now_position != 2 && now_position_second != 2){
    floor1 = 1;Serial.println("go to 2");
    //digitalWrite(led2, HIGH);
  }
  if(digitalRead(btn3) == LOW && now_position != 3 && now_position_second != 3){
    floor2 = 1;Serial.println("go to 3");
    //digitalWrite(led3, HIGH);
  }
  if(ground == 1){
    ground = 0;
    int dif1 = abs(now_position - 1);
    int dif2 = abs(now_position_second -1);
    if(dif1 < dif2){
      down(1);
    }
    else if(dif1 == dif2){// random choose elevator
      int num_random = random(0, 2);
      if(num_random == 0)
        down(1);
      else
        down_second(1);
    }
    else{
      down_second(1);
    }
    //digitalWrite(led1, LOW);
  }
  else if(floor1 == 1){
    floor1 = 0;
    int dif1 = abs(now_position - 2);
    int dif2 = abs(now_position_second - 2);
    if(dif1 < dif2){
      if(now_position > 2){
        down(2);
      }
      else{
        up(2);
      }
    }
    else if(dif1 == dif2){// random choose elevator
      int num_random = random(0, 2);
      if(num_random == 0){
        if(now_position > 2)
          down(2);
        else
          up(2);
      }
      else{
        if(now_position_second > 2)
          down_second(2);
        else
          up_second(2);
      }
    }
    else{
      if(now_position_second > 2){
        down_second(2);
      }
      else{
        up_second(2);
      }
    }
    //digitalWrite(led2, LOW);
  }
  else if(floor2 == 1){
    floor2 = 0;
    int dif1 = abs(3 - now_position);
    int dif2 = abs(3 - now_position_second);
    if(dif1 < dif2){
      up(3);
    }
    else if(dif1 == dif2){// random choose elevator
      int num_random = random(0, 2);
      if(num_random == 0)
        up(3);
      else
        up_second(3);
    }
    else{
      up_second(3);
    }
    //digitalWrite(led3, LOW);
  }
}
void up(int n){
  Serial.println("First elevator is up");
  int need_to_move = n - now_position;
  t = millis();
  //Serial.println(need_to_move);
  Serial.print(t);Serial.print(", ");Serial.println(millis());
  while((millis() - t) < (10000 * need_to_move)){
    digitalWrite(p1, HIGH);
    digitalWrite(p2, LOW);
    digitalWrite(p3, LOW);
    digitalWrite(p4, LOW);
    delay(3);
    digitalWrite(p1, HIGH);
    digitalWrite(p2, HIGH);
    digitalWrite(p3, LOW);
    digitalWrite(p4, LOW);
    delay(3);
    digitalWrite(p1, LOW);
    digitalWrite(p2, HIGH);
    digitalWrite(p3, LOW);
    digitalWrite(p4, LOW);
    delay(3);
    digitalWrite(p1, LOW);
    digitalWrite(p2, HIGH);
    digitalWrite(p3, HIGH);
    digitalWrite(p4, LOW);
    delay(3);
    digitalWrite(p1, LOW);
    digitalWrite(p2, LOW);
    digitalWrite(p3, HIGH);
    digitalWrite(p4, LOW);
    delay(3);
    digitalWrite(p1, LOW);
    digitalWrite(p2, LOW);
    digitalWrite(p3, HIGH);
    digitalWrite(p4, HIGH);
    delay(3);
    digitalWrite(p1, LOW);
    digitalWrite(p2, LOW);
    digitalWrite(p3, LOW);
    digitalWrite(p4, HIGH);
    delay(3);
    digitalWrite(p1, HIGH);
    digitalWrite(p2, LOW);
    digitalWrite(p3, LOW);
    digitalWrite(p4, HIGH);
    delay(3);
  }
  now_position = n;
}
void down(int n){
  int need_to_move = now_position - n;
  t = millis();
  Serial.println("First elevator is down");
  //Serial.println(need_to_move);
  Serial.print(t);Serial.print(", ");Serial.println(millis());
  while((millis() - t) < (10000 * need_to_move)){
    //Serial.println("cue");
    digitalWrite(p4, HIGH);
    digitalWrite(p3, LOW);
    digitalWrite(p2, LOW);
    digitalWrite(p1, LOW);
    delay(3);
    digitalWrite(p4, HIGH);
    digitalWrite(p3, HIGH);
    digitalWrite(p2, LOW);
    digitalWrite(p1, LOW);
    delay(3);
    digitalWrite(p4, LOW);
    digitalWrite(p3, HIGH);
    digitalWrite(p2, LOW);
    digitalWrite(p1, LOW);
    delay(3);
    digitalWrite(p4, LOW);
    digitalWrite(p3, HIGH);
    digitalWrite(p2, HIGH);
    digitalWrite(p1, LOW);
    delay(3);
    digitalWrite(p4, LOW);
    digitalWrite(p3, LOW);
    digitalWrite(p2, HIGH);
    digitalWrite(p1, LOW);
    delay(3);
    digitalWrite(p4, LOW);
    digitalWrite(p3, LOW);
    digitalWrite(p2, HIGH);
    digitalWrite(p1, HIGH);
    delay(3);
    digitalWrite(p4, LOW);
    digitalWrite(p3, LOW);
    digitalWrite(p2, LOW);
    digitalWrite(p1, HIGH);
    delay(3);
    digitalWrite(p4, HIGH);
    digitalWrite(p3, LOW);
    digitalWrite(p2, LOW);
    digitalWrite(p1, HIGH);
    delay(3);
  }
  now_position = n;
}
void up_second(int n){
  Serial.println("Second elevator is up");
  int need_to_move = n - now_position_second;
  t = millis();
  //Serial.println(need_to_move);
  Serial.print(t);Serial.print(", ");Serial.println(millis());
  while((millis() - t) < (10000 * need_to_move)){
    digitalWrite(second_p1, HIGH);
    digitalWrite(second_p2, LOW);
    digitalWrite(second_p3, LOW);
    digitalWrite(second_p4, LOW);
    delay(3);
    digitalWrite(second_p1, HIGH);
    digitalWrite(second_p2, HIGH);
    digitalWrite(second_p3, LOW);
    digitalWrite(second_p4, LOW);
    delay(3);
    digitalWrite(second_p1, LOW);
    digitalWrite(second_p2, HIGH);
    digitalWrite(second_p3, LOW);
    digitalWrite(second_p4, LOW);
    delay(3);
    digitalWrite(second_p1, LOW);
    digitalWrite(second_p2, HIGH);
    digitalWrite(second_p3, HIGH);
    digitalWrite(second_p4, LOW);
    delay(3);
    digitalWrite(second_p1, LOW);
    digitalWrite(second_p2, LOW);
    digitalWrite(second_p3, HIGH);
    digitalWrite(second_p4, LOW);
    delay(3);
    digitalWrite(second_p1, LOW);
    digitalWrite(second_p2, LOW);
    digitalWrite(second_p3, HIGH);
    digitalWrite(second_p4, HIGH);
    delay(3);
    digitalWrite(second_p1, LOW);
    digitalWrite(second_p2, LOW);
    digitalWrite(second_p3, LOW);
    digitalWrite(second_p4, HIGH);
    delay(3);
    digitalWrite(second_p1, HIGH);
    digitalWrite(second_p2, LOW);
    digitalWrite(second_p3, LOW);
    digitalWrite(second_p4, HIGH);
    delay(3);
  }
  now_position_second = n;
}
void down_second(int n){
  int need_to_move = now_position_second - n;
  t = millis();
  Serial.println("Second elevator is down");
  //Serial.println(need_to_move);
  Serial.print(t);Serial.print(", ");Serial.println(millis());
  while((millis() - t) < (10000 * need_to_move)){
    //Serial.println("cue");
    digitalWrite(second_p4, HIGH);
    digitalWrite(second_p3, LOW);
    digitalWrite(second_p2, LOW);
    digitalWrite(second_p1, LOW);
    delay(3);
    digitalWrite(second_p4, HIGH);
    digitalWrite(second_p3, HIGH);
    digitalWrite(second_p2, LOW);
    digitalWrite(second_p1, LOW);
    delay(3);
    digitalWrite(second_p4, LOW);
    digitalWrite(second_p3, HIGH);
    digitalWrite(second_p2, LOW);
    digitalWrite(second_p1, LOW);
    delay(3);
    digitalWrite(second_p4, LOW);
    digitalWrite(second_p3, HIGH);
    digitalWrite(second_p2, HIGH);
    digitalWrite(second_p1, LOW);
    delay(3);
    digitalWrite(second_p4, LOW);
    digitalWrite(second_p3, LOW);
    digitalWrite(second_p2, HIGH);
    digitalWrite(second_p1, LOW);
    delay(3);
    digitalWrite(second_p4, LOW);
    digitalWrite(second_p3, LOW);
    digitalWrite(second_p2, HIGH);
    digitalWrite(second_p1, HIGH);
    delay(3);
    digitalWrite(second_p4, LOW);
    digitalWrite(second_p3, LOW);
    digitalWrite(second_p2, LOW);
    digitalWrite(second_p1, HIGH);
    delay(3);
    digitalWrite(second_p4, HIGH);
    digitalWrite(second_p3, LOW);
    digitalWrite(second_p2, LOW);
    digitalWrite(second_p1, HIGH);
    delay(3);
  }
  now_position_second = n;
}
