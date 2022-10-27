/*
 * bit_math.h
 *
 *  Created on: Jan 5, 2021
 *      Author: MOHAMED ADEL
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(x,y)            (x |=(1<<y))
#define CLE_BIT(x,y)            (x &=~(1<<y))
#define TOG_BIT(x,y)            (x ^=(1<<y))
#define GET_BIT(x,y)            ((x>>y)&1)

#define SET_PORT(REG)           (REG |=(0xff))
#define CLE_PORT(REG)           (REG &=~(0xff))
#define GET_PORT(REG)           (REG&(0xff))


#endif /* BIT_MATH_H_ */
