/*
 * Logger.cpp
 *
 *  Created on: Jul 6, 2024
 *      Author: Michin
 */

#include "Logger.hpp"

Logger::Logger(UART_HandleTypeDef* _handler) {
	// TODO Auto-generated constructor stub
	handler = _handler;
}

bool Logger::PrintChar(char buff)
{
	HAL_UART_Transmit(handler, (uint8_t*)&buff, 1, HAL_MAX_DELAY);
	return 1;
}

bool Logger::Print(char buff[])
{
	for(size_t i = 0; i < strlen(buff); i++)
	{
		PrintChar(buff[i]);
	}
	return true;
}

bool Logger::D(char buff[])
{
	return false;
}

bool Logger::W(char buff[])
{
	return false;
}

bool Logger::E(char buff[])
{
	return false;
}

Logger::~Logger() {
	// TODO Auto-generated destructor stub
}

