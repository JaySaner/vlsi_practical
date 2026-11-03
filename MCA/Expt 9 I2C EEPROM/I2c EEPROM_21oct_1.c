
#include <lpc214x.h>

#define RS (1 << 19)
#define RW (1 << 20)
#define EN (1 << 21)

volatile unsigned char data = 65;
volatile unsigned char read_data = 0;

void delay(unsigned int n)
{
    volatile unsigned int i, j;

    for(i = 0; i < n; i++)
        for(j = 0; j < 1200; j++);
}

void lcd_cmd(unsigned char x)
{
    IO0CLR = 0x00FF0000;
    IO0SET = (unsigned long)x << 16;

    IO1CLR = RS | RW;
    IO1SET = EN;
    delay(2);
    IO1CLR = EN;
    delay(2);
}

void lcd_data(unsigned char x)
{
    IO0CLR = 0x00FF0000;
    IO0SET = (unsigned long)x << 16;

    IO1CLR = RW;
    IO1SET = RS;
    IO1SET = EN;
    delay(2);
    IO1CLR = EN;
    delay(2);
}

void lcd_init(void)
{
    IO0DIR |= 0x00FF0000;
    IO1DIR |= RS | RW | EN;

    IO1CLR = RS | RW | EN;
    delay(20);

    lcd_cmd(0x38);   // 8-bit, 2-line
    lcd_cmd(0x0C);   // Display ON
    lcd_cmd(0x01);   // Clear display
    lcd_cmd(0x06);   // Cursor increment
}

void lcd_string(char *s)
{
    while(*s)
        lcd_data(*s++);
}

void i2c_init(void)
{
    PINSEL0 = (PINSEL0 & ~0xF0) | 0x50;

    I2C0CONCLR = 0x6C;
    I2C0SCLH = 150;
    I2C0SCLL = 150;
    I2C0CONSET = 0x40;
}

void i2c_start(void)
{
    I2C0CONSET = 0x20;
    I2C0CONCLR = 0x08;

    while(!(I2C0CONSET & 0x08));
}

void i2c_send(unsigned char x)
{
    I2C0DAT = x;
    I2C0CONCLR = 0x28;

    while(!(I2C0CONSET & 0x08));
}

void i2c_stop(void)
{
    I2C0CONSET = 0x10;
    I2C0CONCLR = 0x28;
}

void eeprom_write(unsigned char addr,
                  unsigned char value)
{
    i2c_start();

    i2c_send(0xA0);    // EEPROM write address
    i2c_send(addr);    // Memory address
    i2c_send(value);   // Data

    i2c_stop();

    delay(20);        // EEPROM write cycle
}

unsigned char eeprom_read(unsigned char addr)
{
    unsigned char value;

    i2c_start();

    i2c_send(0xA0);    // EEPROM write address
    i2c_send(addr);    // Memory address

    i2c_start();       // Repeated START
    i2c_send(0xA1);    // EEPROM read address

    I2C0CONCLR = 0x0C; // Clear AA and SI

    while(!(I2C0CONSET & 0x08));

    value = I2C0DAT;

    i2c_stop();

    return value;
}

int main(void)
{
 
    PINSEL1 &= ~0x0000FFFF;


    PINSEL2 = 0x00000000;

    VPBDIV = 0x02;

    lcd_init();
    i2c_init();

    eeprom_write(0x10, data);

    read_data = eeprom_read(0x10);

    lcd_cmd(0x80);
    lcd_string("EEPROM DATA:");

    lcd_cmd(0xC0);

    lcd_data(read_data / 100 + '0');
    lcd_data((read_data / 10) % 10 + '0');
    lcd_data(read_data % 10 + '0');

    while(1);
}
