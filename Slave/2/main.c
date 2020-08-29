/*
* slave_2 final project.c
*
* Created: 8/27/2020 11:36:16 AM
* Author : h
*/

#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "DIO.h"
#include "LCD.h"
#include "SPI.h"


int main(void)
{ volatile char X=0;
	adjust_pin();
	LCD_init();
	SPI_INIT('S');
	while (1)
	{
		X=SPI_SENDandRECIVE(0xFF);
		switch(X)
		{
			
			case 'A':
			LCD_cmd(1);
			LCD_string("LED_2 is ON");
			set(PORTC,2);
			break;
			
			case 'B':
			LCD_cmd(1);
			LCD_string("LED_2 is OFF");
			reset(PORTC,2);
			break;
			
			default:
			LCD_cmd(1);
			LCD_string("Invalid Command");
			
			break;
			
			
		}
	}
}
