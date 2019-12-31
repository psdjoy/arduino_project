void setup() {
 DDRD= 0b11111111;
 pinMode(8,OUTPUT);

 
 digitalWrite(8,LOW);

}

void loop() {
  PORTD=0b00000110;//1
  delay(1000);
  PORTD=0b01011011;//2
  delay(1000);
  PORTD=0b01001111;//3
  delay(1000);
  PORTD=0b01100110;//4
  delay(1000);
}
