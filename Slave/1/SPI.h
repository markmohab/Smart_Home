/*
 * SPI.h
 *
 * Created: 8/24/2020 7:11:28 AM
 *  Author: h
 */ 


#ifndef SPI_H_
#define SPI_H_
#include <avr/io.h>
#define SLAVE_EN1() reset(PORTB,4)
#define SLAVE_DIS1() set(PORTB,4)
#define SLAVE_EN2() reset(PORTB,0)
#define SLAVE_DIS2() set(PORTB,0)


void SPI_INIT(char type);
char SPI_SENDandRECIVE(char data);




#endif /* SPI_H_ */