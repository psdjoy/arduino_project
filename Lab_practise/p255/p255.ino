byte lupTable[16] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D,
                     0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E,
                     0x79, 0x71};
byte index[4] = { };
int ampT;
unsigned long prmillis;


void setup()
{
  //Serial.begin(9600);
  analogReference(INTERNAL);
  DDRD = 0xFF;
  DDRB =0b111111;
}

void loop()

{
  do
  {
    refreshDisplay();

  }
  while (millis() - prmillis <= 1200);
  prmillis = millis();


  ampT = 100 * (1.1 / 1023) * analogRead(A4) * 100;

  //Serial.println(analogRead(A4));

  for (int i = 3; i >= 0; i--)
  {
    index[i] = ampT % 10;
    ampT = ampT / 10;
  }
  refreshDisplay();

}

void refreshDisplay()
{

 byte x = lupTable[index[0]];
  PORTD =x;
  bitWrite(PORTB,5,(bitRead(x,0)));
  //use pin 13 because of problem in pin 0.
  
  //-------------------------------
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  delay(1);


  x = lupTable[index[1]];
  x = x | 0b10000000;

  PORTD = x;
  bitWrite(PORTB,5,(bitRead(x,0))); 
  //-------------------------------
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);

  delay(1);

  x = lupTable[index[2]];
  PORTD =x;
  bitWrite(PORTB,5,(bitRead(x,0)));  

  //-------------------------------
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);

  delay(1);


  x = lupTable[index[3]];
  PORTD =x;
  bitWrite(PORTB,5,(bitRead(x,0))); 
  //-------------------------------
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  delay(1);

}
