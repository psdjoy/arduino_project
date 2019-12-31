void setup() {
  pinMode(A0,INPUT);
  pinMode(8,OUTPUT);
  digitalWrite(8,LOW);

}

void loop() {
    for (int i=1;100;i++){
      bool n=digitalRead(A0);
      if (n==1){
      digitalWrite(8,HIGH);
      delay(1000);
      }
      
      else continue;
      n=0;
    }
}
