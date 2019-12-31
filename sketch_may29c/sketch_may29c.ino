byte lupTable[16]= {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,
0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};
  byte index[4]={ };
  
void setup() 
{
  DDRD=0xFF;

  DDRB=0b111111;
 int x=0x1234+0x4567;  //579B

for (int i=0;i<=3;i++)
{
  index[i]=x % 16;
  x=x / 16;
  }
}

void loop() 
{
for (int i=0;i<=3;i++)
{
  byte x=lupTable[index[i]];
  PORTD=x;
  

 if (i==0){PORTB=0b0111;}
 else if(i==1){PORTB=0b1011;}
 else if(i==2){PORTB=0b1101;}
 else if(i==3){PORTB=0b1110;}
 delay(1); 
}
}
