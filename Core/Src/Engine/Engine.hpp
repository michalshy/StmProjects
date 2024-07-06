/*
 * Engine.h
 *
 *  Created on: Jul 6, 2024
 *      Author: Michin
 */

#ifndef SRC_ENGINE_HPP_
#define SRC_ENGINE_HPP_
#include "../Modules/Blinker/Blinker.hpp"
#include "../Modules/ConnectUsart/UsartHandler.hpp"
#include "stm32h7xx_hal.h"
#include "../Modules/Logger/Logger.hpp"

class Engine {
	UART_HandleTypeDef* handler;
	Blinker blink;
	UsartHandler uartCom;
	Logger log;
public:
	Engine() = default;
	Engine(UART_HandleTypeDef* _handler);
	void Loop();
	virtual ~Engine();
};

#endif /* SRC_ENGINE_HPP_ */
