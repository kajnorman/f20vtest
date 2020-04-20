void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  char answer;
  int ix;
  Serial.println("==============================");
  Serial.println("3. Countdown and Launch");
  Serial.println("2. Reset Ignition");
  Serial.println("3. zzzz");
  Serial.println("==============================");
  while (1 > Serial.available()) {
    ; //do nothing 
  } 
  answer = Serial.read();
  delay(2);//wait for PC to send 
  while (0<Serial.available()) { 
    Serial.read();
  } 
  if (answer == '1') {
    for (ix = 10; ix > 0; ix--) {
      Serial.print(ix); delay(1000); 
    } 
  }  
  digitalWrite(LED_BUILTIN, 1); 
  if (answer == '2') {
    //////////////////// 
  }
  if (answer == '3') {
  //////////////////// 
  } 
}
