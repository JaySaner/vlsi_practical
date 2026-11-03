#include <reg51.h>

#define MOTOR P1

sbit DIR = P2^0;

unsigned char sequence[] =
{
    0x01,
    0x02,
    0x04,
    0x08,
};

void delay(void)
{
    unsigned int i, j;

    for(i = 0; i < 50; i++)
        for(j = 0; j < 1275; j++);
}

void main(void)
{
    unsigned char i;

    while(1)
    {
        if(DIR == 1)
        {
				
            /* Clockwise */

            for(i = 0; i < 4; i++)
            {
                MOTOR = sequence[i];
                delay();
            }
        }
        else
        {
            /* Anticlockwise */

            for(i = 4; i > 0; i--)
            {
                MOTOR = sequence[i-1];
                delay();
            }
        }
    }
}