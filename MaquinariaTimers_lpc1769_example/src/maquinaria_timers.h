/*
 * maquinaria_timers.h
 *
 *  Created on: 16 mar. 2021
 *      Author: ealegremendoza
 */

#ifndef MAQUINARIA_TIMERS_H_
#define MAQUINARIA_TIMERS_H_
#include "headers.h"
typedef struct
{
	uint32_t Tiempo;
	uint8_t Alarma;
	void (*Func) (void);
}STRUCT_TIMER;

#define CANT_TIMERS	3

void TIMER_Start(uint32_t Nro, uint32_t T, void (*f) (void));
void TIMER_Stop(uint32_t Nro);
void TIMER_Descontar(void);
void TIMER_Analizar(void);

#endif /* MAQUINARIA_TIMERS_H_ */
