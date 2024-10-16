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

void UsartHandler::Reception()
{
	uint8_t value;
	if(HAL_UART_Receive(handler, &value, 1, 0) == HAL_OK)
	{
		message = value;
		Logger::D(handler, "Received byte");
	}
	else
	{
		Logger::D(handler, "Waiting for value");
	}
}

void UsartHandler::HandleLED()
{
	if(message == 'Y')
	{
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_1, GPIO_PIN_SET);
	}
	else if(message == 'N')
	{
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_1, GPIO_PIN_RESET);
	}
}


UsartHandler::~UsartHandler() {
	// TODO Auto-generated destructor stub
}

