void setup() { //configure pin 7 as an input and enable the internal pull-up resistor 
  pinMode(7, INPUT_PULLUP); 
  pinMode(8,OUTPUT); 
  pinMode(9,OUTPUT); 
  pinMode(10,OUTPUT); 
} 

int digitalPressed(int pinnr) //returns true if switch is pressed 
{ 
if (digitalRead(pinnr) == true) 
  return false; 
else 
  return true; 
}

int Find_Trigger(int PinNumber){ 
static int previouspressed=false;//static means global lifetime but local scope 
static int currentpressed=false; 
previouspressed = currentpressed; 
currentpressed = digitalPressed(PinNumber); 
if ((previouspressed==false) && (currentpressed==true)) 
  return true; 
else 
  return false; 
}

int n = 0;

void loop() {
  // put your main code here, to run repeatedly:
  
  if (Find_Trigger(7))
   {
    n++;
    if (n==1)
      {
      digitalWrite(8,true);
      }
    if (n==2)
      {
      digitalWrite(9,true);
      digitalWrite(8,false);
      }
    if (n==3)
      {
      digitalWrite(10,true);
      digitalWrite(9,false);
      }
    if (n==4)
      {
      digitalWrite(8,true);
      digitalWrite(10,false);
      n=0;
      }
     }
  delay(5);

}
