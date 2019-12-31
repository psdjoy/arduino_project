#include <Wire.h>
#include<OneWire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,  2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

union
{
  float lmTmp;
  byte myArray[4];
} myData;

union
{
  float dsTmp;
  byte myData[4];     // DS18B20
} myDataDs;


void setup()
{
  Wire.begin(0x08);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
  lcd.begin(16,2);
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

  myDataDs.myData[3] = Wire.read();
  myDataDs.myData[2] = Wire.read();
  myDataDs.myData[1] = Wire.read();
  myDataDs.myData[0] = Wire.read();

  Serial.print("LMT: ");
  Serial.print(myData.lmTmp, 2);
  Serial.println(" degC ");
  

  lcd.setCursor(0, 0);
  lcd.print("LMT: ");
  lcd.print(myData.lmTmp, 2);
  lcd.print(' ');
  lcd.write(0xDF);
  lcd.print('C');


  //----------------------------------------




  Serial.print("DST: ");
  Serial.print(myDataDs.dsTmp, 2);
  Serial.println(" degC ");
  

  lcd.setCursor(0, 1);
  lcd.print("DST: ");
  lcd.print(myDataDs.dsTmp, 2);
  lcd.print(' ');
  lcd.write(0xDF);
  lcd.print('C');














  
}


