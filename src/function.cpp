/*
 * function.cpp
 *
 *  Created on: Jun 2, 2018
 *      Author: ZeonTuring
 */

#include <function.h>
#include <lcdmenu.h>
#include <config.h>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>

string inputStr;  //global
bool tune = false;  //global
std::vector<double> constVector;  //global

std::vector<std::pair<int,int>> front;

std::vector<std::pair<int,int>> back;

void getRX(UartDevice* uart)
{

		char data = bluetooth->GetByte();
		if(manual)
		{
			if (data == 'w') motor->SetSPD(400);
			if (data == 's') motor->SetSPD(0);
			if (data == 'a') servo->SetAngle(servo->GetAngle() - (servo->GetAngle() <= 10 ? 0 : 10));
			if (data == 'd') servo->SetAngle(servo->GetAngle() + (servo->GetAngle() >=170 ? 0 : 10));

			if (data == 'e') manual = !manual;
		}
		else
		{
		if (data == 'e') manual = !manual;

		if (data == '/') {motor->SetSPD(motor->GetSPD() == 1000 ? 0 : 1000);}

		if (data == 't') {
			programRun = 1;
			tune = 1;
			inputStr = "";
		}
		if (tune) {
			if (data != 't' && data != '\n') {
				inputStr += data;
			} else if (data == '\n') {
				tune = 0;
			}
			if (!tune) {
				constVector.clear();
				char * pch;
				pch = strtok(&inputStr[0], ",");
				while (pch != NULL){
					float constant;
					constant = strtof(pch, NULL);
					constVector.push_back(constant);
					pch = strtok (NULL, ",");
				}
				f50sum = constVector[0];
				b50sum = constVector[1];
				dif50 = constVector[2];
				f60sum = constVector[3];
				b60sum = constVector[4];
				dif60 = constVector[5];
				f100sum = constVector[6];
				b100sum = constVector[7];
				dif100 = constVector[8];
				foutloop = constVector[9];
				boutloop = constVector[10];
				sum50 = constVector[11];
				sum60 = constVector[12];
				sum100 = constVector[13];

	//			leftSpeedErrSum = 0;
	//			rightSpeedErrSum = 0;
			}
		}
		}
}

UartDevice::Config GetBTConfig()
{
	UartDevice::Config config;
	config.uartn = UartDevice::Name::kUart0;
	config.baudrate = 9600u;
	config.rx_full_listener = getRX;

	config.tx_empty_listener = nullptr;//getTX;//getTX;
	return config;
}

Joystick::Config GetJoystickConfig()
{
	Joystick::Config config;
	config.up = libbase::Pin::Name::kPtg3;
	config.down = libbase::Pin::Name::kPtg1;
	config.left = libbase::Pin::Name::kPtg2;
	config.right = libbase::Pin::Name::kPte1;
	config.center = libbase::Pin::Name::kPtg0;
	return config;
}
void tunePID(){
	        readingFL = adc2->FetchOnce()*a0Comp;
			readingFR = adc3->FetchOnce()*a1Comp;
			readingBL = adc4->FetchOnce()*a4Comp;
			readingBR = adc5->FetchOnce()*a5Comp;
			magerrornow = (10000.0/readingFL - 10000.0/readingFR + curl);
			errorQ[errorCounter]=magerrornow-magpreviouserror;
			magderivative=[&](float errorQ[]){
				float sum=0;
				for(int i=0;i<3;i++) sum+=errorQ[i];
				errorQ[errorCounter]=sum/3.0;
				return errorQ[errorCounter];
			}(errorQ);
			errorCounter=errorCounter==2 ? 0 : errorCounter+1;
			magpreviouserror = magerrornow;
			float magservo = kP * magerrornow + kI * magintegral + kD * magderivative;
			servo->SetAngle(90 + magservo);
}





