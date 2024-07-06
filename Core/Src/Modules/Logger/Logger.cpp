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
	return true;
}

bool Logger::PrintLn(const char buff[])
{
	HAL_UART_Transmit(handler, (uint8_t*)buff, strlen(buff), HAL_MAX_DELAY);
	PrintChar('\r');
	PrintChar('\n');
	return true;
}

bool Logger::PrintLn(const char buff[], const char msg[])
{
	char* TotalLine{ new char[strlen(buff) + strlen(msg) + 1] };
	TotalLine = strcpy(TotalLine, buff);
	TotalLine = strcat(TotalLine, msg);

	HAL_UART_Transmit(handler, (uint8_t*)TotalLine, strlen(TotalLine), HAL_MAX_DELAY);
	PrintChar('\r');
	PrintChar('\n');
	return true;
}

bool Logger::D(const char buff[])
{
	return false;
}

bool Logger::W(const char buff[])
{
	return false;
}

bool Logger::E(const char buff[])
{
	return false;
}

Logger::~Logger() {
	// TODO Auto-generated destructor stub
}

