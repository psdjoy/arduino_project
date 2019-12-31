#include<Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);


void setup()
{
  analogReference(INTERNAL);
  lcd.begin(16,2);
  lcd.clear();
  lcd.print("Room temperature");
}

void loop()
{
  float temp = 100.00 * (1.10 / 1024.00) * analogRead(A0);
  lcd.setCursor(0, 1);
  lcd.print(temp);
  delay(1000);

}
