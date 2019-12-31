void setup() {
  Serial.begin(9600);
  pinMode(6,INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN,LOW);

}

void loop() {
  for (int i=1;i<=5;i++){
    bool n=digitalRead(6);
    if(n== 0){
      digitalWrite(LED_BUILTIN,HIGH);
      delay(500);
      digitalWrite(LED_BUILTIN,LOW);
      
    }
    else continue;
    n=0;
  } 

}
