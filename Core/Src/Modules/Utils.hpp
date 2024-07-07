/*
 * Utils.hpp
 *
 *  Created on: Jul 7, 2024
 *      Author: Michin
 */

#ifndef SRC_MODULES_UTILS_HPP_
#define SRC_MODULES_UTILS_HPP_

#include <string.h>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

inline void Concat(const char* first, const char* sec, char* final)
{
	strcpy(final, first);
	strcat(final, sec);
}


#endif /* SRC_MODULES_UTILS_HPP_ */
