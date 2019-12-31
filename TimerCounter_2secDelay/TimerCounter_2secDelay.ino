void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);

  TCCR1A = 0x00;
  TCCR1B = 0x00;

  TCNT1 = 0x85EE;
  TCCR1B = 0x05;

}


void loop() {
  digitalWrite(LED_BUILTIN, HIGH);


  while (bitRead(TIFR1 , 0) != HIGH)
    ;
    //TIFR1 = 0x01;
  bitSet(TIFR1 , 0);
  TCNT1 = 0x85EE;

  digitalWrite(LED_BUILTIN, LOW);
  while (bitRead(TIFR1 , 0) != HIGH)
    ;
// TIFR1 = 0x01;
   bitSet(TIFR1 , 0);
  TCNT1 = 0x85EE;
}
