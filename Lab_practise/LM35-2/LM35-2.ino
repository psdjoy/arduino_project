#include<LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);


void setup()
{
  analogReference(INTERNAL);
  lcd.begin(20, 4);
  lcd.setCursor(0,0);
  lcd.print("Room temperature is");
}

void loop()
{
  float temp = 100.00 * (1.10 / 1024.00) * analogRead(A4);
  lcd.setCursor(0, 1); // lcd.setCursor(column , row)
  lcd.print(temp);
  delay(1000);
}
