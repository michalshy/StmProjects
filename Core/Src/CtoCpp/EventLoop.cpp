/*
 * EventLoop.cpp
 *
 *  Created on: Jul 5, 2024
 *      Author: Michin
 */

#include "EventLoop.hpp"
#include "../Engine/Engine.hpp"
#include <vector>

static UART_HandleTypeDef * handler;
static Engine eng;

void InitCpp()
{
	eng = Engine(handler);
}

// Main Cpp event loop to run application
void EventLoopCpp()
{
	eng.Loop();
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
    	handler = hand;
    	InitCpp();
    }
}
