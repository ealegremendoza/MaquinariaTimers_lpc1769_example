/*
 * systick.c
 *
 *  Created on: 16 mar. 2021
 *      Author: ealegremendoza
 */
#include "systick.h"

void SysTick_Init(uint32_t frecuencia)
{
	uint32_t Temporal=0;
	if(frecuencia > 0xffffff)
		return;
	Temporal=CCLK/frecuencia - 1;
	STCURR = 0;
	STRELOAD = Temporal;
	STCTRL = (1<<0)|(1<<1)|(1<<2);
}
void SysTick_Handler(void)
{
	static uint32_t Divisor_1seg=0;
	static uint32_t Divisor_1min=0;
	Divisor_1seg++;

	if(Divisor_1seg==1000)
	{
		//1 seg!
		Divisor_1seg=0;
		printf("%d\n",Divisor_1min);
		TIMER_Descontar();
		Divisor_1min++;
		if(Divisor_1min == 60)
		{
			//1min
			Divisor_1min=0;
		}
	}
}
