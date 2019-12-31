#include<LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
 

void setup() {
  analogReference(INTERNAL);

}

void loop() {
    float temp= 100.00 * (1.10/1024.00)* analogRead(A5);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Room temperature is");
  lcd.setCursor(0,1);
  lcd.print(temp);

  //digitalWrite(13,!digitalRead(13));
  delay(1000);

}
