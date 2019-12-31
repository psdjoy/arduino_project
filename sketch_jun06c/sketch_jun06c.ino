byte lupTable[16] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D,
                     0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E,
                     0x79, 0x71
                    };
byte index[8] = { };
unsigned long prmillis;
unsigned int ADCT ;
unsigned long BINTamplified;
void setup()
{
  Serial.begin(9600);
  analogReference(INTERNAL);
  DDRD = 0xFF;
  DDRB = 0b111111;
}

void loop()
{
  do
  {
    refreshDisplay();
  }
  while (millis() - prmillis <= 3000);
  prmillis = millis();

  
  computeBinTemp();
  bcdTemp();
  refreshDisplay();
}

void acquireTemp()
{
  ADCT = analogRead(A4);
}
void computeBinTemp()
{
  acquireTemp();
  BINTamplified = 0x0432 * ADCT;
}

void bcdTemp()
{
  unsigned long y;
  unsigned long x = BINTamplified;
  for (int i = 7; i >= 0; i--)
  {
    y = x % 10;
    index[i] = y;
    x = x / 10;
  }
}



void refreshDisplay()
{

  byte x = lupTable[index[0]];
  PORTD = x;
  bitWrite(PORTB, 5, (bitRead(x, 0)));
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
  bitWrite(PORTB, 5, (bitRead(x, 0)));
  //-------------------------------
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);

  delay(1);

  x = lupTable[index[2]];
  PORTD = x;
  bitWrite(PORTB, 5, (bitRead(x, 0)));

  //-------------------------------
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);

  delay(1);


  x = lupTable[index[3]];
  PORTD = x;
  bitWrite(PORTB, 5, (bitRead(x, 0)));
  //-------------------------------
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  delay(1);

}




