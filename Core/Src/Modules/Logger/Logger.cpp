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
	uint8_t size = strlen(buff) + 3;
	char t[size];
	Concat(buff, "\r\n", t);
	HAL_UART_Transmit(handler, (uint8_t*)t, strlen(t), HAL_MAX_DELAY);
	return true;
}

bool Logger::D(const char buff[])
{
	char t[(strlen(buff) + strlen(debug) + 1)];
	Concat(debug, buff, t);
	PrintLn(t);
	return true;
}

bool Logger::W(const char buff[])
{
	char t[(strlen(buff) + strlen(warning) + 1)];
	Concat(warning, buff, t);
	PrintLn(t);
	return true;
}

bool Logger::E(const char buff[])
{
	char t[(strlen(buff) + strlen(error) + 1)];
	Concat(error, buff, t);
	PrintLn(t);
	return true;
}

Logger::~Logger() {
	// TODO Auto-generated destructor stub
}

