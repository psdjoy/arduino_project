void setup() {
  pinMode(A0,INPUT);
  pinMode(8,OUTPUT);
  digitalWrite(8,LOW);

}

void loop() {
  if (digitalRead(A0)==HIGH){
    for (int i=1;5;i++){

      digitalWrite(8,HIGH);
      delay(1000);
      digitalWrite(8,LOW);
      }
    }
    else 
}
