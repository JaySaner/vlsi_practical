/* 
   Company Name:- Logsun Systems
	 Project Name: 7 segment with keypad
        
connection details :-
											PORT0(J1) :- (J11)7_seg_data
											PORT1(J2) :- (J12)7_seg_transistor
											PORT2(J3) :- (J13) Keypad
*/

#include <reg51.h>

sbit R1 = P2^0;
sbit R2 = P2^1;
sbit R3 = P2^2;
sbit R4 = P2^3;
sbit C1 = P2^4;
sbit C2 = P2^5; 
sbit C3 = P2^6;
sbit C4 = P2^7;

 void main(void)
  {			
			P0 = 0x00;
			P1 = 0xFF;
		  P2 = 0x0F;
 	   while(1)
			{
				while(P2 == 0x0F){P1=0xFF;}
				C1=0;C2=C3=C4=1;
				if(R1 == 0){P0=0x8E;}	 // Display F
				if(R2 == 0){P0=0x83;}	 // Display E
				if(R3 == 0){P0=0xF8;}	 // Display D
				if(R4 == 0){P0=0xB0;}	 // Display C
				C2=0;C1=C3=C4=1;
				if(R1 == 0){P0=0x86;}	 // Display B
				if(R2 == 0){P0=0x88;}	 // Display A
				if(R3 == 0){P0=0x82;}	 // Display 9
				if(R4 == 0){P0=0xA4;}	 // Display 8
				C3=0;C1=C2=C4=1;
				if(R1 == 0){P0=0xA1;}	 // Display 7
				if(R2 == 0){P0=0x90;}	 // Display 6
				if(R3 == 0){P0=0x92;}	 // Display 5
				if(R4 == 0){P0=0xF9;}	 // Display 4
				C4=0;C2=C3=C1=1;
				if(R1 == 0){P0=0xC6;}	 // Display 3
				if(R2 == 0){P0=0x80;}	 // Display 2
				if(R3 == 0){P0=0x99;}	 // Display 1
				if(R4 == 0){P0=0xC0;}  // Display 0
		
			}		
	}

 