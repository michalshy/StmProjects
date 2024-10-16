/*
 * Blinker.h
 *
 *  Created on: Jul 4, 2024
 *      Author: Michin
 */

#ifndef SRC_BLINKER_BLINKER_H_
#define SRC_BLINKER_BLINKER_H_

#include "stm32h7xx_hal.h"
#include "../Logger/Logger.hpp"

/*
 * First project which is blinking of LED's
 */
class Blinker{
public:
	Blinker() = default;

	void Blink();

	virtual ~Blinker();
};

#endif /* SRC_BLINKER_BLINKER_H_ */
