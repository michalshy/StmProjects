/*
 * EventLoop.hpp
 *
 *  Created on: Jul 5, 2024
 *      Author: Michin
 */

#ifndef EVENTLOOP_HPP_
#define EVENTLOOP_HPP_


#include "stm32h7xx_hal.h"





void Init(UART_HandleTypeDef* hand);
void EventLoopCpp();   // Cpp function to call into main event loop

#ifdef __cplusplus
extern "C"
{
#endif
    void EventLoopC();  // C function to call into Cpp event loop from main
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C"
{
#endif
    void InitC(UART_HandleTypeDef* hand);  // C function to call into Cpp event loop from main
#ifdef __cplusplus
}
#endif

#endif /* EVENTLOOP_HPP_ */
