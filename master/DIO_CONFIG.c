/*
* GIO_CONFIG.c
*
* Created: 7/4/2020 7:14:25 PM
*  Author: h
*/
#include "DIO_CONFIG.h"
#include "DIO_TYPES.h"

const  pin_config pin[]= {
	//port A
	{output,High},
	{output,High},
	{output,High},
	{output,High},
	{output,High},
	{output,High},
	{output,High},
	{output,High},
	//port B
	{output,High},
	{output,High},
	{output,High},
	{output,High},
	{output,High},
	{output,High},
	{input,High},
	{output,High},
	//port C
	{output,High},
	{output,High},
	{output,High},
	{output,High},
	{output,High},
	{output,High},
	{output,High},
	{output,High},
	//port D
	{output,High},
	{output,High},
	{input,High},
	{output,High},
	{output,High},
	{output,High},
	{output,High},
	{output,High},
};

void adjust_pin()
{
	PORTS portx;
	channels channel_num;
	uint8 count = 0;
	for (count=channelA0;count<PIN_NUMBER;count++)
	{
		portx=count/8;
		channel_num=count%8;
		switch (portx)
		{
			case DIO_PORTA:
			if (pin[count].pindir==output)
			{set (DDRA_reg,channel_num);}
			else {reset(DDRA_reg,channel_num);}
			break;
			
			case DIO_PORTB:
			if (pin[count].pindir==output)
			{set (DDRB_reg,channel_num);}
			else {reset(DDRB_reg,channel_num);}
			break;
			
			case DIO_PORTC:
			if (pin[count].pindir==output)
			{set (DDRC_reg,channel_num);}
			else {reset(DDRC_reg,channel_num);}
			break;
			
			case DIO_PORTD:
			if (pin[count].pindir==output)
			{set (DDRD_reg,channel_num);}
			else {reset(DDRD_reg,channel_num);}
			break;
		}
	}
}

