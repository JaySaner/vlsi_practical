#include <lpc214x.h> 
#include <stdio.h>

#define PIN_RS   (1<<27)
#define PIN_RW   (1<<28)
#define PIN_EN   (1<<29)

#define RW(x) ((x) ? (IO1SET = PIN_RW) : (IO1CLR = PIN_RW))
#define RS(x) ((x) ? (IO1SET = PIN_RS) : (IO1CLR = PIN_RS))
#define EN(x) ((x) ? (IO1SET = PIN_EN) : (IO1CLR = PIN_EN))

 void delay(unsigned int n);
 void lcd_data (unsigned int data);
 void lcd_cmd(unsigned int data) ;
 void lcd_initialize(void);
 void lcd_display (int row,const char *str); 
void convert(void);             
unsigned int value;
void delay(unsigned int n)
 	{   
 		unsigned int i,j;    
		for(i=0;i<n;i++)     
 	 	for(j=0;j<1200;j++); 
	}  
	
	void lcd_data (unsigned int data)
 {      
		IO1CLR = 0xFF0000;
		IO1SET = data<<16;
		RW(0);
		RS(1);
		EN(1);   
 		delay(8);    
		EN(0); 	 

}   
 void lcd_cmd(unsigned int data) 
{ 
		IO1CLR = 0xFF0000;
		IO1SET = data<<16;
		RW(0);
		RS(0);         //0x1000;      //RS   
		EN(1);   
 		delay(8);    
		EN(0);
}  

 void lcd_initialize(void) 
{   
 		lcd_cmd(0x38);
		delay(8); 
		lcd_cmd(0x0c);
		delay(8); 
		lcd_cmd(0x01);
		delay(8); 
		lcd_cmd(0x06);
		delay(8); 
		lcd_cmd(0x80);
		lcd_display (1," LOGSUN SYSTEMS");
	//	lcd_display (2,"KEY PRESSED:  ");
 }   
int main(void) 
{
		PINSEL1  = 0x00000000;  
		PINSEL0  = 0x00000C00;  
		IODIR0   = 0xFFFFBF;     
		PINSEL2  = 0x00000000;  
		IODIR1   = 0xFFFFFFFF; 	
		lcd_initialize();       
		while(1)
		{
		  AD0CR=0X01200680;
  		while(((value=AD0GDR) & 0x80000000) == 0);
  		value=((value >>6)& 0x3ff );
		  convert();  
		} 
}  

void convert(void)
{
	float x;
	char voltage[20];
	x=(3.3*value)/1024;
	sprintf(voltage,"INPUT=%0.2fVolt",x);
	lcd_display(2,voltage);	
}

void lcd_display(int row,const char *str) 
{   
	 int k;
	if (row==1)
	lcd_cmd(0x80);
	else lcd_cmd(0xC0);
	for(k=0;k<16;k++)
	{
		if(str[k] !=0)
		lcd_data(str[k]);
		else  break;
	}		
while((k<16)){
				lcd_data(' ');
				k++;
			}
 }
