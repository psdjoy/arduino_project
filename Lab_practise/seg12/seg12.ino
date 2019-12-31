byte lupTable[17]= {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,
0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71,0x80};
byte index0;
byte index1;
byte index2;
byte index3;
void setup() {
  DDRB=0b111111;
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  DDRC=0b1111;
  
  int x=0x1234+0x4567;  //579B

  index0 = x % 16;             //index of 1st digit from right
 x = x/16;
 //-------------------------]

   index1 = x % 16;             //index1
 x = x/16;
 //-------------------------

  index2 = x % 16;             //index2
 x = x/16;
 //-------------------------

  index3 = x % 16;             //index3
 x = x/16;
 //-------------------------
}

void loop() 
{
for (int i=0;i<=3;i++)
{
 if (i==0)
 {
   PORTB=lupTable[index2];
  bool n=bitRead(index0,6);
  bitWrite(PORTD,6,n);
  bool m=bitRead(index0,7);
  bitWrite(PORTD,7,m);
  digitalWrite(A0,LOW);
  digitalWrite(A1,HIGH);
  digitalWrite(A2,HIGH);
  digitalWrite(A3,HIGH);
  delay(10);
  
  }
  
  }



}
