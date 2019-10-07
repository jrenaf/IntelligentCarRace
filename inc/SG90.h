/*

 * SG90.h
 *
 *  Created on: Jun 24, 2018
 *      Author: ZeonTuring
 */

#pragma once
#include <cassert>
#include <config.h>
using libbase::Ftm;
//#include <libbase/ftm.h>
//using libbase::Ftm;

class SG90
{
public:
	SG90():pwm(new Ftm(Ftm::Name::kFTM2,Ftm::EXT_CLK::kDisable,nullptr))
	{
		pwm->InitOutput(Ftm::CHANNEL::kCh1,50,60);//43-145 kCh1 102	// 22 60 110
	}

	void SetAngle(uint16_t angle)
	{
		if (angle >= 0 && angle <= 180)
			if (angle <=90)
				pwm->SetDutyCycle(Ftm::CHANNEL::kCh1,21+angle*38/90);
			else pwm->SetDutyCycle(Ftm::CHANNEL::kCh1,60+(angle-90)*48/90);
		else if(angle < 30) pwm->SetDutyCycle(Ftm::CHANNEL::kCh1,22+30*39/90);
				else pwm ->SetDutyCycle(Ftm::CHANNEL::kCh1,61+60*49/90);
	}
	uint16_t GetAngle() {
		uint16_t temp = pwm->GetDutyCycle(Ftm::CHANNEL::kCh1);
		if (temp <=61)
			return (temp-21)*90/38;
		else return (temp-60)*90/48+90;
	}
private:
	Ftm* pwm;
};
