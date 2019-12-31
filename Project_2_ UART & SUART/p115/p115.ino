void setup() {
  pinMode(3,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  byte x;
  if (Serial.available() > 0)
  {
    x = Serial.read();
  while(digitalRead(3)!=LOW)
  ;
      Serial.write(x);
  }
}
