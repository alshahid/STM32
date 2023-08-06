/*******************************************************************************/
/*Author  : George Ghoubrial                                                   */
/*Date    : 9 AUG 2020                                                         */
/*Version : V01                                                                */
/*******************************************************************************/
#ifndef BIT_MATH_H
#define BIT_MATH_H


#define SET_BIT(REG,BIT_NUM)    (REG=REG | (1<<BIT_NUM))
#define CLEAR_BIT(REG,BIT_NUM)  (REG=REG & ~(1<<BIT_NUM))
#define TOGGLE_BIT(REG,BIT_NUM) (REG=REG ^ (1<<BIT_NUM))
#define GET_BIT(REG,BIT_NUM)    ((REG>>BIT_NUM) & 1)



#endif
