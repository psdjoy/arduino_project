#include<Wire.h>

union
{
  float lmTmp;
  byte myArray[4];   //for LM35
} myDataLM;


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

  myDataLM.lmTmp = lmTmp;

  // Wire.beginTransmission(0x08);

  //Wire.endTransmission();

  Serial.print("LMT: ");
  Serial.print(myDataLM.lmTmp, 2);
  Serial.println(" degC ");
  delay(1000);

  Wire.beginTransmission(0x08);
  Wire.write(myDataLM.myArray[3]);
  Wire.write(myDataLM.myArray[2]);
  Wire.write(myDataLM.myArray[1]);
  Wire.write(myDataLM.myArray[0]);


  Wire.endTransmission();







}

