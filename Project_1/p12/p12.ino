void setup() 
{
  
Serial.begin(9600);
analogReference(INTERNAL);

}

void loop() 
{

float temp = 100.00 * (1.1/1024.00) * analogRead(A5);
Serial.print("LMT:  ");
Serial.println(temp , 2);
delay(2000);

}
