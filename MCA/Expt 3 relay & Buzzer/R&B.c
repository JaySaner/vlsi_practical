# include<reg51.h>

sbit Relay = P3^0;
Sbit Relay_SW = P3^1;

void delay()

{
  unsigned char i, j;
  for(i=0;i<300;i++)
  for (j=0;j<1275;j++);
}

void main (void)

{
  P3 = 0xFE;
	relay = 0;
	Relay_SW=1;
	
	while(1)
		
	{
	  if (Relay_SW == 0);
		
		{
		   Relay = 1;
					
		}
	else 
		
	{
	
	};
	
}
	}
