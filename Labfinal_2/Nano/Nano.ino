#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include <SoftwareSerial.h>
SoftwareSerial mySuart (7 , 6);

union
{
  float x;
  byte y[4];
} myData;

void setup()
{
  Serial.begin(9600);
  mySuart.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop()
{
  if (mySuart.available() > 0)
  {
    myData.y[3] = mySuart.read(); //ASCII code
    myData.y[2] = mySuart.read();
    myData.y[1] = mySuart.read();
    myData.y[0] = mySuart.read();
    Serial.print("LM Temp = ");
    Serial.println(myData.x, 2);

    lcd.setCursor(0 , 0);
    lcd.print("LM Temp =  ");
    lcd.println(myData.x, 2);
    delay(1000);
  }

}
