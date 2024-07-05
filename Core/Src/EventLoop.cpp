/*
 * EventLoop.cpp
 *
 *  Created on: Jul 5, 2024
 *      Author: Michin
 */

#include "EventLoop.hpp"
#include "Modules/Blinker/Blinker.hpp"
#include "Modules/ConnectUsart/UsartHandler.hpp"



// Main Cpp event loop to run application
void EventLoopCpp()
{
	Blinker blink = Blinker();
	blink.Blink();
}

void Init(UART_HandleTypeDef* hand)
{
	UsartHandler handler = UsartHandler(hand);
	handler.Communicate();
}

// Define all C function calls from main.c below
extern "C"
{
    void EventLoopC()
    {
        EventLoopCpp();
    }
}

extern "C"
{
    void InitC(UART_HandleTypeDef * hand)
    {
    	Init(hand);
    }
}
