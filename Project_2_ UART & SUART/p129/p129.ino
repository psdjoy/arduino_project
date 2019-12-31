#include<SoftwareSerial.h>
SoftwareSerial mySUART (4, 5); //SRX = 4, STX = 5

union
{
  float x = 12.34;
  byte y[4];
} myData;

void setup()
{
  mySUART.begin(9600);
  mySUART.write(myData.y[3]);
  mySUART.write(myData.y[2]);
  mySUART.write(myData.y[1]);
  mySUART.write(myData.y[0]);
}
void loop()
{

}
