 #include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

void setup() 
{
  lcd.begin(20,4);
  lcd.setCursor(0,1);
  lcd.print("AUST");
    lcd.setCursor(0,0);
  lcd.print("25*C");

}

void loop() 
{
digitalWrite(13, !digitalRead(13));
delay(2000);
  // put your main code here, to run repeatedly:

}
