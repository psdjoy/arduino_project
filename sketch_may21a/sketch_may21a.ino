void setup() {
   pinMode(6,INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN,LOW);

}

void loop() {
  switch(digitalRead(6))
  {
   case 0: 
   digitalWrite(LED_BUILTIN,HIGH);
   delay(500);
   //digitalWrite(LED_BUILTIN,LOW);
   default :
    digitalWrite(LED_BUILTIN,LOW);
    
    }

}
