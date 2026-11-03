#include<reg51.h>
void delay()
{
int i,j;
for(i=0;i<300;i++)
	for(j=0;j<1275;j++);
}

void main()

{
while(1)

{
 P2=0xFF;  //1010 1010
 delay();
 P2=0x00; // 0101 0101
delay();
}


}