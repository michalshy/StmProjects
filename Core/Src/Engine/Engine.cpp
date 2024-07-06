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
	log = new Logger(handler);
	blink = new Blinker(log);
	uartCom = new UsartHandler(handler, log);
}

void Engine::Loop()
{
	blink->Blink();
	uartCom->Reception();
	uartCom->HandleLED();
}

Engine::~Engine() {
	delete log;
	delete blink;
	delete uartCom;
}

