void setup() {
  pinMode(A0,INPUT);
  pinMode(8,OUTPUT);
  digitalWrite(8,LOW);
}

void loop() {
    
    do{
      digitalWrite(8,HIGH);
      }
     while(digitalRead(A0)==HIGH); 
  }
