//RGB LED Potentiometer Control
int redPin = 9; //Pin for the red RGB led pin
int greenPin = 10; //Pin for the green RGB led pin
int bluePin = 11; //Pin for the blue RGB led pin

int potPin_red = A0;  //declare pin for the potentiometer for the red LED
int potPin_green = A1;  //declare pin for the potentiometer for the green LED
int potPin_blue = A2;  //declare pin for the potentiometer for the blue LED
 
int readValue_red; //declare variable to store the read value from the potentiometer which controls the red LED
int readValue_green; //declare variable to store the read value from the potentiometer which controls the green LED
int readValue_blue; //declare variable to store the read value from the potentiometer which controls the blue LED
 
int writeValue_red; //declare variable to send to the red LED
int writeValue_green; //declare variable to send to the green LED
int writeValue_blue; //declare variable to send to the blue LED
 
void setup() {
  pinMode(potPin_red, INPUT); 
  pinMode(potPin_green, INPUT); 
  pinMode(potPin_blue, INPUT); 
  
  pinMode(redPin,OUTPUT); 
  pinMode(bluePin,OUTPUT); 
  pinMode(greenPin, OUTPUT); 
}
 
void loop() {
  readValue_red = analogRead(potPin_red); 
  readValue_green = analogRead(potPin_green); 
  readValue_blue = analogRead(potPin_blue); 
  
  writeValue_red = (255./1023.)*readValue_red; 
  writeValue_green = (255./1023.)*readValue_green; 
  writeValue_blue = (255./1023.)*readValue_blue;
  
  analogWrite(redPin,writeValue_red); 
  analogWrite(greenPin,writeValue_green); 
  analogWrite(bluePin,writeValue_blue); 
}
