/*  This is the reliableToggle.ino File  */


void setup() { //configure pin 7 as an input and enable the internal pull-up resistor 
  pinMode(7, INPUT_PULLUP); 
  pinMode(13,OUTPUT); 
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
    digitalWrite(13,!digitalRead(13));
   }
  delay(5);

}
