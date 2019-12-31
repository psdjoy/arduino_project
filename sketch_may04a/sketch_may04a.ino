void setup() {
 DDRD=0xFF;
 pinMode(8,OUTPUT);
 pinMode(9,OUTPUT);
}

void loop() {
  PORTD=0xDB;
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
  delay(10);
  PORTD=0x4F;
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  delay(10);
}
