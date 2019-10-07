/*
[] * function.h
 *
 *  Created on: Jun 2, 2018
 *      Author: ZeonTuring
 */

#pragma once
#include "config.h"

inline void SystemPause(uint16_t ms)
 {
	uint32_t time = Systick::GetTime() + ms * 100;
	while (time > Systick::GetTime());
}

UartDevice::Config GetBTConfig();
Joystick::Config GetJoystickConfig();

void LcdInit(bool choice);

void TestMode(uint32_t& );

void tunePID();

void MainAlgo(uint32_t&);

void MainAlgo(uint32_t &currenttime,uint32_t &previoustime);
