#include<Wire.h>

void setup() {
  Serial.begin(9600);
  Serial.println("I2CLCD search");
  Serial.println("----------");

  Wire.begin();
  int i2c= 0x20;
  for (int i=0;i<32;i++)
  {
  Serial.print("Search at [");
  Serial.print("i2c , HEX");
  Serial.print("]");
  Wire.beginTransmission(i2c);
  int result=Wire.endTransmission();
  if(result == 0)
  {
    Serial.println("found");
  }
  else
  {
    Serial.println("not found");
  }
  i2c++;
  }

}

void loop() {
  

}
