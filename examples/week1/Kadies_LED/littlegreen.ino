const int buttonPin = 2;
const int led1 =  13;
const int led2 =  12;
const int led3 =  11;
const int led4 =  10;
const int led5 =  9;
const int led6 =  8;

int buttonState = 0;

void setup() { 
  pinMode(buttonPin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
}
void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {   
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  } 
  else {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4,  LOW);
  digitalWrite(led5,  LOW);
  digitalWrite(led6,  LOW);
  delay(150);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3,  LOW);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led6,  LOW);
  delay(150);
  digitalWrite(led1, HIGH);
  digitalWrite(led2,  LOW);
  digitalWrite(led3,  LOW);
  digitalWrite(led4,  LOW);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  delay(150);
  }
}
