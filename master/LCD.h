/*
* LCD.h
*
* Created: 7/10/2020 4:27:35 PM
*  Author: h
*/


#ifndef LCD_H_
#define LCD_H_
#define F_CPU 16000000UL
#include <util/delay.h>
#include "DIO.h"


#define LCD_Data_Port DIO_PORTA
#define LCD_Control_Port DIO_PORTB

#define LCD_RS channelB1
#define LCD_RW channelB2
#define LCD_E channelB3


void LCD_cmd(uint8 data);
void LCD_init (void);
void LCD_char (char data_2);
void LCD_string (char *string);
void LCD_string_pos ( uint8 line, uint8 position , char *data);









#endif /* LCD_H_ */