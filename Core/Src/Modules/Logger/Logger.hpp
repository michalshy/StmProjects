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
public:
	static bool D(UART_HandleTypeDef* handler, const char buff[]);
	static bool W(UART_HandleTypeDef* handler, const char buff[]);
	static bool E(UART_HandleTypeDef* handler, const char buff[]);
	static bool Print(UART_HandleTypeDef* handler, const char buff[]);
	static bool PrintLn(UART_HandleTypeDef* handler, const char buff[]);
};


#endif /* SRC_MODULES_LOGGER_LOGGER_HPP_ */
