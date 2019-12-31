unsigned long presentMillis = 0;
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);

}

void loop() {
   byte x;
  if (Serial.available() > 0)
  {
    x = Serial.read();
  }

}

void serialEvent()
{ int x;
   x = Serial.read();
   for (int i=0;i<x;i++)
   {
    digitalWrite(LED_BUILTIN,HIGH);
    delay(1000);
     digitalWrite(LED_BUILTIN,LOW);
    delay(1000);
   }

}
void timeDelay3()
{
  while(millis() - presentMillis !=1000)
  ;
  presentMillis = millis();
}

