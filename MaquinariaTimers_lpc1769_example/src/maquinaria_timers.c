/*
 * maquinaria_timers.c
 *
 *  Created on: 16 mar. 2021
 *      Author: ealegremendoza
 */

#include "maquinaria_timers.h"

STRUCT_TIMER Timer[CANT_TIMERS];

void TIMER_Start(uint32_t Nro, uint32_t T, void (*f) (void))
{
	if(Nro>CANT_TIMERS)
		return;
	Timer[Nro].Tiempo=T;
	Timer[Nro].Alarma=0;
	Timer[Nro].Func=f;
}

void TIMER_Stop(uint32_t Nro)
{
	if(Nro>=CANT_TIMERS)
		return;
	Timer[Nro].Tiempo=0;
	Timer[Nro].Alarma=0;
	Timer[Nro].Func=0;
}

void TIMER_Descontar(void)// al systick
{
	uint32_t i;
	for(i=0;i<CANT_TIMERS;i++)
	{
		if(Timer[i].Tiempo>0)
		{
			Timer[i].Tiempo--;
			if(0==Timer[i].Tiempo)
				Timer[i].Alarma=1;
		}
	}
}

void TIMER_Analizar(void) //al while(1)
{
	uint32_t i;
	for(i=0;i<CANT_TIMERS;i++)
	{
		if(1==Timer[i].Alarma)
		{
			Timer[i].Alarma=0;
			Timer[i].Func();	//ejecuto la funcion
		}
	}
}
