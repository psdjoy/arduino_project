byte lupTable[17]= {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,
0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71,0x80};

void setup() {
  DDRD=0xFF;
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
}

void loop() {
  byte x=0x23;
  byte y=0x1C;
  byte z=x+y;
byte indexU=z%16;
byte indexT=z/16;
  PORTD=lupTable[indexT];
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
  delay(10);
  PORTD=lupTable[indexU];
  digitalWrite(9,LOW);
  digitalWrite(8,HIGH);
  delay(10);

  

}
