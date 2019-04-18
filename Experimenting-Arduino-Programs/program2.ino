
//LED Patterns
int L1 = 13;
int L2 = 12;
int L3 = 11;
int L4 = 10;
int L5 = 9;

int buttonPin = 6;  //the number of the pushbutton pin

int de=50;  // delay time

int p=0;    // variable for pattem

int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  

  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);
  pinMode(L5, OUTPUT);
    
  pinMode(buttonPin, INPUT);

}

void loop()
{
 buttonState = digitalRead(buttonPin);

 if (buttonState == HIGH)
 
    {
      p++;
      delay(500);
    } 
    else if(p==3)
    {
      p=p-2;
    }
 
  if(p==1)              // eto ung first pattern ng code nila bali 2 sets ito since 2 patterns ang ginagawa ng LED nila
  {
 digitalWrite(L1,1); 
 digitalWrite(L2,0); 
 digitalWrite(L3,0); 
 digitalWrite(L4,0); 
 digitalWrite(L5,0); //1
  delay(de);  
  
 digitalWrite(L1,0); 
 digitalWrite(L2,1); 
 digitalWrite(L3,0); 
 digitalWrite(L4,0); 
 digitalWrite(L5,0);  //2
  delay(de); 
  
 digitalWrite(L1,0); 
 digitalWrite(L2,0); 
 digitalWrite(L3,1); 
 digitalWrite(L4,0); 
 digitalWrite(L5,0);  //3
  delay(de); 
  
 digitalWrite(L1,0); 
 digitalWrite(L2,0); 
 digitalWrite(L3,0); 
 digitalWrite(L4,1); 
 digitalWrite(L5,0); //4
  delay(de); 
  
 digitalWrite(L1,0); 
 digitalWrite(L2,0); 
 digitalWrite(L3,0); 
 digitalWrite(L4,0); 
 digitalWrite(L5,1);  //5
  delay(de); 
  
   }

  if(p==2)                    // etong "p==2" is ung second pattern ng code nila eto ung second effect na nangyayari sa LEDs
  { 
  digitalWrite(L1,0); 
 digitalWrite(L2,0); 
 digitalWrite(L3,0); 
 digitalWrite(L4,0); 
 digitalWrite(L5,1);  //5
  delay(de); 
  
  digitalWrite(L1,0); 
 digitalWrite(L2,0); 
 digitalWrite(L3,0); 
 digitalWrite(L4,1); 
 digitalWrite(L5,0);  //4
  delay(de);  
 
  digitalWrite(L1,0); 
 digitalWrite(L2,0); 
 digitalWrite(L3,1); 
 digitalWrite(L4,0); 
 digitalWrite(L5,0); //3
  delay(de);  
 
 
  digitalWrite(L1,0); 
 digitalWrite(L2,1); 
 digitalWrite(L3,0); 
 digitalWrite(L4,0); 
 digitalWrite(L5,0);  //2
  delay(de); 
  
   digitalWrite(L1,1); 
 digitalWrite(L2,0); 
 digitalWrite(L3,0); 
 digitalWrite(L4,0); 
 digitalWrite(L5,0);  //1
  delay(de);  
  
  }
   
               
}
