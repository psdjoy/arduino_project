byte lupTable[17]= {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,
0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71,0x80};

void setup() {
  DDRD=0xFF;
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
}

void loop() {
  byte x=0x13;
  byte y=0x27;
  byte z=x+y;
  byte z1=z;
  z=z>>4;
  z1=z1&0b00001111;
  PORTD=lupTable[z];
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
  delay(10);
  PORTD=lupTable[z1];
  digitalWrite(9,LOW);
  digitalWrite(8,HIGH);
  delay(10);

  

}
