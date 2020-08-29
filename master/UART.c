/*
* UART.c
*
* Created: 8/23/2020 6:23:17 PM
*  Author: h
*/
#include <avr/io.h>
#include "UART.h"

void UART_INIT()
{
	UBRRL = 103;
	UBRRH = 0;
	UCSRC |= (1<<1)| (1<<2);
	UCSRB |= (1<<4) | (1<<3);

}

void UART_TRANSMIT(char data)
{
	while(!(UCSRA&(1<<5)));
	UDR = data;
}

char UART_RECIVE()
{
	while(!(UCSRA&(1<<7)));
	return UDR;
}