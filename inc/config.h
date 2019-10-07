/*
 * Config.h
 *
 *  Created on: Jun 2, 2018
 *      Author: ZeonTuring
 */

#pragma once
#include <libbase/i2c_master.h>
#include <libbase/sys_tick.h>
#include <libbase/uart_device.h>
#include <libbase/flash.h>
#include <stdio.h>
#include <cstring>
#include <libbase/gpio.h>
#include <libsc/sh1106.h>
#include <libsc/dir_encoder.h>
#include <libbase/adc.h>
#include <libbase/pin.h>
#include <cstdlib>
#include <libbase/ftm.h>
#include <libsc/joystick.h>
#include <batterymeter.h>
#include <motor.h>
#include <sg90.h>
#include <queue>
/*
 * Global objects
 */
using libbase::Adc;
using libbase::Gpo;
using libbase::Gpi;
using libbase::I2cMaster;
using libbase::Systick;
using libbase::UartDevice;
using libsc::Sh1106;
using std::string;
using libsc::DirEncoder;
using libbase::Ftm;
using libcreate::Joystick;
using libcreate::Motor;
using libbase::Flash;

extern Adc* adc0;
extern Adc* adc1;
extern Adc* adc2;
extern Adc* adc3;
extern Adc* adc4;
extern Adc* adc5;

extern BatteryMeter* voltage;

extern DirEncoder* encoder;
extern Flash* flash;

extern Motor* motor;
extern SG90* servo;

extern Gpi* stop;

extern Gpo* led0;
extern Gpo* led2;
extern Gpo* led1;
extern Gpo* motorDIR;
extern Gpo* motorPWR;

extern Joystick* joystick;

extern Sh1106* lcd;

extern UartDevice* bluetooth;

/*
 *  Global variables
 */
enum carState_ {



	straight = 0,

	loopleft,

	loopright = 2,



	carstop

};



enum loopDiameter{

	loop100=0,//(90,300)/(75,800)

	loop60,   //(75,850)

	loop50 = 2

};



extern carState_ state;

extern uint32_t interval;

extern loopDiameter loop_state;

extern float kP;

extern float kI;

extern float kD;

extern float magerrornow;

extern float magintegral;

extern float magpreviouserror;

extern float magderivative;

extern int dif_sum;

extern bool test_mode;

extern bool page;



extern std::vector<std::pair<int,int>> front;

extern std::vector<std::pair<int,int>> back;

extern bool loop;

extern bool programRun;

extern bool manual;

extern bool directstraight;



extern float errorQ[3];

extern uint8_t errorCounter;

extern uint32_t initTime;

extern float curl;

extern int temp;

extern int i;


extern float a0Comp;

extern float a1Comp;

extern float a2Comp;

extern float a3Comp;

extern float a4Comp;

extern float a5Comp;



extern uint8_t readingFL;

extern uint8_t readingFR;

extern uint8_t readingBL;

extern uint8_t readingBR;



extern uint16_t f50sum;

extern uint16_t b50sum;

extern int dif50;

extern uint16_t f60sum;

extern uint16_t b60sum;

extern int dif60;

extern uint16_t f100sum;

extern uint16_t b100sum;

extern int dif100;

extern uint16_t foutloop;

extern uint16_t boutloop;

extern uint16_t sum50;

extern uint16_t sum60;

extern uint16_t sum100;

extern uint8_t outloopsum;
extern uint8_t outloopback;
extern uint8_t inloopsum;
extern uint8_t inloopback;
extern int curlin;
extern int curlout;
extern int curlinterim;
