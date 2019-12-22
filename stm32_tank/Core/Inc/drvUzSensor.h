/*
 * drvUzSensor.h
 *
 *  Created on: Dec 9, 2019
 *      Author: Slavon
 */

#ifndef SRC_DRVUZSENSOR_H_
#define SRC_DRVUZSENSOR_H_

#include"stm32f4xx.h"
#include"stdint.h"
#include"main.h"


void pulse_start();
uint32_t distance_cm();
#endif /* SRC_DRVUZSENSOR_H_ */
