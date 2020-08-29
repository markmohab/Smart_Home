/*
* DIO.h
*
* Created: 7/4/2020 6:58:36 PM
*  Author: h
*/


#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_

typedef enum{
	channelA0=0,
	channelA1,
	channelA2,
	channelA3,
	channelA4,
	channelA5,
	channelA6,
	channelA7,
	channelB0,
	channelB1,
	channelB2,
	channelB3,
	channelB4,
	channelB5,
	channelB6,
	channelB7,
	channelC0,
	channelC1,
	channelC2,
	channelC3,
	channelC4,
	channelC5,
	channelC6,
	channelC7,
	channelD0,
	channelD1,
	channelD2,
	channelD3,
	channelD4,
	channelD5,
	channelD6,
	channelD7
}channels;

typedef enum
{
	DIO_PORTA=0,
	DIO_PORTB,
	DIO_PORTC,
	DIO_PORTD
}PORTS;


typedef enum
{
	input=0,
	output
}data_state;







#endif /* DIO_H_ */