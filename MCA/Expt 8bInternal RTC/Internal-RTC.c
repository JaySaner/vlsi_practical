#include <LPC214x.h>



#define RS   (1<<11)
#define RW  (1<<12)
#define EN   (1<<13)


/* Function Prototypes */

void delay(unsigned int n);
void lcd_cmd(unsigned char cmd);
void lcd_data(unsigned char data);
void lcd_init(void);
void lcd_string(char *str);
void rtc_init(void);


/*-------------------------------------------------
                    DELAY
--------------------------------------------------*/

void delay(unsigned int n)
{
    unsigned int i, j;

    for(i=0; i<n; i++)
        for(j=0; j<1200; j++);
}


/*-------------------------------------------------
             SEND COMMAND TO LCD
--------------------------------------------------*/

void lcd_cmd(unsigned char cmd)
{
    IO0CLR = 0xFF;       // Clear P0.0 - P0.7
    IO0SET = cmd;        // Put command on data pins

    IO0CLR = RS;         // RS = 0 : Command
    IO0CLR = RW;         // RW = 0 : Write

    IO0SET = EN;         // EN = 1
    delay(1);

    IO0CLR = EN;         // EN = 0
    delay(2);
}


/*-------------------------------------------------
                SEND DATA TO LCD
--------------------------------------------------*/

void lcd_data(unsigned char data)
{
    IO0CLR = 0xFF;       // Clear P0.0 - P0.7
    IO0SET = data;       // Put data on LCD

    IO0SET = RS;         // RS = 1 : Data
    IO0CLR = RW;         // RW = 0 : Write

    IO0SET = EN;         // EN = 1
    delay(1);

    IO0CLR = EN;         // EN = 0
    delay(2);
}


/*-------------------------------------------------
                LCD INITIALIZATION
--------------------------------------------------*/

void lcd_init(void)
{
    delay(20);           // LCD power-on delay

    lcd_cmd(0x38);       // 8-bit, 2-line LCD
    delay(5);

    lcd_cmd(0x0C);       // Display ON, Cursor OFF
    delay(5);

    lcd_cmd(0x01);       // Clear LCD
    delay(5);

    lcd_cmd(0x06);       // Increment cursor
    delay(5);

    lcd_cmd(0x80);       // First line
}


/*-------------------------------------------------
               DISPLAY STRING
--------------------------------------------------*/

void lcd_string(char *str)
{
    while(*str != '\0')
    {
        lcd_data(*str);
        str++;
    }
}


/*-------------------------------------------------
                RTC INITIALIZATION
--------------------------------------------------*/

void rtc_init(void)
{
    CCR = 0x02;          // Reset RTC clock divider
    CCR = 0x00;          // Stop RTC

    /* Set Initial Time */

    HOUR = 10;
    MIN  = 30;
    SEC  = 0;

    /* Set Initial Date */

    DOM   = 8;
    MONTH = 10;
    YEAR  = 2026;

    /* Start RTC */

    CCR = 0x11;
}


/*-------------------------------------------------
                   MAIN PROGRAM
--------------------------------------------------*/

int main(void)
{
    unsigned char num[] = "0123456789";

    /* Configure P0.0 to P0.10 as GPIO */

    PINSEL0 = 0x00000000;

    /* Configure P0.0 to P0.10 as OUTPUT */

    IO0DIR = 0x000007FF;


    /* Initialize LCD */

    lcd_init();


    /* Display message on second line */

    lcd_cmd(0xC0);
    lcd_string("RTC LPC2148");


    /* Initialize RTC */

    rtc_init();


    while(1)
    {
        /* Move cursor to first line */

        lcd_cmd(0x80);


        /*------------ HOUR ------------*/

        lcd_data(num[HOUR / 10]);
        lcd_data(num[HOUR % 10]);

        lcd_data(':');


        /*------------ MINUTE ----------*/

        lcd_data(num[MIN / 10]);
        lcd_data(num[MIN % 10]);

        lcd_data(':');


        /*------------ SECOND ----------*/

        lcd_data(num[SEC / 10]);
        lcd_data(num[SEC % 10]);


        delay(10);
    }
}