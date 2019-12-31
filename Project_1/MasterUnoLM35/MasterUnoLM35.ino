#include<Wire.h>

union
{
  float lmTmp;
  byte myArray[4];
} myData;

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  analogReference(INTERNAL);
}

void loop()
{
  float lmTmp;
  lmTmp = (float)100 * (1.1 / 1024) * analogRead(A0);

  myData.lmTmp = lmTmp;

  Wire.beginTransmission(0x08);
  Wire.write(myData.myArray[3]);
  Wire.write(myData.myArray[2]);
  Wire.write(myData.myArray[1]);
  Wire.write(myData.myArray[0]);
  Wire.endTransmission();

  Serial.print("LMT: ");
  Serial.print(myData.lmTmp, 2);
  Serial.println(" degC ");
  delay(2000);
}

