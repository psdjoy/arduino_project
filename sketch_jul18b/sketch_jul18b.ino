#include<OneWire.h>
OneWire ds(10);
byte dsAddr[8];

void setup() {

  Serial.begin(9600);

}

void loop() 
{
  ds.reset();
  ds.search(dsAddr);

  ds.reset();
  ds.select(dsAddr);
  ds.write(0x44);
  delay(1000);

  byte dsMemData[9];
   ds.reset();
  ds.select(dsAddr);
  ds.write(0xBE);  

  for (int i=0;i<9;i++)
  {
    dsMemData[i]=ds.read();
  }

int rawdsTemp = (dsMemData[1]<<8) | dsMemData[0];
float celsius ;
celsius = (float) rawdsTemp/16.0;

  Serial.print("DST: ");
  Serial.print(celsius, 2);
  Serial.println(" degC ");
  delay(2000);

}
