int RledPin =  9;    // Red LED connected to digital pin 9
int GledPin = 10;    // Green LED connected to digital pin 10
int BledPin = 11;    // Blue LED connected to digital pin 11
int _delay  =  6;    // Delay time
int _step   =  1;    // Increment/decrement size

int FadeOn(int pin)
{
  int fadeValue;
  // Ramp up pin  
  for(fadeValue = 0 ; fadeValue <= 255; fadeValue += _step) {
    // sets the value (range from 0 to 255):
    analogWrite(pin, fadeValue);        
    // wait to see the dimming effect    
    delay(_delay);                            
  }
  analogWrite(pin, 255);        
  return(fadeValue);
}

int FadeOff(int pin)
{
  int fadeValue;
  // Ramp down pin  
  for(fadeValue = 255 ; fadeValue >= 0; fadeValue -= _step) {
    // sets the value (range from 0 to 255):
    analogWrite(pin, fadeValue);        
    // wait to see the dimming effect    
    delay(_delay);                            
  }
  analogWrite(pin, 0);        
  return(fadeValue);
}

void setup()  {
   // sets the pins as output
   pinMode(RledPin, OUTPUT);
   pinMode(GledPin, OUTPUT);
   pinMode(BledPin, OUTPUT);
   
  // LEDs off
  analogWrite(RledPin, 0);        
  analogWrite(GledPin, 0); 
  // Ramp up blue LED  
  FadeOn(BledPin); 
}

void loop()  {
  // phase 0: fade in red from min to max
  FadeOn(RledPin); 

  // phase 1: fade out blue from max to min
  FadeOff(BledPin); 

  // phase 2: fade in green from min to max
  FadeOn(GledPin); 

  // phase 3: fade out red from max to min
  FadeOff(RledPin); 

  // phase 4: fade in blue from min to max
  FadeOn(BledPin); 

  // phase 5: fade out from max to min
  FadeOff(GledPin);        
}
