/*
 * Bit_math.h
 *
 * Created: 7/7/2020 12:27:45 AM
 *  Author: h
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define set( name ,  location) (name |=(1<<location))

#define  reset( name ,  location) (name&=~(1<<location))


#define toggle( name ,  location) (name^=(1<<location))

#define read( name ,  location) ((name>>location)&1)



#endif /* BIT_MATH_H_ */