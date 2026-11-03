#include<reg51.h>
void delay(unsigned char x)
{
int i;
for(i=0;i<x;i++);
}

void main()

{
while(1)

{
 P1=0x33; 
 delay(1000);
P1=0xCC; 
delay(1000);
}


}