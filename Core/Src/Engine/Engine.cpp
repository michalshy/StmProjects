/*
 * Engine.cpp
 *
 *  Created on: Jul 6, 2024
 *      Author: Michin
 */

#include "Engine.hpp"

Engine::Engine(UART_HandleTypeDef* _handler)
{
	handler = _handler;

	log = Logger(handler);
	blink = Blinker(&log);
	uartCom = UsartHandler(handler, &log);

	mInit = true;
}

void Engine::Loop()
{
	if(mInit)
	{
		blink.Blink();
		uartCom.Reception();
		uartCom.HandleLED();
	}
}
