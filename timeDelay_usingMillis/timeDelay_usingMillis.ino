unsigned long presentMillis = 0;
unsigned long currentMillis = millis();

void setup() {
  pinMode(LED_BUILTIN,OUTPUT);

}

void loop() {
  digitalWrite(LED_BUILTIN , !(digitalRead(LED_BUILTIN)));
  timeDelay3();
}

void timeDelay3()
{
  while(millis() - presentMillis <=100)
  ;
  presentMillis = millis();
}

