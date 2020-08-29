/*
 * DIO.h
 *
 * Created: 7/6/2020 7:59:30 AM
 *  Author: h
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "DIO_CONFIG.h"
#include "Bit_math.h"
#include "STD_TYPE.h"
#include "DIO_HW.h"
#include "DIO_TYPES.h"



void pin_write ( channels channelx ,  state level);
void port_write (uint8 port,uint8 new_value);
void pin_toggle ( channels channelx);
int pin_read ( channels channelx);


#endif /* DIO_H_ */