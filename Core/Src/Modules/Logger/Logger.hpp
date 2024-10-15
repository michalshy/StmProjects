/*
 * Logger.hpp
 *
 *  Created on: Jul 6, 2024
 *      Author: Michin
 */

#ifndef SRC_MODULES_LOGGER_LOGGER_HPP_
#define SRC_MODULES_LOGGER_LOGGER_HPP_

#include "stm32h7xx_hal.h"

#include "../Utils.hpp"

/**
 * Transform this module into static module, it should always work on the same UART configured in the code
 */

class Logger {
	UART_HandleTypeDef* handler = nullptr;
	const char* debug = "[     DEBUG     ]\t";
	const char* warning = "[    WARNING    ]\t";
	const char* error = "[     ERROR     ]\t";
public:
	Logger() = default;
	Logger(UART_HandleTypeDef* _handler);
	bool D(const char buff[]);
	bool W(const char buff[]);
	bool E(const char buff[]);
	bool Print(const char buff[]);
	bool PrintLn(const char buff[]);
	virtual ~Logger();
protected:
	bool PrintChar(const char buff);
};


#endif /* SRC_MODULES_LOGGER_LOGGER_HPP_ */
