byte lupTable[16] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D,
                     0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71
                    };
byte index[4] = { };
int ampT;
unsigned long prmillis;


void setup()
{
  Serial.begin(9600);
  analogReference(INTERNAL);
  DDRB = 0b111111;
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  DDRD = 0xFF;
  //579B   T = 100*(1.1/1023)*analogRead(A5)



}

void loop()

{
  //prmillis = millis();
  //int z = analogRead(A5);

  do
  {
    refreshDisplay();

  }
  while (millis() - prmillis < 1500);
  prmillis = millis();



  ampT = 100 * (1.1 / 1023) * analogRead(A5) * 100; // ampT =0x0AEC =2796

  //ampT= 0x0AEC;
  Serial.println(ampT, DEC);
  //while(1);
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
  PORTB = x;
  bitWrite(PORTD, 6, bitRead(x, 6));
  bitWrite(PORTD, 7, bitRead(x, 7));
  //-------------------------------
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  delay(1);


  x = lupTable[index[1]];

  PORTB = x;
  bitWrite(PORTD, 6, bitRead(x, 6));
  bitWrite(PORTD, 7, bitSet(x, 7));
  //-------------------------------
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);

  delay(1);

  x = lupTable[index[2]];
  PORTB = x;
  bitWrite(PORTD, 6, bitRead(x, 6));
  bitWrite(PORTD, 7, bitRead(x, 7));
  //-------------------------------
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);

  delay(1);


  x = lupTable[index[3]];
  PORTB = x;
  bitWrite(PORTD, 6, bitRead(x, 6));
  bitWrite(PORTD, 7, bitRead(x, 7));
  //-------------------------------
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);

  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  delay(1);

}
