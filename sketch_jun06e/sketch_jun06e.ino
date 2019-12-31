void setup() {
  Serial.begin(9600);

}

void loop() {
 Serial.write(0x37+ 0x0A);
  //Serial.write('B');
delay(1000);
}
