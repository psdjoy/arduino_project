#include<OneWire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
OneWire ds(10);
byte dsAddr[8];
//---------------------------------
byte lupTable[16] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D,
                     0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E,
                     0x79, 0x71
                    };
byte index[4] = { };
int ampT;
unsigned long prmillis;

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  analogReference(INTERNAL);
  lcd.init();
  lcd.backlight();
  DDRD = 0xFF;
  DDRB = 0b111111;
}

void loop()
{

  ds.reset();
  ds.search(dsAddr);

  ds.reset();
  ds.select(dsAddr);
  ds.write(0x44);
  delay(1000);

  byte dsMemData[9];
  ds.reset();
  ds.select(dsAddr);
  ds.write(0xBE);

  for (int i = 0; i < 9; i++)
  {
    dsMemData[i] = ds.read();
  }

  int rawdsTemp = (dsMemData[1] << 8) | dsMemData[0];
  float celsius ;
  celsius = (float) rawdsTemp / 16.0;
  int temP = rawdsTemp / 16;
  lcd.setCursor(0, 1);
  lcd.print("DST: ");
  lcd.print(temP);
  lcd.print(' ');
  lcd.write(0xDF);
  lcd.print('C');
  delay(2000);
  //--------------------------------------------------


  do
  {
    refreshDisplay();

  }
  while (millis() - prmillis <= 1200);
  prmillis = millis();





  for (int i = 1; i >= 0; i--)
  {
    index[i] = temP % 10;
    temP = temP / 10;
  }
  refreshDisplay();


}

void refreshDisplay()
{

  byte x = lupTable[index[1]];
  PORTD = x;


  //-------------------------------
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  delay(1);

  x = lupTable[index[0]];
  PORTD = x;
  //-------------------------------
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  delay(1);

}

