/*
 * UsartHandler.h
 *
 *  Created on: Jul 5, 2024
 *      Author: Michin
 */

#ifndef SRC_MODULES_CONNECTUSART_USARTHANDLER_H_
#define SRC_MODULES_CONNECTUSART_USARTHANDLER_H_

#include "stm32h7xx_hal.h"
#include <string.h>

class UsartHandler {
	UART_HandleTypeDef* handler = nullptr;
public:
	UsartHandler(UART_HandleTypeDef* _handler);

	void Communicate();

	virtual ~UsartHandler();
};

#endif /* SRC_MODULES_CONNECTUSART_USARTHANDLER_H_ */
