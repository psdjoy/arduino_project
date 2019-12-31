#include<SoftwareSerial.h>
SoftwareSerial mySUART (4, 5);
byte x;

void setup()
{
  Serial.begin(9600);
  mySUART.begin(9600);
}

void loop()
{
  if (mySUART.available() > 0)
  {
    x = mySUART.read(); //ASCII
    Serial.write(x);
  }
}
