/*
 * bit_math.h
 *
 *  Created on: Jan 5, 2021
 *      Author: MOHAMED ADEL
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BIT)        (REG |=(1<<BIT))
#define CLE_BIT(REG,BIT)        (REG &=~(1<<BIT))
#define TOG_BIT(REG,BIT)        (REG ^=(1<<BIT))
#define GET_BIT(REG,BIT)        ((REG>>BIT)&1)

#define SET_PORT(REG)           (REG |=(0xff)) 
#define CLE_PORT(REG)           (REG &=~(0xff))
#define GET_PORT(REG)           (REG&(0xff)) 

#endif /* BIT_MATH_H_ */
