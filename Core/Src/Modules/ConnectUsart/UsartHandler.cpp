/*
 * UsartHandler.cpp
 *
 *  Created on: Jul 5, 2024
 *      Author: Michin
 */

#include "UsartHandler.hpp"

UsartHandler::UsartHandler(UART_HandleTypeDef* _handler) {
	handler = _handler;

}

void UsartHandler::Communicate()
{
	const char message[] = "Hello world!\r\n";
	HAL_UART_Transmit(handler, (uint8_t*)message, strlen(message), HAL_MAX_DELAY);
}

UsartHandler::~UsartHandler() {
	// TODO Auto-generated destructor stub
}

