/*
 * Logger.hpp
 *
 *  Created on: Jul 6, 2024
 *      Author: Michin
 */

#ifndef SRC_MODULES_LOGGER_LOGGER_HPP_
#define SRC_MODULES_LOGGER_LOGGER_HPP_

#include "stm32h7xx_hal.h"
#include <string.h>
#include <cstring>

class Logger {
	UART_HandleTypeDef* handler = nullptr;
public:
	Logger() = default;
	Logger(UART_HandleTypeDef* _handler);
	bool D(const char buff[]);
	bool W(const char buff[]);
	bool E(const char buff[]);
	bool Print(const char buff[]);
	bool PrintLn(const char buff[]);
	bool PrintLn(const char buff[], const char msg[]);
	virtual ~Logger();
protected:
	bool PrintChar(const char buff);
};


#endif /* SRC_MODULES_LOGGER_LOGGER_HPP_ */
