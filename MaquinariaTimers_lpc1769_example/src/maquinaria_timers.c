/*
 * maquinaria_timers.c
 *
 *  Created on: 16 mar. 2021
 *      Author: ealegremendoza
 */

#include "maquinaria_timers.h"

STRUCT_TIMER Timer[CANT_TIMERS];

/*
 *	@brief:		Initialize the indicated timer.
 *	@param:		Nro:	Timer number.
 *	@param:		T:		Task delay. The unit depends on where the "Discount" function is placed.
 *	@param:		f:		Pointer to the function to be executed after time T.
 *	@return:	Nothing.
 */
void TIMER_Start(uint32_t Nro, uint32_t T, void (*f) (void))
{
	if(Nro>CANT_TIMERS)
		return;
	Timer[Nro].Tiempo=T;
	Timer[Nro].Alarma=0;
	Timer[Nro].Func=f;
}

/*
 *	@brief:		Stop the indicated timer.
 *	@param:		Nro:	Timer number.
 *	@return:	Nothing.
 */
void TIMER_Stop(uint32_t Nro)
{
	if(Nro>=CANT_TIMERS)
		return;
	Timer[Nro].Tiempo=0;
	Timer[Nro].Alarma=0;
	Timer[Nro].Func=0;
}

/*
 *	@brief:		Discount all timers.
 *	@param:		Nothing.
 *	@return:	Nothing.
 *	@note:		Invoke this function using a fixed time base like the systick.
 */
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

/*
 *	@brief:		Analyze the status of the timers alarms.
 *				If it finds one activated, it executes its
 *				assigned function.
 *	@param:		Nothing.
 *	@return:	Nothing.
 */
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
