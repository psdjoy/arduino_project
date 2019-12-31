void setup() {
  Serial.begin(9600);
  analogReference(INTERNAL);

}

void loop() {
 //float temp = 100.00 * (1.10 / 1024.00)*analogRead(A5);
 unsigned int temp = 100.00 * (1.10 / 1024.00)*analogRead(A5);
  Serial.println(temp,DEC);
  delay(2000);

}
