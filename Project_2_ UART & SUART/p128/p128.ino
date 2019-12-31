#include<SoftwareSerial.h>
SoftwareSerial mySUART (4, 5); //SRX = 4, STX = 5

void setup()
{
  mySUART.begin(9600);
  mySUART.println("AUST");
}

void loop()
{

}

