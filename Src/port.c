/*
 * port.c
 *
 *  Created on: 16 de dez de 2018
 *      Author: raul
 */

#include "gpio.h"
#include "port.h"

void pinMode(GPIO_TypeDef* display_port, uint32_t pin, byte isOutput){

	GPIO_InitTypeDef GPIO_InitStruct = {0};

	HAL_GPIO_WritePin(display_port, pin, GPIO_PIN_RESET);

    if(isOutput){
		GPIO_InitStruct.Pin = pin;
    	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		HAL_GPIO_Init(display_port, &GPIO_InitStruct);
    }

    else	{
		GPIO_InitStruct.Pin = pin;
    	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		HAL_GPIO_Init(display_port, &GPIO_InitStruct);
    }

}

void digitalWrite(GPIO_TypeDef* display_port, uint32_t pin, byte setOrReset){
    if (setOrReset)
    	HAL_GPIO_WritePin(display_port, pin, GPIO_PIN_SET);
    else
    	HAL_GPIO_WritePin(display_port, pin, GPIO_PIN_RESET);
}

GPIO_PinState digitalRead(GPIO_TypeDef* display_port, uint32_t pin){
	return HAL_GPIO_ReadPin(display_port, pin);
}




uint32_t delaySetup(){
	  CoreDebug->DEMCR &= ~CoreDebug_DEMCR_TRCENA_Msk; // ~0x01000000;
	  CoreDebug->DEMCR |=  CoreDebug_DEMCR_TRCENA_Msk; // 0x01000000;
	  DWT->CTRL &= ~DWT_CTRL_CYCCNTENA_Msk; //~0x00000001;
	  DWT->CTRL |=  DWT_CTRL_CYCCNTENA_Msk; //0x00000001;
	  DWT->CYCCNT = 0;
	  asm volatile ("NOP");
	  asm volatile ("NOP");
	  asm volatile ("NOP");

	  return DWT->CYCCNT;
}


inline void delayMicroseconds(unsigned int delay){
	  uint32_t clk_cycle_start = DWT->CYCCNT;
	  delay *= (HAL_RCC_GetHCLKFreq() / 1000000);
	  while ( (DWT->CYCCNT - clk_cycle_start) < delay);
}

inline void delayMilliseconds(unsigned int delay){
	while(delay--)
		delayMicroseconds(1000);
}
