void setup() {
 DDRD = 0b11111111;

}

void loop() {

  int i=1;
  while (i<10){
    if (i==1){PORTD = 0b00000110;
    delay(1000);}
    else if(i==2){PORTD = 0b01011011;
    delay(1000);}
    else if ()
    i++;
   if(i==3){i=1;}
  }
}
