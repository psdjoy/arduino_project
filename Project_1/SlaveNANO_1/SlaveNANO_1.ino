#include<Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x31, 16,2);
byte cmd;
void setup()
{
  Wire.begin(0x08);
  Serial.begin(9600);
  Wire.onReceive(receiveEvent);

}

void receiveEvent()
{
  cmd = Wire.read();
  Serial.println(cmd, HEX);

}
void loop()
{ 
 // lcd.begin(16,2);
  lcd.setCursor(0, 0);
  lcd.print(cmd,HEX);
  delay(2000);
}
