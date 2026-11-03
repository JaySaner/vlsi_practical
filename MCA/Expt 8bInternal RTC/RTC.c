#include <LPC214x.h>

/* LCD Control Pins */
#define RS (1<<8)       // P0.8
#define RW (1<<9)       // P0.9
#define EN (1<<10)      // P0.10


/* Simple Delay */
void delay(void)
{
    unsigned int i;

    for(i = 0; i < 50000; i++);
}


/* Send Command to LCD */
void lcd_cmd(unsigned char cmd)
{
    IO0CLR = 0xFF;       // Clear data pins
    IO0SET = cmd;        // Send command

    IO0CLR = RS;         // RS = 0, Command
    IO0CLR = RW;         // RW = 0, Write

    IO0SET = EN;         // Enable = 1
    delay();

    IO0CLR = EN;         // Enable = 0
}


/* Send Data to LCD */
void lcd_data(unsigned char data)
{
    IO0CLR = 0xFF;       // Clear data pins
    IO0SET = data;       // Send data

    IO0SET = RS;         // RS = 1, Data
    IO0CLR = RW;         // RW = 0, Write

    IO0SET = EN;         // Enable = 1
    delay();

    IO0CLR = EN;         // Enable = 0
}


/* Initialize RTC */
void rtc_init(void)
{
    CCR = 0x02;          // Reset RTC
    CCR = 0x00;          // Stop RTC

    HOUR = 10;           // Set Hour
    MIN  = 30;           // Set Minute
    SEC  = 0;            // Set Second

    CCR = 0x11;          // Start RTC
}


/* Main Program */
int main(void)
{
    char num[] = "0123456789";

    /* Port Configuration */
    PINSEL0 = 0x00000000;
    IO0DIR  = 0x000007FF;


    /* LCD Initialization */
    lcd_cmd(0x38);       // 8-bit, 2-line LCD
    lcd_cmd(0x0C);       // Display ON
    lcd_cmd(0x01);       // Clear LCD
    lcd_cmd(0x06);       // Increment cursor


    /* RTC Initialization */
    rtc_init();


    while(1)
    {
        /* First Line of LCD */
        lcd_cmd(0x80);

        /* Display Hour */
        lcd_data(num[HOUR/10]);
        lcd_data(num[HOUR%10]);

        lcd_data(':');

        /* Display Minute */
        lcd_data(num[MIN/10]);
        lcd_data(num[MIN%10]);

        lcd_data(':');

        /* Display Second */
        lcd_data(num[SEC/10]);
        lcd_data(num[SEC%10]);
    }
}