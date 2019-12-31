#include<Wire.h>
void setup()
{
  Wire.begin();
  Serial.begin(9600);

  Wire.beginTransmission(0x08);
  Wire.write(0x25);
  Wire.endTransmission();
}

void loop() {


}
