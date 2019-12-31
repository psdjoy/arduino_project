  byte lupTable[16]= {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,
0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};
  
void setup() 
{
  DDRD=0b11111111;
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);

  analogReference(INTERNAL);
}

void loop() 
{
 unsigned int ADCT= analogRead(A4);
 unsigned long BINTamplified;
 BINTamplified= 0x0432 * ADCT;

 byte bcdArray[8];
 unsigned long x= BINTamplified;
 for(int i=7;i>=0;i--)
 {
  x=x%10;
  bcdArray[i];
  x=BINTamplified /10;
 }
 //byte x0=LupTable(bcdArray[0]);
 //byte x1=LupTable(bcdArray[1]);
 //byte x2=LupTable(bcdArray[2]);
 //byte x3=LupTable(bcdArray[3]);
byte ccArray[4];
for(int i=0;i<=3;i++)
{
  ccArray[i]=lupTable[bcdArray[i]];
}
ccArray[1]=ccArray[1] | 0b10000000;
while(1)
{
  byte x=0b111111;
  for(int i=0;i<4;i++)
  {
    PORTD=ccArray[i];
    bitClear(x,i);
    delay(1);
  }
}  
}
