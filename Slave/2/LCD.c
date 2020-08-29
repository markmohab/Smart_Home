/*
* LCD.c
*
* Created: 7/10/2020 4:27:25 PM
*  Author: h
*/

# include "LCD.h"


void LCD_cmd(uint8 data)
{
	uint8 command;
	command= ((LCD_Data_Port & (0x0F))|(data&(0xF0)));
	port_write(LCD_Data_Port,command);
	pin_write(  LCD_RS ,Low);
	pin_write(LCD_E,Low);
	_delay_ms(2);
	pin_write(LCD_E,High);
	_delay_ms(2);
	
	command=((LCD_Data_Port & (0x0F))|(data<<4));
	port_write(LCD_Data_Port,command);
	pin_write(  LCD_RS ,Low);
	pin_write(LCD_E,Low);
	_delay_ms(2);
	pin_write(LCD_E,High);
	_delay_ms(2);
}

void LCD_init (void)
{
	pin_write(LCD_RW,Low);
	_delay_ms(20);
	LCD_cmd(0x33);
	_delay_ms(2);
	LCD_cmd(0x32);
	LCD_cmd(0x28);
	LCD_cmd(0x06);
	LCD_cmd(0x0C);
	LCD_cmd(0x01);
	_delay_ms(2);
	
	
	
}

void LCD_char(char data_2)
{
	uint8 commands;
	commands = ((LCD_Data_Port & (0x0F))|(data_2&(0xF0)));
	port_write(LCD_Data_Port,commands);
	pin_write(  LCD_RS ,High);
	pin_write(LCD_E,Low);
	_delay_ms(2);
	pin_write(LCD_E,High);
	_delay_ms(2);
	
	commands=((LCD_Data_Port & (0x0F))|(data_2<<4));
	port_write(LCD_Data_Port,commands);
	pin_write(  LCD_RS ,High);
	pin_write(LCD_E,Low);
	_delay_ms(2);
	pin_write(LCD_E,High);
	_delay_ms(2);
	
}




 void LCD_string (char *string)
{
uint8 i = 0 ;

while (string[i] !='\0')
{
LCD_char(string[i]);
i++;
}

}


void LCD_string_pos ( uint8 line, uint8 position , char *data)
{
switch (line ){
case 1 :
LCD_cmd ((0x80) | (position & 0x0F));
LCD_string (data);
break;

case 2:
LCD_cmd ((0xC0) | (position & 0x0F));
LCD_string (data);
break;
}
}

