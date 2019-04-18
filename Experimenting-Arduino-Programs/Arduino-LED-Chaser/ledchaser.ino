const int analogPin = A0;  
const int ledCount = 10;   

int ledPins[] = {
  2,3,4,5,6,7,8,9,10,11
};

void setup() {
 
for (int thisLed = 0;thisLed < ledCount;thisLed++) { //for loop (initialization, condition, iteration)

  pinMode(ledPins[thisLed],OUTPUT); 
 }
}

void loop() {
int sensorReading = analogRead(analogPin); 

int ledLevel =map(sensorReading,0,1023,0,ledCount); // Scale down the potentiometer reading ( 0 ~ 1023 ) to a valid Pulse Width Modulation value

for (int thisLed = 0;thisLed <ledCount;thisLed++){ //for loop (initialization, condition, iteration)

  if (thisLed < ledLevel) { 
    digitalWrite(ledPins[thisLed],HIGH);
  }
  else {
    digitalWrite(ledPins[thisLed],LOW);
  }
 }
}
