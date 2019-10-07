/*
 * lcdmenu.h
 *
 *  Created on: Jun 2, 2018
 *      Author: ZeonTuring
 */

#pragma once
#include <config.h>

class LcdMenu
{
public :
	LcdMenu():exit(false),inverse(0),state(Joystick::State::kIdle),data{outloopsum,outloopback,inloopsum},data2{curlin,curlout,curlinterim}{}
	void run();
private:
	//void PrintP1();
//	void TuneLoopCondition();
//	void TuneLoopCondition1(uint8_t inverse);
	//void PrintM1P2();
	//void CheckInput(uint8_t inverse);
	void Tune(uint8_t position,bool increase);
	void SaveSetting();
	//inline void LoadDefault(){kP = 0; kI = 0; kD = 0; pid[0] = kP; pid[1] = kI; pid[2] = kD;}

	bool exit;
	uint8_t inverse;
	//uint8_t page;
	Joystick::State state;
	char str[21];
	uint8_t data[3];
	int data2[3];
};
