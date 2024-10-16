/*
 * Logger.cpp
 *
 *  Created on: Jul 6, 2024
 *      Author: Michin
 */

#include "Logger.hpp"

constexpr char* debug = "[     DEBUG     ]\t";
constexpr char* warning = "[    WARNING    ]\t";
constexpr char* error = "[     ERROR     ]\t";

bool PrintChar(UART_HandleTypeDef* handler, const char buff)
{
	HAL_UART_Transmit(handler, (uint8_t*)&buff, 1, HAL_MAX_DELAY);
	return true;
}

bool Logger::Print(UART_HandleTypeDef* handler, const char buff[])
{
	HAL_UART_Transmit(handler, (uint8_t*)buff, strlen(buff), HAL_MAX_DELAY);
	PrintChar(handler, '\t');
	return true;
}

bool Logger::PrintLn(UART_HandleTypeDef* handler, const char buff[])
{
	uint8_t size = strlen(buff) + 3;
	char t[size];
	Concat(buff, "\r\n", t);
	HAL_UART_Transmit(handler, (uint8_t*)t, strlen(t), HAL_MAX_DELAY);
	return true;
}

bool Logger::D(UART_HandleTypeDef* handler, const char buff[])
{
	char t[(strlen(buff) + strlen(debug) + 1)];
	Concat(debug, buff, t);
	Logger::PrintLn(handler, t);
	return true;
}

bool Logger::W(UART_HandleTypeDef* handler, const char buff[])
{
	char t[(strlen(buff) + strlen(warning) + 1)];
	Concat(warning, buff, t);
	Logger::PrintLn(handler, t);
	return true;
}

bool Logger::E(UART_HandleTypeDef* handler, const char buff[])
{
	char t[(strlen(buff) + strlen(error) + 1)];
	Concat(error, buff, t);
	Logger::PrintLn(handler, t);
	return true;
}


