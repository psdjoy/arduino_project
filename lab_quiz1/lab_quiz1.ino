#include<LiquidCrystal.h>
LiquidCrystal lcd(9, 3, 4, A0, A1, 13);


void setup()
{
  Serial.begin(9600);
  analogReference(INTERNAL);
  lcd.begin(20, 4);
  lcd.setCursor(0,0);
  lcd.print("Room temperature is");
}

void loop()
{
  float temp = 100.00 * (1.10 / 1023.00) * analogRead(A4);
  lcd.setCursor(0 , 1);
  lcd.print(temp , 4);
  Serial.println(temp , 4);
  delay(2000);
}
