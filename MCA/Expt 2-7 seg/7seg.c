#include<reg51.h>
void delay()
{ int i,j;
	for(i=0;i<300;i++)
  for(j=0;j<1275;j++);
}
void main()
{
  while(1)
		
	{
    P0=0xF9;	 // 1111 1001 
		P2=0x01;
	  delay();
		P0=0xA4;	  // 1010 0100
		P2=0x02;
	  delay();
		P0=0x30;	
		P2=0x03;
	  delay();
		P0=0x19;	
		P2=0x04;
	  delay();;
		P0=0x12;
		P2=0x05;
	  delay();
		P0=0x06;
	  delay();
		P0=0x78;	
		P2=0x07;
	  delay();
		P0=0x00;	   
		P2=0x08;
	  delay();
		P0=0x10;
    P2=0x09;	
	  delay();
	  P0=0x40;
    P2=0x00;		
	  delay();
	}
}