void setup() {
  pinMode(6,INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN,LOW);
}

void loop() {
  if(digitalRead(6)== 0 )
  {
    for (int i=1;i<=5;i++){
      digitalWrite(LED_BUILTIN,HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN,LOW); 
    delay(500);
    }
   
    }

}
