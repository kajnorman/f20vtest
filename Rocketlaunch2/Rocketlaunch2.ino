int delayTime = 1000;

int readInt(void) //will read a positive integer in the range from 0 to 32767
{
   String inString = "";    // string to hold input
   int inChar = ' ';
   int value;

   do
   {
    if (Serial.available() > 0) 
    {
      inChar = Serial.read();
      if (isDigit(inChar)) 
      {
        // convert the incoming byte to a char and add it to the string:
        inString += (char)inChar;
      }
    }
    else  // no inchar is read
    {
      inChar = 0;  //not a number not a nl
    }
   } while (inChar != '\n');
  value = inString.toInt();
  return value;
}


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  char answer;
  int ix;  
  char confirm = 0; //not confirmed
  
  Serial.println("==============================");
  Serial.println("1.  Countdown and Launch");  
  Serial.println("2.  Reset Ignition");  
  Serial.println("3.  Read delay in count down (miliseconds)");  
  Serial.println("==============================");  
  while (1 > Serial.available())    
    {
    ;  //do nothing    
    }  
  answer = Serial.read();
  delay(2);//wait for PC to send
  while (0<Serial.available())    
    {
      Serial.read();
    }  
  if (answer == '1')  
    {      
      confirm = 0; //not confirmed
      for (ix = 10; ix > 0; ix--) 
      {
        Serial.println(ix);
        delay(delayTime);
        if(digitalRead(2)==0)
          {
             confirm = 1; 
             Serial.println("confirmed launch");
          }
          //if at any point something is in the serial buffer
          //    then empty the buffer
          //    set confirm to 0
          while(Serial.available())
          {
            Serial.read();
            Serial.println("launch aborted");
            confirm=0;
          }

      }
      if (confirm==1)
        {
          digitalWrite(LED_BUILTIN, 1); 
        }        
    }            
  if (answer == '2')  
  {  
    digitalWrite(LED_BUILTIN, 0);             
  }
  if (answer == '3')
  {  
        Serial.println(delayTime = readInt());
  }

}
