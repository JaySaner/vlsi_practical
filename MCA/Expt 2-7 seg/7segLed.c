#include <reg51.h>
unsigned char code seg_code[10] =

{
    0xF9, //1111 1001
		0xA4, //1010 0100 
		0xB0,  
		0x99,
		0x92,
		0x82,
		0xF8,
		0x80,
		0x90,
		0xC0,

};

void delay(void)

{
    
    unsigned int i,j;

    for(i=0;i<300;i++)

        for(j=0;j<1275;j++);

}

void main()

{

    unsigned char i,k;

    while(1)

    {
        for(k=0;k<10;k++)
        {

            P3 = k;              // Binary count on LEDs
            delay();
            P0 = seg_code[i];    // Display decimal digit on 7-segment
            delay();

        }

    }

}