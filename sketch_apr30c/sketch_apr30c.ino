void setup() {
  pinMode(A0,INPUT);
  pinMode(8,OUTPUT);
  digitalWrite(8,LOW);

}

void loop() {
  switch(digitalRead(A0)){
    case 1:
    digitalWrite(8,HIGH);
    break;
    default:
    digitalWrite(8,LOW);
  }
}
