#include <LPC214x.h>

void display(unsigned char data)
{
    IO0CLR = 0xFF;        // Clear P0.0 to P0.7   Seven segment data pins  
    IO0SET = data;        // Send data to 7 segment
}

int main()
{
    
    IO0DIR |= 0x000000FF;  // P0.0 to P0.7 as output for 7 segment
   
    IO1DIR |= 0x000F0000;  // P1.16 to P1.19 as output for keypad rows
   
    IO1DIR &= ~0x00F00000;  // P1.20 to P1.23 as input for keypad columns

    while(1)
    {
        /* -------- Row 1 -------- */
        IO1SET = 0x000F0000;      // All rows HIGH     
        IO1CLR = (1<<16);         // R1 LOW ie R1=0, R2=1, R3=1, R4=1

        if(!(IO1PIN & (1<<20)))
           display(0xC0);        // 0

        if(!(IO1PIN & (1<<21)))
            display(0xF9);        // 1

        if(!(IO1PIN & (1<<22)))
           display(0xA4);        // 2

        if(!(IO1PIN & (1<<23)))
          display(0xB0);        // 3



        /* -------- Row 2 -------- */
        IO1SET = 0x000F0000;
        IO1CLR = (1<<17);         // R2 LOW   ie R1=1, R2=0, R3=1, R4=1

        if(!(IO1PIN & (1<<20)))
            display(0x99);        // 4

        if(!(IO1PIN & (1<<21)))
					display(0x92);        // 5
           
        if(!(IO1PIN & (1<<22)))
           	display(0x82);        // 6

        if(!(IO1PIN & (1<<23)))
            display(0xF8);        // 7


        /* -------- Row 3 -------- */
        IO1SET = 0x000F0000;
        IO1CLR = (1<<18);         // R3 LOW ie R1=1, R2=1, R3=0, R4=1

        if(!(IO1PIN & (1<<20)))
        display(0x80);        // 8    
				
        if(!(IO1PIN & (1<<21)))
         display(0x90);        // 9           
			
        if(!(IO1PIN & (1<<22)))
          display(0x88);        // A

        if(!(IO1PIN & (1<<23)))
        display(0x83);        // B
				

        /* -------- Row 4 -------- */
        IO1SET = 0x000F0000;
        IO1CLR = (1<<19);         // R4 LOW ie R1=1, R2=1, R3=1, R4=0

        if(!(IO1PIN & (1<<20)))
         display(0xC6);        // C           
				
        if(!(IO1PIN & (1<<21)))
         display(0xA1);        // D    
				

        if(!(IO1PIN & (1<<22)))
        display(0x86);        // E    
				

        if(!(IO1PIN & (1<<23)))
					display(0x8E);        // F
            
    }
}