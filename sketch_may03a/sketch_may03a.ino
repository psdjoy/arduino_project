void setup() {
  DDRD=0xFF;

}

void loop() {
byte  lupTable[3]={0x3F,0x06,0x5B};
  for (int i=0;i<=2;i++){
    PORTD=lupTable[i];
    delay(500);
    };
  // put your main code here, to run repeatedly:

}
