/*
===============================================================================
 Name        : main.c
 Author      : ealegremendoza
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "headers.h"
void System_Init(void)
{
	InitPLL();//cclk 100MHz
	SysTick_Init(1000);	//1ms
}

void DoSomething(void)
{
	printf("Hola!\n");
}

int main(void)
{
	System_Init();
	TIMER_Start(0,10,DoSomething);	//TIMER[0],T:10(segundos),Func: DoSomething
    while(1) {
    	TIMER_Analizar();
    }
    return 0 ;
}
