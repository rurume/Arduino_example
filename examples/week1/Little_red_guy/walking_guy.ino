int r1_gnd = 4;
int r2_gnd = 5;
int r3_gnd = 6;
int r4_gnd = 7;
int c1 = 13;
int c2 = 12;
int c3 = 11;
int c4 = 10;
int c5 = 9;
int c6 = 8;
int button = 2;
void setup(){
  pinMode(button, INPUT);
  pinMode(r1_gnd, OUTPUT);
  pinMode(r2_gnd, OUTPUT);
  pinMode(r3_gnd, OUTPUT);
  pinMode(r4_gnd, OUTPUT);
  pinMode(c1, OUTPUT);
  pinMode(c2, OUTPUT);
  pinMode(c3, OUTPUT);
  pinMode(c4, OUTPUT);
  pinMode(c5, OUTPUT);
  pinMode(c6, OUTPUT);
  Serial.begin(9600);
}
int start_time = millis();
void loop(){
  int state = digitalRead(button);
  if(state == LOW){
    if((millis()-start_time) / 500 % 7 == 0){
      step1();
    }
    else if((millis()-start_time) / 500 % 7 == 1){
      step2();
    }
    else if((millis()-start_time) / 500 % 7 == 2){
      step3();
    }
    else if((millis()-start_time) / 500 % 7 == 3){
      step4();
    }
    else if((millis()-start_time) / 500 % 7 == 4){
      step5();
    }
    else if((millis()-start_time) / 500 % 7 == 5){
      step6();
    }
    else if((millis()-start_time) / 500 % 7 == 6){
      step7();
    }
  }
  else{
    if((millis()-start_time) / 500 % 7 == 0){
      step7();
    }
    else if((millis()-start_time) / 500 % 7 == 1){
      step6();
    }
    else if((millis()-start_time) / 500 % 7 == 2){
      step5();
    }
    else if((millis()-start_time) / 500 % 7 == 3){
      step4();
    }
    else if((millis()-start_time) / 500 % 7 == 4){
      step3();
    }
    else if((millis()-start_time) / 500 % 7 == 5){
      step2();
    }
    else if((millis()-start_time) / 500 % 7 == 6){
      step1();
    }
  }
}

void step1(){
  digitalWrite(c6, LOW);
  digitalWrite(c5, LOW);
  digitalWrite(c4, LOW);
  digitalWrite(c3, LOW);
  digitalWrite(c2, LOW);
  digitalWrite(r1_gnd, LOW);
  digitalWrite(r2_gnd, LOW);
  digitalWrite(r3_gnd, LOW);
  digitalWrite(r4_gnd, HIGH);
  digitalWrite(c1, HIGH);
  ///////////////////////////
  delay(10);
  digitalWrite(c1, LOW);
  digitalWrite(r1_gnd, HIGH);
  digitalWrite(r2_gnd, HIGH);
  digitalWrite(r4_gnd, LOW);
  digitalWrite(c2, HIGH);
  delay(10);
}

void step2(){
  digitalWrite(r1_gnd, LOW);
  digitalWrite(r2_gnd, LOW);
  digitalWrite(r3_gnd, LOW);
  digitalWrite(r4_gnd, LOW);
  digitalWrite(c2, HIGH);
  digitalWrite(c1, LOW);
  digitalWrite(c3, LOW);
  digitalWrite(c4, LOW);
  digitalWrite(c5, LOW);
  digitalWrite(c6, LOW);
}

void step3(){
  digitalWrite(c1, LOW);
  digitalWrite(c2, HIGH);
  digitalWrite(c3, LOW);
  digitalWrite(c4, LOW);
  digitalWrite(c5, LOW);
  digitalWrite(c6, LOW);
  digitalWrite(r1_gnd, HIGH);
  digitalWrite(r2_gnd, HIGH);
  digitalWrite(r3_gnd, LOW);
  digitalWrite(r4_gnd, LOW);
  delay(5);
  digitalWrite(r4_gnd, HIGH);
  digitalWrite(r1_gnd, LOW);
  digitalWrite(r2_gnd, LOW);
  digitalWrite(c2, LOW);
  digitalWrite(c3, HIGH);
  delay(5);
  digitalWrite(r4_gnd, LOW);
  digitalWrite(r1_gnd, HIGH);
  digitalWrite(r2_gnd, HIGH);
  digitalWrite(c3, LOW);
  digitalWrite(c4, HIGH);
  delay(5);
}

void step4(){
  digitalWrite(c1, LOW);
  digitalWrite(c2, LOW);
  digitalWrite(c3, LOW);
  digitalWrite(c4, HIGH);
  digitalWrite(c5, LOW);
  digitalWrite(c6, LOW);
  digitalWrite(r1_gnd, LOW);
  digitalWrite(r2_gnd, LOW);
  digitalWrite(r3_gnd, LOW);
  digitalWrite(r4_gnd, LOW);
}

void step5(){
  digitalWrite(r1_gnd, HIGH);
  digitalWrite(r2_gnd, HIGH);
  digitalWrite(r3_gnd, LOW);
  digitalWrite(r4_gnd, LOW);
  digitalWrite(c1, LOW);
  digitalWrite(c2, LOW);
  digitalWrite(c3, LOW);
  digitalWrite(c4, HIGH);
  digitalWrite(c5, LOW);
  digitalWrite(c6, LOW);
  delay(5);
  digitalWrite(r1_gnd, LOW);
  digitalWrite(r2_gnd, LOW);
  digitalWrite(r4_gnd, HIGH);
  digitalWrite(c4, LOW);
  digitalWrite(c5, HIGH);
  delay(5);
  digitalWrite(r1_gnd, HIGH);
  digitalWrite(r2_gnd, HIGH);
  digitalWrite(r4_gnd, LOW);
  digitalWrite(c5, LOW);
  digitalWrite(c6, HIGH);
  delay(5);
}
void step6(){
  digitalWrite(c1, LOW);
  digitalWrite(c2, LOW);
  digitalWrite(c3, LOW);
  digitalWrite(c4, LOW);
  digitalWrite(c5, LOW);
  digitalWrite(c6, HIGH);
  digitalWrite(r1_gnd, LOW);
  digitalWrite(r2_gnd, LOW);
  digitalWrite(r3_gnd, LOW);
  digitalWrite(r4_gnd, LOW);
}
void step7(){
  digitalWrite(c1, LOW);
  digitalWrite(c2, LOW);
  digitalWrite(c3, LOW);
  digitalWrite(c4, LOW);
  digitalWrite(c5, LOW);
  digitalWrite(c6, HIGH);
  digitalWrite(r1_gnd, HIGH);
  digitalWrite(r2_gnd, HIGH);
  digitalWrite(r3_gnd, LOW);
  digitalWrite(r4_gnd, LOW);
}
