#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED
#include<avr/interrupt.h>
#include <avr/io.h>
#include<util/delay.h>
struct{volatile unsigned int isr_Flag1:1;
       volatile unsigned int isr_Flag2:1;}flag;
#define SET_BIT(PORT,BIT) PORT|=(1<<BIT)
#define CLR_BIT(PORT,BIT) PORT&=~(1<<BIT)
#endif // TEST_H_INCLUDED

