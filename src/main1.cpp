///*
// * main.cpp
// *
// *  Created on: Feb 27, 2018
// *      Author: ZeonTuring
// */
//
//#include <config.h>
//#include <function.h>
//#include <lcdmenu.h>
//#include <motor.h>
//#include <SG90.h>
//
//using libcreate::Motor;
//
//int main()
//{
//	SystemInit();
//	Systick::Init();
//	get_clk();
//
//	adc0 = new Adc(libbase::Pin::Name::kPtc0);//a7
//	adc1 = new Adc(libbase::Pin::Name::kPtc1);//a6
//	adc2 = new Adc(libbase::Pin::Name::kPtf4,Adc::Bit::k8);
//	adc3 = new Adc(libbase::Pin::Name::kPtf5,Adc::Bit::k8);
//	adc4 = new Adc(libbase::Pin::Name::kPtf6);
//	adc5 = new Adc(libbase::Pin::Name::kPtf7,Adc::Bit::k8);
//
////	encoder = new DirEncoder(1);
//
////		motor->InitOutput(Ftm::CHANNEL::kCh1,25000,1000);//kCh0
////	servo = new Ftm(Ftm::Name::kFTM2,Ftm::EXT_CLK::kDisable,nullptr);
////	motorDIR = new Gpo(libbase::Pin::Name::kPte6,1);
//	motor = new Motor();
//	servo = new SG90();
//
////		servo->InitOutput(Ftm::CHANNEL::kCh0,50,109);	//73 to 145 kCh1
//
//	stop = new Gpi(libbase::Pin::Name::kPtd4);
//
//	led0 = new Gpo(libbase::Pin::Name::kPth6,1);
//
//	led1 = new Gpo(libbase::Pin::Name::kPth5,0);
//
////	motorPWR = new Gpo(libbase::Pin::Name::kPti4,0);
//
//
//
//	lcd = new Sh1106(I2cMaster::Name::kI2C0,900000,false);lcd->ClrScr(); LcdInit(page);
//
//	joystick = new Joystick(lcd,GetJoystickConfig());
//
//	bluetooth = new UartDevice(GetBTConfig());
//
//	LcdMenu menu;
//
//	uint32_t time;
//	uint32_t previoustime = Systick::GetTime(); //new
//	// implementation  of meanfilter, these needed to be initialized once
//	uint8_t samples = 10;
//	std::vector<uint16_t>mag0;
//	std::vector<uint16_t>mag1;
//	std::vector<uint16_t>mag2;
//	std::vector<uint16_t>mag3;
//	std::vector<uint16_t>mag4;
//	std::vector<uint16_t>mag5;
//	mag0.clear();
//	mag1.clear();
//	mag2.clear():
//	mag3.clear();
//	mag4.clear();
//	mag5.clear();
//	uint16_t mag0sum = 0;
//	uint16_t mag1sum = 0;
//	uint16_t mag2sum = 0;
//	uint16_t mag3sum = 0;
//	uint16_t mag4sum = 0;
//	uint16_t mag5sum = 0;
//	uint16_t reading0 = 0;
//	uint16_t reading1 = 0;
//	uint16_t reading2 = 0;
//	uint16_t reading3 = 0;
//	uint16_t reading4 = 0;
//	uint16_t reading5 = 0;
//	uint16_t reading6 = 0;
//
//	for (int i = 0, i < samples, i++){
//		mag0.emplace_back(0);
//		mag1.emplace_back(0);
//		mag2.emplace_back(0);
//		mag3.emplace_back(0);
//		mag4.emplace_back(0);
//		mag5.emplace_back(0);
//	}
//
//
//
//	char str[5];
//	while(1)
//	{
//		time = Systick::GetTime();
//		uint32_t dt = time - previoustime;//new
//		if (dt == 0){dt+=1;}//new
//
//		MeanFilter(); //new
//		if (dt%3 == 0){ //new
//			MainAlgo(time,previoustime);
//		}
//
//
//
//					if(page)
//					{
//
//
//					lcd->Clear(5,0,4);
//											sprintf(str,"%u",motor->GetSPD());
//											lcd->WriteString(str);
//
//								lcd->Clear(15,0,4);
//								sprintf(str,"%ld",motor->GetCount());
//								lcd->WriteString(str);
//
//								lcd->Clear(7,1,3);
//								sprintf(str,"%.1f",voltage->GetVoltage());
//								lcd->WriteString(str);
//
//								lcd->Clear(7,2,8);
//								sprintf(str,"%s",[&](carState_ carState){
//										switch(carState)
//										{
//										case 0: return "turn"; break;
//										case 1: return "straight"; break;
//										case 2: return "loop"; break;
//										default: return "NA";
//										}
//								}(state));
//								lcd->WriteString(str);
//
//		//						lcd->Clear(9,3,4);
//		//						sprintf(str,"%u",adc5->FetchOnce());
//		//						lcd->WriteString(str);
//					}
//					else
//					{
//						lcd->Clear(6,0,4);
//									sprintf(str,"%u",adc0->FetchOnce());
//									lcd->WriteString(str);
//
//						lcd->Clear(15,0,4);
//						sprintf(str,"%u",adc1->FetchOnce());
//						lcd->WriteString(str);
//
//						lcd->Clear(6,1,4);
//									sprintf(str,"%u",adc2->FetchOnce());
//									lcd->WriteString(str);
//
//						lcd->Clear(15,1,4);
//						sprintf(str,"%u",adc3->FetchOnce());
//						lcd->WriteString(str);
//
//						lcd->Clear(6,2,4);
//									sprintf(str,"%u",adc4->FetchOnce());
//									lcd->WriteString(str);
//
//						lcd->Clear(15,2,4);
//						sprintf(str,"%u",adc5->FetchOnce());
//						lcd->WriteString(str);
//					}
//
//
//		if (joystick->GetState() == Joystick::State::kUp || joystick->GetState() == Joystick::State::kDown)
//		{
//			led1->Turn();
//			page = !page;
//			SystemPause(300);
//		}
//
//		if (joystick->GetState() == Joystick::State::kCenter)
//		{
//			led1->Turn();
//			menu.run();
//		}
//
//
//	}
//}
