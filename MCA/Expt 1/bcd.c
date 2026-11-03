#include <reg51.h> 
void delay() 
{ 
unsigned int i, j; 
for(i = 0; i < 300; i++) 
{ 
for(j = 0; j < 1275; j++); 
} 
} 
void main() 
{ 
unsigned char bcd; 
while(1) 
{ 
for (bcd=0;bcd<=9;bcd++)
{
	P2=bcd;
	delay();
} 
} 
}