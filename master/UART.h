/*
 * UART.h
 *
 * Created: 8/23/2020 6:41:01 PM
 *  Author: h
 */ 


#ifndef UART_H_
#define UART_H_
#define BOT 9600



void UART_INIT(void);
void UART_TRANSMIT(char data);
char UART_RECIVE(void);


#endif /* UART_H_ */