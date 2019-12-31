#include<Wire.h>
#include<OneWire.h>
OneWire ds(10);
byte dsAddr[8];


union
{
  float dsTmp;
  byte myData[4];     // DS18B20
} myDataDs;

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  analogReference(INTERNAL);

  
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

  myDataDs.dsTmp = celsius;

  Wire.beginTransmission(0x08);
  Wire.write(myDataDs.myData[3]);
  Wire.write(myDataDs.myData[2]);
  Wire.write(myDataDs.myData[1]);
  Wire.write(myDataDs.myData[0]);
  Wire.endTransmission();


  Serial.print("DST: ");
  Serial.print(myDataDs.dsTmp , 2);
  Serial.println(" degC ");
  delay(2000);
  
}

