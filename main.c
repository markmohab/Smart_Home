/*
* combined_master_final project.c
*
* Created: 8/25/2020 1:49:07 PM
* Author : h
*/
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "DIO.h"
#include "LCD.h"
#include "UART.h"
#include "SPI.h"

int main(void)
{
	volatile unsigned int x=0;
	volatile char z=0;
	
	adjust_pin();
	LCD_init();
	UART_INIT();
	SPI_INIT('M');
	LCD_string("Good Evening");
	_delay_ms(500);
	
	DDRC|=0X01;
	PORTC=1;
	while (1)
	{  
		LCD_cmd(1);
		LCD_string("Select slave num");
		x=UART_RECIVE();
		if (x=='1')
		{
			
			
		}
		else if (x=='2')
		{
			reset(PORTC,0);
		}
		switch(x)
		{
			case '1':
			
			
			LCD_cmd(1);
			LCD_string("Slave 1 selected");
			_delay_ms(200);
			LCD_cmd(1);
			LCD_string("enter command");
			_delay_ms(200);
			LCD_cmd(1);
			LCD_string("A=High  ");
			LCD_string("B=Low  ");
			LCD_string_pos(2,0,"R=Go Back");
			while(1)
			{
				z=UART_RECIVE();
				if (z=='R')
				{
					break;
				}
				else 
					{   
						SLAVE_EN1();
						SPI_SENDandRECIVE(z);
						SLAVE_DIS1();
					}
				
			
			}
			
			break;
		
		
		
		case '2':
	
		LCD_cmd(1);
		LCD_string("Slave 2 selected");
		_delay_ms(200);
		LCD_cmd(1);
		LCD_string("enter command");
		_delay_ms(200);
		LCD_cmd(1);
		LCD_string("A=High  ");
		LCD_string("B=Low  ");
		LCD_string_pos(2,0,"R=Go Back");
		while(1)
		{
			z=UART_RECIVE();
			if (z=='R')
			{
				break;
			}
			else
			{  
				SLAVE_EN2();
				SPI_SENDandRECIVE(z);
				SLAVE_DIS2();
			}
			
		}
		
		break;
		
		default:
		LCD_cmd(1);
		LCD_string("not a valid number");
		
		break;
	}
	
	
}
}

