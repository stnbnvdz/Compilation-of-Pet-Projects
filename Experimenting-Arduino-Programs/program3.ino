//even ledpins is automatically on if the button is unpressed and odd ledpins will turn on if the button is pressed
int LEDPIN4=4;
int LEDPIN5=5;
int LEDPIN6=6;
int LEDPIN7=7;
int LEDPIN8=8;
int LEDPIN9=9;
int BUTTON=3;
void setup() {
  // put your setup code here, to run once:
pinMode(LEDPIN4, OUTPUT);
pinMode(LEDPIN5, OUTPUT);
pinMode(LEDPIN6, OUTPUT);
pinMode(LEDPIN7, OUTPUT);
pinMode(LEDPIN8, OUTPUT);
pinMode(LEDPIN9, OUTPUT);
pinMode(BUTTON, INPUT);
}
void even() {         //Eto yung unang set ng code para sa even na LED's na siyang iilaw (2,4,6,)
// put your main code here, to run repeatedly:
//first pattern
digitalWrite(LEDPIN4, HIGH); //even ledpins will turn on if it is un pressed
delay(1000);
digitalWrite(LEDPIN4, LOW); //even ledpins will turn off if it is pressed
delay(1000);
digitalWrite(LEDPIN6, HIGH);
delay(1000);
digitalWrite(LEDPIN6, LOW);
delay(1000);
digitalWrite(LEDPIN8, HIGH);
delay(1000);
digitalWrite(LEDPIN8, LOW);
delay(1000);
}

void odd() {      //Eto yung unang set ng code para sa odd na LED's na siyang iilaw (1,3,5)
digitalWrite(LEDPIN5, HIGH); //odd ledpins will turn on if it is un pressed
delay(1000);
digitalWrite(LEDPIN5, LOW); //odd ledpins will turn off if it is pressed
delay(1000);
digitalWrite(LEDPIN7, HIGH);
delay(1000);
digitalWrite(LEDPIN7, LOW);
delay(1000);
digitalWrite(LEDPIN9, HIGH);
delay(1000);
digitalWrite(LEDPIN9, LOW);
delay(1000);
}



void loop(){
  if (digitalRead(BUTTON)==HIGH)
  {
     odd();
  }
  else
  {
    even();
  }
  }
