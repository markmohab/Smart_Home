/*
* SPI.c
*
* Created: 8/24/2020 7:10:35 AM
*  Author: h
*/
#include <avr/io.h>
#include "SPI.h"
#include "Bit_math.h"
#define SPI_direction DDRB
#define SPI_port PORTB
#define SS 4
#define MOSI 5
#define MISO 6
#define CLK 7



void SPI_INIT(char type)
{ 
	switch(type)
	{
		case'M':
		  SLAVE_DIS1();
		  SLAVE_DIS2();
		set(SPI_direction,SS);
		reset(SPI_direction,MISO);
		set(SPI_direction,MOSI);
		set(SPI_direction,CLK);
		SPCR=(1<<SPE)|(1<<SPR0)|(1<<MSTR);
	
		
		break;
		
		case'S':
		reset(SPI_direction,SS);
		set(SPI_direction,MISO);
		reset(SPI_direction,MOSI);
		reset(SPI_direction,CLK);
		SPCR|=(1<<SPE)|(1<<SPR0);
		break;
	}
		
		
		
	
}



char SPI_SENDandRECIVE(char data)
{	
	SPDR=data;
	while( !(SPSR&(1<<SPIF)) ) ;
	return SPDR;
		
}

