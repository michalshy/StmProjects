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
	const char buff[] = "Hi STM32H723 :) !\r\n";
	HAL_UART_Transmit(handler, (uint8_t*)buff, strlen(buff), HAL_MAX_DELAY);
}

void UsartHandler::ResetMessage()
{
	const char buff[] = "Reset Message!\r\n";
	HAL_UART_Transmit(handler, (uint8_t*)buff, strlen(buff), HAL_MAX_DELAY);
}


void UsartHandler::Reception()
{
	uint8_t value;
	HAL_UART_Receive(handler, &value, 1, HAL_MAX_DELAY);
	message = value;
	char c = message;
	HAL_UART_Transmit_IT(handler, (uint8_t*)&c, 1);
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

