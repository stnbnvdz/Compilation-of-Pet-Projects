const int buttonPin = 0;
const int redPin = 6;
const int greenPin = 7;
const int bluePin = 8;
int counter = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  int buttonState;
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == LOW) {
    counter++;
    delay(150);
  }
  
  else if (counter == 0) {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  }
  
  else if (counter == 1) {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  }
  
  else if (counter == 2) {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);
  }
  
  else if (counter == 3) {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, HIGH);
  }
  
  else {
    counter = 0;
  }
}
