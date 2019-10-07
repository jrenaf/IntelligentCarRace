/*
 * Config.cpp
 *
 *  Created on: Jun 2, 2018
 *      Author: ZeonTuring
 */

#include "config.h"
/*
 * Global objects
 */
Adc* adc0 = nullptr;
Adc* adc1 = nullptr;
Adc* adc2 = nullptr;
Adc* adc3 = nullptr;
Adc* adc4 = nullptr;
Adc* adc5 = nullptr;

BatteryMeter* voltage = nullptr;

DirEncoder* encoder = nullptr;

Motor* motor = nullptr;
SG90* servo = nullptr;

Gpi* stop = nullptr;

Gpo* led0 = nullptr;
Gpo* led1 = nullptr;
Gpo* motorDIR = nullptr;
Gpo* motorPWR = nullptr;

Joystick* joystick = nullptr;

Sh1106* lcd = nullptr;

UartDevice* bluetooth = nullptr;

/*
 * Global variables
 */
float kP = 0.062;//0.069;//0.072;//0.06// 0.048;//0.13

float kI = 0;

float kD = 0.58;//0.655;//0.82;//0.35//0.032;//0.8`

carState_ state = carState_::straight;

uint32_t interval = 5000;

int dif_sum=0;

float magerrornow = 0;

float magintegral = 0;wireless

float magpreviouserror = 0;

float magderivative = 0;

bool test_mode=false;

bool page = true;

loopDiameter loop_state=loopDiameter::loop100;

bool loop=false;

bool programRun = true;

bool manual = false;

int i=0;

bool directstraight=false;

float errorQ[3]={0,0,0};

uint8_t errorCounter=0;

uint32_t initTime=0;

float curl=0;

int temp=0;



float a0Comp=0.89286;

float a1Comp=1.13636;

float a2Comp=1;

float a3Comp=1;

float a4Comp=1.5;

float a5Comp=1;



uint8_t readingFL=0;

uint8_t readingFR=0;

uint8_t readingBL=0;

uint8_t readingBR=0;



uint16_t f50sum=1000;

uint16_t b50sum=1000;

int dif50=-10;

uint16_t f60sum=1000;

uint16_t b60sum=1000;

int dif60=-1;

uint16_t f100sum=1000;

uint16_t b100sum=1000;

int dif100=-5;

uint16_t foutloop=550;

uint16_t boutloop=0;

uint16_t sum50=600;

uint16_t sum60=500;

uint16_t sum100=700;

uint8_t outloopsum=170;//+-1
uint8_t outloopback=90;//+-1
uint8_t inloopsum=180;//+-1
//uint8_t inloopback=0;
int curlin=-600;//+-10
int curlout=-350;//+-10
int curlinterim=1;//+-0.2
