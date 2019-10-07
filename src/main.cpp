/*
 * main.cpp
 *
 *  Created on: Feb 27, 2018
 *      Author: ZeonTuring
 */

#include <config.h>
#include <function.h>
#include <functions.cpp>
#include <lcdmenu.h>
#include <motor.h>
#include <SG90.h>


using libcreate::Motor;

int main()
{


	SystemInit();
	Systick::Init();
	get_clk();
	// 11 14 14 13 11 10 / 106 121 123 114 118 98 / 9 11 11 11 9 9
	//adc0 = new Adc(libbase::Pin::Name::kPta6,Adc::Bit::k8);//a7
	//adc1 = new Adc(libbase::Pin::Name::kPta7,Adc::Bit::k8);//a6
	adc2 = new Adc(libbase::Pin::Name::kPtf4,Adc::Bit::k8);
	adc3 = new Adc(libbase::Pin::Name::kPtf5,Adc::Bit::k8);
	adc4 = new Adc(libbase::Pin::Name::kPtf6,Adc::Bit::k8);
	adc5 = new Adc(libbase::Pin::Name::kPtf7,Adc::Bit::k8);
	//flash = new Flash();
	//initialize
	state = carState_::straight;
	servo = new SG90();// servo->SetAngle(0); SystemPause(2000);servo->SetAngle(45); SystemPause(2000);servo->SetAngle(90); SystemPause(2000);servo->SetAngle(135); SystemPause(2000);servo->SetAngle(180); SystemPause(2000);
	motor = new Motor();
	stop = new Gpi(libbase::Pin::Name::kPtd4);
	motorPWR = new Gpo(libbase::Pin::Name::kPti4,0);
	led0 = new Gpo(libbase::Pin::Name::kPth6,1);
	led1 = new Gpo(libbase::Pin::Name::kPth5,1);
	voltage = new BatteryMeter();
	lcd = new Sh1106(I2cMaster::Name::kI2C0,900000,true);
	lcd->ClrScr();

	//LcdInit(page);
	joystick = new Joystick(lcd,GetJoystickConfig());
	bluetooth = new UartDevice(GetBTConfig());
	LcdMenu menu;
	dif_sum=0;
	char str[30];
	led1->Set(1);
	uint32_t previoustime=Systick::GetTime()+1100;
	led0->Set(0);
	uint32_t vtime = Systick::GetTime()+100000;
	uint8_t counter=0;
	while (voltage->GetVoltage() > 4.2&&counter<59)
		{
		counter++;
		if(vtime <= Systick::GetTime())
		{
		lcd->Clear(0,0,10);
		sprintf(str,"voltage: %f",voltage->GetVoltage());
		lcd->WriteString(str);
		vtime = Systick::GetTime() + 100000;
		}
		}
	motorPWR->Set(1);
	//motor->SetSPD(1000);
	led0->Set(1);
	//led1->Set(0);
	while(programRun)

	{
		i++;
//		if(test_mode){
//			led1->Set(1);
//			TestMode(previoustime);
//		}
//		else
		if (Systick::GetTime() >= previoustime && manual == false)
		{
			previoustime = Systick::GetTime()+1100;
			if(loop==true){
					if(curl<=-curlout){
						curl+=1;
						directstraight=true;
					}
			}
			if(temp>=1&&temp<200){
				temp++;
				if(temp>=150){
					temp=0;
				}
			   directstraight=true;
			}
			MainAlgo(previoustime);
		}

		//page=true;

		if(page){
/*
			lcd->Clear(0,0,10);
			sprintf(str," %.1f", a0Comp*adc2->FetchOnce());
			lcd->WriteString(str);

			lcd->Clear(10,0,10);
			sprintf(str," %.1f", a1Comp*adc3->FetchOnce());
			lcd->WriteString(str);

			lcd->Clear(0,1,10);
			sprintf(str," %.1f", a4Comp*adc4->FetchOnce());
			lcd->WriteString(str);

			lcd->Clear(10,1,10);
			sprintf(str," %.1f", a5Comp*adc5->FetchOnce());
			lcd->WriteString(str);
*/

//			lcd->Clear(10,0,10);
//			sprintf(str," %.1f",a4Comp*adc4->FetchOnce()+a5Comp*adc5->FetchOnce());
//			lcd->WriteString(str);
//
//			lcd->Clear(0,1,10);
//			sprintf(str,"%.1f",a0Comp*adc2->FetchOnce()+a1Comp*adc3->FetchOnce()+ a4Comp*adc4->FetchOnce()+a5Comp*adc5->FetchOnce());
//			lcd->WriteString(str);

//			lcd->Clear(10,1,10);
//			sprintf(str," %.1f",curl);
//			lcd->WriteString(str);

//
//			lcd->Clear(10,1,10);
//			sprintf(str,"adc5: %.1f", a5Comp*adc5->FetchOnce());
//			lcd->WriteString(str);

//			lcd->Clear(0,2,10);
//			sprintf(str," %f", tunePID());
//			lcd->WriteString(str);

//
//			lcd->Clear(7,1,3);
//			sprintf(str,"%.1f",voltage->GetVoltage());
//			lcd->WriteString(str);
//			lcd->Clear(7,2,8);

//			sprintf(str,"%s",[&](carState_ carState){

//				switch(carState)

//				{

//				case 0: return "turn"; break;

//				case 1: return "straight"; break;

//				case 2: return "loop"; break;

//				default: return "NA";

//				}

//			}(state));

//			lcd->WriteString(str);

//

//			//						lcd->Clear(9,3,4);

//			//						sprintf(str,"%u",adc5->FetchOnce());

//			//						lcd->WriteString(str);

		}

		if(joystick->GetState() == Joystick::State::kDown){
			motor->SetSPD(motor->GetSPD() == 1000 ? 0 : 1000);
			SystemPause(1500);
			state=carState_::straight;
			initTime=Systick::GetTime();
		}
		if (joystick->GetState() == Joystick::State::kUp){
			menu.run();
		}
	}
}

