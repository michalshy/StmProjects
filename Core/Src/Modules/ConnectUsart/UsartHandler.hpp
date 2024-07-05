/*
 * UsartHandler.h
 *
 *  Created on: Jul 5, 2024
 *      Author: Michin
 */

#ifndef SRC_MODULES_CONNECTUSART_USARTHANDLER_H_
#define SRC_MODULES_CONNECTUSART_USARTHANDLER_H_

#include "stm32h7xx_hal.h"
#include "../Blinker/Blinker.hpp"
#include <string>
#include <string.h>


class UsartHandler {
	UART_HandleTypeDef* handler = nullptr;
	char message;
public:
	UsartHandler() = default;
	UsartHandler(UART_HandleTypeDef* _handler);

	void Communicate();
	void HandleLED();
	void Reception();
	void ResetMessage();
	virtual ~UsartHandler();
};

#endif /* SRC_MODULES_CONNECTUSART_USARTHANDLER_H_ */
