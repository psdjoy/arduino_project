#include <Wire.h>
#include<OneWire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16,2);

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
  lcd.init();
  lcd.backlight();

}
void loop()
{

}

void receiveEvent(int howmany)
{
  interrupts(); //sei();
  myDataDs.myData[3] = Wire.read();
  myDataDs.myData[2] = Wire.read();
  myDataDs.myData[1] = Wire.read();
  myDataDs.myData[0] = Wire.read();



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


