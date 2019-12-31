void setup() {
 
  pinMode(A0,INPUT);
  pinMode(8,OUTPUT);
  digitalWrite(8,LOW);
  
  // put your setup code here, to run once:

}

void loop() {
 L1: bool n= digitalRead(A0);
 if (n==1){
  digitalWrite(8,HIGH);
  }
  else {
    digitalWrite(8,LOW);
    }
  // put your main code here, to run repeatedly:

}
