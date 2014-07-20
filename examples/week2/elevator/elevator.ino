int p1 = 2;//orange
int p2 = 3;//yellow
int p3 = 4;//pink
int p4 = 5;//blue
int btn3 = 10;//floor2
int btn2 = 9;//floor1
int btn1 = 8;//ground
int now_position = 1;
int ground = 0;
int floor1 = 0;
int floor2 = 0;
int led1 = 7;
int led2 = 6;
int led3 = 12;
void setup(){
  pinMode(p1, OUTPUT);
  pinMode(p2, OUTPUT);
  pinMode(p3, OUTPUT);
  pinMode(p4, OUTPUT);
  pinMode(btn3,INPUT_PULLUP);
  pinMode(btn2,INPUT_PULLUP);
  pinMode(btn1,INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  Serial.begin(9600);
}
unsigned int t;
void loop(){ 
  //test();
  if(digitalRead(btn1) == LOW && now_position != 1){
    ground = 1;Serial.println("1");
    digitalWrite(led1, HIGH);
  }
  if(digitalRead(btn2) == LOW && now_position != 2){
    floor1 = 1;Serial.println("2");
    digitalWrite(led2, HIGH);
  }
  if(digitalRead(btn3) == LOW && now_position != 3){
    floor2 = 1;Serial.println("3");
    digitalWrite(led3, HIGH);
  }
  if(ground == 1){
    ground = 0;
    down(1);
    digitalWrite(led1, LOW);
  }
  else if(floor1 == 1){
    floor1 = 0;
    if(now_position > 2){
      down(2);
    }
    else{
      up(2);
    }
    digitalWrite(led2, LOW);
  }
  else if(floor2 == 1){
    floor2 = 0;
    up(3);
    digitalWrite(led3, LOW);
  }
}
void up(int n){
  Serial.println("what's wrong");
  int need_to_move = n - now_position;
  t = millis();
  Serial.println(need_to_move);
  Serial.print(t);Serial.print(", ");Serial.print(millis());
  while((millis() - t) < (4000 * need_to_move)){
    digitalWrite(p1, HIGH);
    digitalWrite(p2, LOW);
    digitalWrite(p3, LOW);
    digitalWrite(p4, LOW);
    delay(4);
    /*digitalWrite(p1, HIGH);
    digitalWrite(p2, HIGH);
    digitalWrite(p3, LOW);
    digitalWrite(p4, LOW);
    delay(2);*/
    digitalWrite(p1, LOW);
    digitalWrite(p2, HIGH);
    digitalWrite(p3, LOW);
    digitalWrite(p4, LOW);
    delay(4);
    /*digitalWrite(p1, LOW);
    digitalWrite(p2, HIGH);
    digitalWrite(p3, HIGH);
    digitalWrite(p4, LOW);
    delay(2);*/
    digitalWrite(p1, LOW);
    digitalWrite(p2, LOW);
    digitalWrite(p3, HIGH);
    digitalWrite(p4, LOW);
    delay(4);
    /*digitalWrite(p1, LOW);
    digitalWrite(p2, LOW);
    digitalWrite(p3, HIGH);
    digitalWrite(p4, HIGH);
    delay(2);*/
    digitalWrite(p1, LOW);
    digitalWrite(p2, LOW);
    digitalWrite(p3, LOW);
    digitalWrite(p4, HIGH);
    delay(4);
    /*digitalWrite(p1, HIGH);
    digitalWrite(p2, LOW);
    digitalWrite(p3, LOW);
    digitalWrite(p4, HIGH);
    delay(2);*/
  }
  now_position = n;
}
void down(int n){
  int need_to_move = now_position - n;
  t = millis();
  Serial.println("down what");
  Serial.println(need_to_move);
  Serial.print(t);Serial.print(", ");Serial.print(millis());
  while((millis() - t) < (4000 * need_to_move)){
    //Serial.println("cue");
    digitalWrite(p4, HIGH);
    digitalWrite(p3, LOW);
    digitalWrite(p2, LOW);
    digitalWrite(p1, LOW);
    delay(2);
    digitalWrite(p4, HIGH);
    digitalWrite(p3, HIGH);
    digitalWrite(p2, LOW);
    digitalWrite(p1, LOW);
    delay(2);
    digitalWrite(p4, LOW);
    digitalWrite(p3, HIGH);
    digitalWrite(p2, LOW);
    digitalWrite(p1, LOW);
    delay(2);
    digitalWrite(p4, LOW);
    digitalWrite(p3, HIGH);
    digitalWrite(p2, HIGH);
    digitalWrite(p1, LOW);
    delay(2);
    digitalWrite(p4, LOW);
    digitalWrite(p3, LOW);
    digitalWrite(p2, HIGH);
    digitalWrite(p1, LOW);
    delay(2);
    digitalWrite(p4, LOW);
    digitalWrite(p3, LOW);
    digitalWrite(p2, HIGH);
    digitalWrite(p1, HIGH);
    delay(2);
    digitalWrite(p4, LOW);
    digitalWrite(p3, LOW);
    digitalWrite(p2, LOW);
    digitalWrite(p1, HIGH);
    delay(2);
    digitalWrite(p4, HIGH);
    digitalWrite(p3, LOW);
    digitalWrite(p2, LOW);
    digitalWrite(p1, HIGH);
    delay(2);
  }
  now_position = n;
}
void test(){
  t = millis();
  //Serial.println(need_to_move);
  //Serial.print(t);Serial.print(", ");Serial.print(millis());
  for(int i=0 ; i<99 ; i++){
    if(i==98){
      for(int j=0 ; j<100000 ; j++){
        digitalWrite(p1, HIGH);
        digitalWrite(p2, LOW);
        digitalWrite(p3, LOW);
        digitalWrite(p4, LOW);
        delay(100-i);
        digitalWrite(p1, HIGH);
        digitalWrite(p2, HIGH);
        digitalWrite(p3, LOW);
        digitalWrite(p4, LOW);
        delay(100-i);
        digitalWrite(p1, LOW);
        digitalWrite(p2, HIGH);
        digitalWrite(p3, LOW);
        digitalWrite(p4, LOW);
        delay(100-i);
        digitalWrite(p1, LOW);
        digitalWrite(p2, HIGH);
        digitalWrite(p3, HIGH);
        digitalWrite(p4, LOW);
        delay(100-i);
        digitalWrite(p1, LOW);
        digitalWrite(p2, LOW);
        digitalWrite(p3, HIGH);
        digitalWrite(p4, LOW);
        delay(100-i);
        digitalWrite(p1, LOW);
        digitalWrite(p2, LOW);
        digitalWrite(p3, HIGH);
        digitalWrite(p4, HIGH);
        delay(100-i);
        digitalWrite(p1, LOW);
        digitalWrite(p2, LOW);
        digitalWrite(p3, LOW);
        digitalWrite(p4, HIGH);
        delay(100-i);
        digitalWrite(p1, HIGH);
        digitalWrite(p2, LOW);
        digitalWrite(p3, LOW);
        digitalWrite(p4, HIGH);
        delay(100-i);
      }
    }
    else{
      digitalWrite(p1, HIGH);
      digitalWrite(p2, LOW);
      digitalWrite(p3, LOW);
      digitalWrite(p4, LOW);
      delay(100-i);
      digitalWrite(p1, HIGH);
      digitalWrite(p2, HIGH);
      digitalWrite(p3, LOW);
      digitalWrite(p4, LOW);
      delay(100-i);
      digitalWrite(p1, LOW);
      digitalWrite(p2, HIGH);
      digitalWrite(p3, LOW);
      digitalWrite(p4, LOW);
      delay(100-i);
      digitalWrite(p1, LOW);
      digitalWrite(p2, HIGH);
      digitalWrite(p3, HIGH);
      digitalWrite(p4, LOW);
      delay(100-i);
      digitalWrite(p1, LOW);
      digitalWrite(p2, LOW);
      digitalWrite(p3, HIGH);
      digitalWrite(p4, LOW);
      delay(100-i);
      digitalWrite(p1, LOW);
      digitalWrite(p2, LOW);
      digitalWrite(p3, HIGH);
      digitalWrite(p4, HIGH);
      delay(100-i);
      digitalWrite(p1, LOW);
      digitalWrite(p2, LOW);
      digitalWrite(p3, LOW);
      digitalWrite(p4, HIGH);
      delay(100-i);
      digitalWrite(p1, HIGH);
      digitalWrite(p2, LOW);
      digitalWrite(p3, LOW);
      digitalWrite(p4, HIGH);
      delay(100-i);
    }
  }
}
