# Maquinaria de Timers - LPC1769 example

El siguiente proyecto contiene un ejemplo de como operar una maquinaria de timers para cualquier tipo de proyecto que requiera de un temporizador.
Los temporizadores estan basados en el systick únicamente. No son temporizadores de hardware.

Se cuenta con una función "Start" con la que se inicializan los datos del temporizador. Una función "STOP" que detiene los temporizadores. 
Una función "Descontar" que decrementa los contadores hasta que llega a cero activado una alarma. Y una función "Analizar" que revisa el estado
de las alarmas de los timers ejecutando la función asociada a dicha alarma cuando esta se activa.

~~~
/*
 *	@brief:		Initialize the indicated timer.
 *	@param:		Nro:	Timer number.
 *	@param:		T:		Task delay. The unit depends on where the "Discount" function is placed.
 *	@param:		f:		Pointer to the function to be executed after time T.
 *	@return:	Nothing.
 */
void TIMER_Start(uint32_t Nro, uint32_t T, void (*f) (void));


/*
 *	@brief:		Stop the indicated timer.
 *	@param:		Nro:	Timer number.
 *	@return:	Nothing.
 */
void TIMER_Stop(uint32_t Nro);

/*
 *	@brief:		Discount all timers.
 *	@param:		Nothing.
 *	@return:	Nothing.
 *	@note:		Invoke this function using a fixed time base like the systick.
 */
void TIMER_Descontar(void);

/*
 *	@brief:		Analyze the status of the timers alarms.
 *				If it finds one activated, it executes its
 *				assigned function.
 *	@param:		Nothing.
 *	@return:	Nothing.
 */
void TIMER_Analizar(void);

~~~

---

- IDE: [MCUXpresso IDE](https://www.nxp.com/design/software/development-software/mcuxpresso-software-and-tools-/mcuxpresso-integrated-development-environment-ide:MCUXpresso-IDE).
- Lenguaje: C.
- Microcontrolador: [LPCXpresso lpc1769 rev C](https://www.embeddedartists.com/products/lpc1769-lpcxpresso/). ![lpc1769](img/lpc1769_lpcxpresso.png)

---
Autor: @ealegremendoza

E-mail: ealegremendoza@gmail.com
