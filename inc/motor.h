/*
 * motor.h
 *
 *  Created on: Mar 1, 2018
 *      Author: ZeonTuring
 */


#pragma once
#include <config.h>
using namespace libbase;
using libsc::DirEncoder;
namespace libcreate{


class Motor
{
public:


	Motor():speed(new Ftm(Ftm::Name::kFTM2,Ftm::EXT_CLK::kDisable,nullptr)),dir(new Gpo(libbase::Pin::Name::kPte6,0)),encoder(new DirEncoder(1)),dir2(1)
	{
		speed->InitOutput(Ftm::CHANNEL::kCh0,50,1000);//kCh0
	}
	~Motor();

	void SetDIR(bool ishigh){dir->Set(ishigh); dir2 = ishigh;} // false=CW true=CCW
	void SetSPD(uint16_t pwm){if (pwm >= 0 && pwm <= 1000) speed->SetDutyCycle(Ftm::CHANNEL::kCh0,1000-pwm);}

	uint16_t GetSPD() { return 1000 - speed->GetDutyCycle(Ftm::CHANNEL::kCh0); }
	bool GetDIR() { return dir2; }
	uint16_t GetCount() { return encoder->GetCount(); }

private:
	Ftm* speed;
	Gpo* dir;
	DirEncoder* encoder;

	bool dir2;
};
}
