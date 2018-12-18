/*
 * port.h
 *
 *  Created on: 16 de dez de 2018
 *      Author: raul
 */

#ifndef PORT_H_
#define PORT_H_

#include "my_types.h"
#include "stm32f1xx.h"

//------------------------------------------------------------------------------
// Comando de digital I/O
void pinMode(GPIO_TypeDef* display_port, uint32_t pin, byte isOutput);
//------------------------------------------------------------------------------
void digitalWrite(GPIO_TypeDef* display_port, uint32_t pin, byte setOrReset);
//------------------------------------------------------------------------------
GPIO_PinState digitalRead(GPIO_TypeDef* display_port, uint32_t pin);
//------------------------------------------------------------------------------

// Comando de delay
//------------------------------------------------------------------------------
uint32_t delaySetup();
//------------------------------------------------------------------------------
void delayMicroseconds(unsigned int delay);
//------------------------------------------------------------------------------
void delayMilliseconds(unsigned int delay);
//------------------------------------------------------------------------------


#endif /* PORT_H_ */
