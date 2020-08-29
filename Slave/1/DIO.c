/*
* DIO.c
*
* Created: 7/6/2020 8:03:50 AM
*  Author: h
*/



#include "DIO.h"

void pin_write (channels channelx,state level)
{
	PORTS portx = channelx/8;
	channels channel_num = channelx%8;

	switch(portx)
	{
		case DIO_PORTA:
		if (level==High)
		{
			set(PORTA_reg,channel_num);
		}
		else
		{
			reset (PORTA_reg,channel_num);
		}
		break;
		case DIO_PORTB:
		if (level==High)
		{
			set(PORTB_reg,channel_num);
		}
		else
		{
			reset (PORTB_reg,channel_num);
		}
		break;
		case DIO_PORTC:
		if (level==High)
		{
			set(PORTC_reg,channel_num);
		}
		else
		{
			reset (PORTC_reg,channel_num);
		}
		break;
		case DIO_PORTD:
		if (level==High)
		{
			set(PORTD_reg,channel_num);
		}
		else
		{
			reset (PORTD_reg,channel_num);
		}
		break;
	}

}

void pin_toggle(channels channelx)
{

	PORTS portx = channelx/8;
	channels channel_num = channelx%8;
	switch(portx)
	{
		case DIO_PORTA:
		toggle (PORTA_reg,channel_num);
		break;

		case DIO_PORTB:
		toggle (PORTB_reg,channel_num);
		break;

		case DIO_PORTC:
		toggle (PORTC_reg,channel_num);
		break;

		case DIO_PORTD:
		toggle (PORTD_reg,channel_num);
		break;
	}
}

int pin_read(channels channelx)
{

	PORTS portx = channelx/8;
	channels channel_num = channelx%8;
	switch(portx)
	{
		case DIO_PORTA:
		if ((read (PINA_reg,channel_num))==1)
		{return 1;}
		else
		{return 0;}
		break;

		case DIO_PORTB:
		if ((read (PINB_reg,channel_num))==1)
		{return 1;}
		else
		{return 0;}
		break;

		case DIO_PORTC:
		if ((read (PINC_reg,channel_num))==1)
		{return 1;}
		else
		{return 0;}
		break;

		case DIO_PORTD:
		if ((read (PIND_reg,channel_num))==1)
		{return 1;}
		else
		{return 0;}
		break;


	}
	return 0;
}

void port_write (PORTS Portx ,uint8 new_value)
{
	switch(Portx){
		case DIO_PORTA:
		PORTA_reg = new_value;
		break;
		case DIO_PORTB:
		PORTB_reg = new_value;
		break;
		case DIO_PORTC:
		PORTC_reg = new_value;
		break;
		case DIO_PORTD:
		PORTD_reg = new_value;
		break;
	}
}

