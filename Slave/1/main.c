/*
 * SLAVE1_FINAL PROJECT.c
 *
 * Created: 8/26/2020 1:14:01 PM
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
   set(PORTD,0);
    while (1) 
    {
		X=SPI_SENDandRECIVE(0xFF);
		
		switch(X)
		{
			
			
			case 'A':
			LCD_cmd(1);
			LCD_cmd(0XE);
			LCD_string("LED_1 is ON");
			set(PORTC,0);
			break;
			
			case 'B':
			LCD_cmd(1);
			LCD_string("LED_1 is OFF");
			reset(PORTC,0);
			break;
			
			//case 'O':
		//	LCD_cmd(8);
			
			//break;
			
			default:
			LCD_cmd(1);
			LCD_string("Invalid Command");
			
			break;
			
		}
		
    }
	reset(PORTD,0);
}

