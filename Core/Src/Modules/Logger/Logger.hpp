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

class Logger {
	UART_HandleTypeDef* handler = nullptr;
public:
	Logger() = default;
	Logger(UART_HandleTypeDef* _handler);
	bool D(char buff[]);
	bool W(char buff[]);
	bool E(char buff[]);
	bool Print(char buff[]);
	virtual ~Logger();
protected:
	bool PrintChar(char buff);
};


#endif /* SRC_MODULES_LOGGER_LOGGER_HPP_ */
