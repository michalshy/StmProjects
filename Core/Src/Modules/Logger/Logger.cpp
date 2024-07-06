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

bool Logger::PrintChar(const char buff)
{
	HAL_UART_Transmit(handler, (uint8_t*)&buff, 1, HAL_MAX_DELAY);
	return true;
}

bool Logger::Print(const char buff[])
{
	HAL_UART_Transmit(handler, (uint8_t*)buff, strlen(buff), HAL_MAX_DELAY);
	PrintChar('\t');
	return true;
}

bool Logger::PrintLn(const char buff[])
{
	HAL_UART_Transmit(handler, (uint8_t*)buff, strlen(buff), HAL_MAX_DELAY);
	PrintChar('\r');
	PrintChar('\n');
	return true;
}

bool Logger::D(const char buff[])
{
	Print("[     DEBUG     ]");
	PrintLn(buff);
}

bool Logger::W(const char buff[])
{
	Print("[    WARNING    ]");
	PrintLn(buff);
}

bool Logger::E(const char buff[])
{
	Print("[     ERROR     ]");
	PrintLn(buff);
}

Logger::~Logger() {
	// TODO Auto-generated destructor stub
}

