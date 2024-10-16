/*
 * Blinker.cpp
 *
 *  Created on: Jul 4, 2024
 *      Author: Michin
 */

#include "Blinker.hpp"

/*
 * Function which implements everything connected to blinking
 */
void Blinker::Blink()
{
	/**
	 * HERE IS SECTION WHERE LEDS ON NUCLEO ARE USED FOR BLINKING
	 */
	//< Blink if button pressed
	if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_SET)
	{
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);
	}
	else
	{
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
	}

	//< Blink in sequence
	HAL_Delay(200);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_SET);
	HAL_Delay(200);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);
	HAL_Delay(200);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
	HAL_Delay(200);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_RESET);
	HAL_Delay(200);




}

Blinker::~Blinker() {
	// TODO Auto-generated destructor stub
}

