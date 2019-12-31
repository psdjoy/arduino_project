#include <SoftwareSerial.h>
SoftwareSerial mySuart (7 , 6);

union
{
  float lmTmp;
  byte myArray[4];   //for LM35
} myDataLM;

void setup() {
  Serial.begin(9600);
  mySuart.begin(9600);
  analogReference(INTERNAL);
}

void loop() {
  float Lmtmp;
  Lmtmp = (float)100 * (1.1 / 1024) * analogRead(A2);

  myDataLM.lmTmp = Lmtmp;

  mySuart.write(myDataLM.myArray[3]);
  mySuart.write(myDataLM.myArray[2]);
  mySuart.write(myDataLM.myArray[1]);
  mySuart.write(myDataLM.myArray[0]);

  Serial.print("LM Temp= ");
  Serial.println(Lmtmp, 2);
  delay(1000);


}
