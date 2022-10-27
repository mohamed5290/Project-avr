/*
 * bit_math.h
 *
 *  Created on: Jan 5, 2021
 *      Author: MOHAMED ADEL
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SIT_BIT(x,y)        (x |=(1<<y))
#define CLEAR_BIT(x,y)      (x &=~(1<<y))
#define TOG_BIT(x,y)        (x ^=(1<<y))
#define GET_BIT(x,y)        ((x>>y)&1)


#endif /* BIT_MATH_H_ */