void TestMode(uint32_t& previoustime){

	previoustime=Systick::GetTime();



	uint32_t readingSumfront =adc3->FetchOnce() + adc3->FetchOnce();

	uint32_t readingSumback = adc4->FetchOnce() + adc5->FetchOnce();

	if(front.size()<5){

		front.emplace_back(std::make_pair(readingFL,readingFR));

		back.emplace_back(std::make_pair(readingBL,readingBR));

	}

	else{

		front.erase(front.begin());

		back.erase(back.begin());

		front.emplace_back(std::make_pair(readingFL,readingFR));

		back.emplace_back(std::make_pair(readingBL,readingBR));

	}

	dif_sum=0;

	if(front.size()==5)

		dif_sum=front[4].first+front[4].second+front[3].first+front[3].second-front[1].first-front[1].second-front[0].first-front[0].second;

	uint32_t dt;

	dt = Systick::GetTime()-previoustime;

	if (dt == 0) dt = 1;

	magerrornow = (10000.0/readingFL - 10000.0/readingFR);

	magintegral += magerrornow * dt;

	magderivative = (magerrornow - magpreviouserror) / dt;

	magpreviouserror = magerrornow;

	double magservo = kP * magerrornow + kI * magintegral + kD * magderivative;

	servo->SetAngle(90 + magservo);

	if((readingSumfront > 170) && dif_sum<-10) {led1->Set(0);//loop100

	//if((readingSumfront > 200 || readingSumback > 110) && dif_sum < 0){ led1->Set(0);//loop60

	//if((readingSumfront > 220|| readingSumback > 120) && dif_sum < 10 ) {led1->Set(0);//loop50

	motor->SetSPD(0);

	}

}





void MainAlgo(uint32_t &previoustime)//, bool &loop) // idk what to put here, this one is the revised version, loopleftright have been commented
{
	if(previoustime-initTime>300000  && i%10==0&&motor->GetCount()==0){
		motor->SetSPD(0);
	}
	//bool loop = false;
	uint32_t dt;
	uint32_t readingSumfront = adc2->FetchOnce() * a0Comp + adc3->FetchOnce() * a1Comp;
	uint32_t readingSumback  = adc4->FetchOnce() * a4Comp + adc5->FetchOnce() * a5Comp;
	//dif_sum=front[4].first+front[4].second+front[3].first+front[3].second-front[1].first-front[1].second-front[0].first-front[0].second;
	if(directstraight==true){
		tunePID();
		directstraight=false;
		return;
	}
	if (stop->Get()){
		state = carState_::carstop;
	}
	else if (loop == true && ((curl>-500 and curl < 0) or (curl > 0 and curl<350)) && readingSumfront +readingSumback> outloopsum &&  adc4->FetchOnce() * a4Comp + adc5->FetchOnce() * a5Comp>outloopback){
		//led1->Set(1);
		loop = false;
		curl = 0;
		temp = 1;
		state = carState_::straight;
		servo->SetAngle(90);
		led1->Set(1);
	}
	else if (
			readingSumfront+readingSumback>inloopsum /*readingSumback > 90 && readingSumfront> 90*/ && loop == false && (adc4->FetchOnce()>45 or adc5->FetchOnce()>45)
	){
		led1->Set(0);
		loop = true;
/*

		if (a4Comp*adc4->FetchOnce()>a5Comp*adc5->FetchOnce() && (a0Comp*adc2->FetchOnce() + a4Comp*adc4->FetchOnce()) - (a1Comp*adc3->FetchOnce() + a5Comp*adc5->FetchOnce()) > 20 ){

			state=loopleft;
		}

		else if (a5Comp*adc5->FetchOnce()> a4Comp*adc4->FetchOnce() &&  (a0Comp*adc2->FetchOnce() + a4Comp*adc4->FetchOnce()) - (a1Comp*adc3->FetchOnce() + a5Comp*adc5->FetchOnce()) < -20 ){
			state = loopright;
		}

		else if (a0Comp*adc2->FetchOnce()>a1Comp*adc3->FetchOnce() && a4Comp*adc4->FetchOnce() < a5Comp*adc5->FetchOnce()){
			state = loopleft;
		}
		else if (a0Comp*adc2->FetchOnce()<a1Comp*adc3->FetchOnce() && a4Comp*adc4->FetchOnce() > a5Comp*adc5->FetchOnce()){
			state = loopright;
		}

		else {
			state = straight;
			loop = false;
		}
		*/
		led0->Set(0);
	}
	else
		state = carState_::straight;
	/*****************************************************************************************/
	if (state == carState_::carstop){
		motor->SetSPD(0);
	}
	if (state == carState_::loopleft){
		curl = curlin;//-600
		tunePID();
	}
	if (state == carState_::loopright){
		curl = 420;
		tunePID();
	}
	if (state == carState_::straight){
		tunePID();
	}
}
