void setup() {
 
  DDRD = 0b11111111;
  
}

void loop() {
  
PORTD = 0b00000110;//1
delay(1000);
PORTD = 0b01011011;//2
delay(1000);
PORTD = 0b01001111; //3
delay(1000);
PORTD = 0b01100110;//4
delay(1000);
PORTD = 0b01101101;//5
delay(1000);
PORTD = 0b01111101;//6
delay(1000);
 PORTD = 0b00000111;//7
delay(1000);
PORTD = 0b01111111;//8
delay(1000);
PORTD = 0b01101111;//9
delay(1000);
}
