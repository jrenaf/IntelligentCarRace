/*
 * batterymeter.h
 *
 *  Created on: Jun 3, 2018
 *      Author: ZeonTuring
 */

#pragma once
#include <libbase/adc.h>

class BatteryMeter
{
public:
	BatteryMeter():adc(new libbase::Adc(libbase::Pin::Name::kPtc3,libbase::Adc::Bit::k8)){}

	float GetVoltage(){return adc->FetchOnceF()*2+0.3;}

private:
	libbase::Adc* adc = nullptr;
};
