#include <reg51.h>

#define MOTOR P1

sbit SW1 = P2^0;     // START
sbit SW2 = P2^1;     // STOP
sbit SW3 = P2^2;     // REVERSE

void delay()
{
    unsigned int i;
    
    for(i = 0; i < 30000; i++);
}

void main()
{
    unsigned char step = 0;
    bit run = 0;
    bit reverse = 0;

    MOTOR = 0x00;
    P2 = 0xFF;       // Make P2 pins as input

    while(1)
    {
        /* START switch */
        if(SW1 == 0)
        {
            run = 1;
        }

        /* STOP switch */
        if(SW2 == 0)
        {
            run = 0;
            MOTOR = 0x00;
        }

        /* REVERSE switch */
        if(SW3 == 0)
        {
            reverse = !reverse;
            
            while(SW3 == 0);   // Wait until switch is released
        }

        /* Motor rotation */
        if(run == 1)
        {
            if(reverse == 0)
            {
                /* Clockwise */

                if(step == 0)
                {
                    MOTOR = 0x0C;       // 1100
                    step = 1;
                }
                else if(step == 1)
                {
                    MOTOR = 0x06;       // 0110
                    step = 2;
                }
                else if(step == 2)
                {
                    MOTOR = 0x03;       // 0011
                    step = 3;
                }
                else
                {
                    MOTOR = 0x09;       // 1001
                    step = 0;
                }
            }
            else
            {
                /* Anticlockwise */

                if(step == 0)
                {
                    MOTOR = 0x09;       // 1001
                    step = 1;
                }
                else if(step == 1)
                {
                    MOTOR = 0x03;       // 0011
                    step = 2;
                }
                else if(step == 2)
                {
                    MOTOR = 0x06;       // 0110
                    step = 3;
                }
                else
                {
                    MOTOR = 0x0C;       // 1100
                    step = 0;
                }
            }

            delay();
        }
    }
}