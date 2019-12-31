void setup()
{
  Serial.begin(9600);

}

void loop()
{
  byte x;
  
  if (Serial.available() > 0)
  {
    x  = Serial.read();
    Serial.write(x);
    
  }
  
}
