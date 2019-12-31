#include<SoftwareSerial.h>
SoftwareSerial mySUART (4, 5);

union
{
  float x;
  byte y[4];
} myData;

void setup()
{
  Serial.begin(9600);
  mySUART.begin(9600);
}

void loop()
{
  if(mySUART.available() > 0)
  {
    myData.y[3]= mySUART.read(); //ASCII code
    myData.y[2] = mySUART.read();
    myData.y[1] = mySUART.read();
    myData.y[0] = mySUART.read();
    Serial.print(myData.x,2);
  }
  
}
