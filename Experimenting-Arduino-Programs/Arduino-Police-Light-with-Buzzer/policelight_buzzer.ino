int RedPin = 10;
int BluePin = 9;
int button = 2;

int Bstart = 600; //tone frequency in hertz
int Bend = 1500;
int iBuzz = Bstart;
int buzz = 7;
volatile int sens = 1;

void setup()
{
  attachInterrupt(0, speedChange, CHANGE);
}

void speedChange()
{
  if(digitalRead(2) == LOW) {
    sens = 1;
  }
  else {
    sens = 13;
  }
}

void loop()
{
  int iBlue = 0;
  int iRed = 0;
  for(iBlue=255;iBlue>128;iBlue-=abs(sens)) {
    analogWrite(BluePin,iBlue);
    delay(button);
    tone(buzz,iBuzz);
    iBuzz += sens;
    if(iBuzz >= Bend || iBuzz <= Bstart)
      sens = - sens;
  }
  for(iRed = 0;iRed < 256;iRed+=abs(sens)) { //Calculates the absolute value of a number
    analogWrite(RedPin,iRed);
    if(iBlue > 0) {
      iBlue-=abs(sens);
      analogWrite(BluePin,iBlue);
    }
    delay(button);
    tone(buzz,iBuzz);
    iBuzz += sens;
    if(iBuzz >= Bend || iBuzz <= Bstart)
      sens = - sens;
  }
  for(iRed=255;iRed>128;iRed-=abs(sens)) {
    analogWrite(RedPin,iRed);
    delay(button);
    tone(buzz,iBuzz);
    iBuzz += sens;
    if(iBuzz >= Bend || iBuzz <= Bstart)
      sens = - sens;
  }
  for(iBlue = 0;iBlue < 256;iBlue+=abs(sens)) {
    analogWrite(BluePin,iBlue);
    if(iRed > 0) {
      iRed-=abs(sens);
      analogWrite(RedPin,iRed);
    }
    delay(button);
    tone(buzz,iBuzz);
    iBuzz += sens;
    if(iBuzz >= Bend || iBuzz <= Bstart)
      sens = - sens;
  }
}
