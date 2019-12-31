  byte lupTable[17]= {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,
0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71,0x80};
  byte index[4]={};
 

void setup() 
{
  DDRB=0b111111;
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  DDRC=0b1111;
  
  int x=0x1234+0x4567;  //579B

  index[0] = x % 16;             //index of 1st digit from right
  x = x/16;
 //-------------------------]

  index[1] = x % 16;             //index1
  x = x/16;
 //-------------------------

  index[2] = x % 16;             //index2
  x = x/16;
 //-------------------------

  index[3] = x % 16;             //index3
  x = x/16;
 //-------------------------
}

void loop() 
{
for (int i=0;i<=3;i++)
{
  PORTB=lupTable[index[i]];
  bool n=bitRead(index[i],6);
  bitWrite(PORTD,6,n);
   bool m=bitRead(index[i],7);
  bitWrite(PORTD,7,m);
 if (i==0){PORTC=0b0111;}
 else if(i==1){PORTC=0b1011;}
 else if(i==2){PORTC=0b1101;}
 else if(i==3){PORTC=0b1110;}
  delay(10); 
}
}
