#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,  2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

union
{
  float lmTemp;
  byte myArray[4];
} myData;

void setup()
{
  Wire.begin(0x08);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.setCursor(0, 0);
}
void loop()
{

}

void receiveEvent(int howmany)
{
  interrupts(); //sei();
  myData.myArray[3] = Wire.read();
  myData.myArray[2] = Wire.read();
  myData.myArray[1] = Wire.read();
  myData.myArray[0] = Wire.read();

  Serial.print("LMT: ");
  Serial.print(myData.lmTemp, 2);
  Serial.println(" degC ");
  
  lcd.print(myData.lmTemp, 2);
  lcd.setCursor(0, 0);
  lcd.print("LMT: ");
  lcd.print(myData.lmTemp, 2);
  lcd.print(' ');
  lcd.write(0xDF);
  lcd.print('C');
  lcd.setCursor(0, 0);
}


