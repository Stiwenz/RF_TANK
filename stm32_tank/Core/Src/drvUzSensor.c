/*
 * drvUzSensor.c
 *
 *  Created on: Dec 9, 2019
 *      Author: Slavon
 */

#include "drvUzSensor.h"

uint32_t current_time_uS = 0;

void pulse_start() {
	clean_tick();
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, SET);
	current_time_uS = Get_uS();

	while (current_time_uS < 10)
	{
		current_time_uS = Get_uS();
	}
	if (current_time_uS >= 10)
	{
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, RESET);

	};

}

uint32_t distance_measure(){
	uint32_t time_stop =0;
	while (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == RESET)
	{
		asm("NOP");// waiting of pulse rising
	};
	if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == SET)
	{
		clean_tick(); // register zeroing
	}
	while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == SET)
	{
		asm("NOP");// waiting of pulse falling
	}
	if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == RESET)
	{
		time_stop = Get_uS(); // delay measuring
	}
	uint32_t distance = time_stop/58; // convert time to cm
	return distance;
}
