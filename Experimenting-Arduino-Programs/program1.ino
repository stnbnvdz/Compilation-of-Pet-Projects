int led1Pin = 4;
int led2Pin = 5;
int led3Pin = 6;
int led4Pin = 7;
int led5Pin = 8;
int led6Pin = 9;
int led7Pin = 10;
int led8Pin = 11;
int butPin = 2;

void setup() {
  pinMode(butPin, INPUT);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  pinMode(led4Pin, OUTPUT);
  pinMode(led5Pin, OUTPUT);
  pinMode(led6Pin, OUTPUT);
  pinMode(led7Pin, OUTPUT);
  pinMode(led8Pin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  if(digitalRead(butPin)==HIGH){
      pat1();
      pat2();
      pat3();
      pat4();
      pat5();
      pat6();
      pat7();
      pat8();
      clearOut();
  }
  else{
    clearOut();
    Serial.println("unpressed");
  }

}
void pat1(){
  if(digitalRead(butPin)==HIGH){
    digitalWrite(led1Pin, HIGH);
    delay(75);
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, HIGH);
    delay(75);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, HIGH);
    delay(75);
    digitalWrite(led3Pin, LOW);
    digitalWrite(led4Pin, HIGH);
    delay(75);
    digitalWrite(led4Pin, LOW);
    digitalWrite(led5Pin, HIGH);
    delay(75);
    digitalWrite(led5Pin, LOW);
    digitalWrite(led6Pin, HIGH);
    delay(75);
    digitalWrite(led6Pin, LOW);
    digitalWrite(led7Pin, HIGH);
    delay(75);
    digitalWrite(led7Pin, LOW);
    digitalWrite(led8Pin, HIGH);
    delay(75);
  }
}
void pat2(){
  if(digitalRead(butPin)==HIGH){
    digitalWrite(led1Pin, HIGH);
    delay(75);
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, HIGH);
    delay(75);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, HIGH);
    delay(75);
    digitalWrite(led3Pin, LOW);
    digitalWrite(led4Pin, HIGH);
    delay(75);
    digitalWrite(led4Pin, LOW);
    digitalWrite(led5Pin, HIGH);
    delay(75);
    digitalWrite(led5Pin, LOW);
    digitalWrite(led6Pin, HIGH);
    delay(75);
    digitalWrite(led6Pin, LOW);
    digitalWrite(led7Pin, HIGH);
    delay(75);
  }
}
void pat3(){
  if(digitalRead(butPin)==HIGH){
    digitalWrite(led1Pin, HIGH);
    delay(75);
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, HIGH);
    delay(75);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, HIGH);
    delay(75);
    digitalWrite(led3Pin, LOW);
    digitalWrite(led4Pin, HIGH);
    delay(75);
    digitalWrite(led4Pin, LOW);
    digitalWrite(led5Pin, HIGH);
    delay(75);
    digitalWrite(led5Pin, LOW);
    digitalWrite(led6Pin, HIGH);
    delay(75); 
  }
}
void pat4(){
  if(digitalRead(butPin)==HIGH){
    digitalWrite(led1Pin, HIGH);
    delay(75);
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, HIGH);
    delay(75);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, HIGH);
    delay(75);
    digitalWrite(led3Pin, LOW);
    digitalWrite(led4Pin, HIGH);
    delay(75);
    digitalWrite(led4Pin, LOW);
    digitalWrite(led5Pin, HIGH);
    delay(75);
  }
}
void pat5(){
  if(digitalRead(butPin)==HIGH){
    digitalWrite(led1Pin, HIGH);
    delay(75);
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, HIGH);
    delay(75);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, HIGH);
    delay(75);
    digitalWrite(led3Pin, LOW);
    digitalWrite(led4Pin, HIGH);
    delay(75);
  }
}
void pat6(){
  if(digitalRead(butPin)==HIGH){
    digitalWrite(led1Pin, HIGH);
    delay(75);
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, HIGH);
    delay(75);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, HIGH);
    delay(75);
  }
}
void pat7(){
  if(digitalRead(butPin)==HIGH){
    digitalWrite(led1Pin, HIGH);
    delay(75);
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, HIGH);
    delay(75);
  }
}
void pat8(){
  if(digitalRead(butPin)==HIGH){
  digitalWrite(led1Pin, HIGH);
  delay(500);
  digitalWrite(led1Pin, LOW);
  delay(75);
  }
}
void clearOut(){
  digitalWrite(led1Pin, LOW);
  digitalWrite(led2Pin, LOW);
  digitalWrite(led3Pin, LOW);
  digitalWrite(led4Pin, LOW);
  digitalWrite(led5Pin, LOW);
  digitalWrite(led6Pin, LOW);
  digitalWrite(led7Pin, LOW);
  digitalWrite(led8Pin, LOW);
}
