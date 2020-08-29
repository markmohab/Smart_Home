/*
 * DIO_CONFIG.h
 *
 * Created: 7/4/2020 7:14:07 PM
 *  Author: h
 */ 


#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_

#include "Bit_math.h"
#include "STD_TYPE.h"
#include "DIO_HW.h"
#include "DIO_TYPES.h"

typedef struct {
	data_state pindir;
	state pin_level; 
	}pin_config;
	
	#define PIN_NUMBER 32
	
	void adjust_pin (void);



#endif /* DIO_CONFIG_H_ */