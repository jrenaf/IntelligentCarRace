///*
// * function.cpp
// *
// *  Created on: Jun 2, 2018
// *      Author: ZeonTuring
// */
//
//#include <function.h>
//#include <config.h>
//
//void getRX(UartDevice* uart_device)
//{
//	{
//
//	}
//}
//
//UartDevice::Config GetBTConfig()
//{
//	UartDevice::Config config;
//	config.uartn = UartDevice::Name::kUart1;
//	config.baudrate = 115200u;
//	config.rx_full_listener = getRX;
//
//	config.tx_empty_listener = nullptr;//getTX;
//	return config;
//}
//
//Joystick::Config GetJoystickConfig()
//{
//	Joystick::Config config;
//	config.up = libbase::Pin::Name::kPtg3;
//	config.down = libbase::Pin::Name::kPtg1;
//	config.left = libbase::Pin::Name::kPtg2;
//	config.right = libbase::Pin::Name::kPtg0;
//	config.center = libbase::Pin::Name::kPte1;
//	return config;
//}
//
//void LcdInit(bool choice)
//{
//	lcd->ClrScr();
//	char str[21];
//	if(choice){
//	sprintf(str,"Mot: %lu Enc: %ld",motor->GetSPD(), encoder->GetCount());
//	lcd->WriteString(str);
//	sprintf(str,"Speed: %f",1.00);
//	lcd->GotoXY(0,1);
//	lcd->WriteString(str);
//	sprintf(str,"Voltage: %.1f",voltage->GetVoltage());
//	lcd->GotoXY(0,2);
//	lcd->WriteString(str);
//	}
//	else
//	{
//		sprintf(str,"ADC1: %lu ADC2: %lu",adc0->FetchOnce(),adc1->FetchOnce());
//		lcd->WriteString(str);
//
//		lcd->GotoXY(0,1);
//		sprintf(str,"ADC3: %lu ADC4: %lu",adc2->FetchOnce(),adc3->FetchOnce());
//		lcd->WriteString(str);
//
//		lcd->GotoXY(0,2);
//		sprintf(str,"ADC5 %lu ADC6: %lu",adc4->FetchOnce(),adc5->FetchOnce());
//		lcd->WriteString(str);
//
//	}
//}
//void MeanFilter(){
//
//	mag0sum -= mag0[0];
//	mag0.erase(mag0.begin());
//	mag0.emplace_back(adc0->FetchOnce());
//	mag0sum += mag0[samples - 1];
//
//	mag1sum -= mag1[0];
//	mag1.erase(mag1.begin());
//	mag1.emplace_back(adc1->FetchOnce());
//	mag1sum += mag1[samples - 1];
//
//	mag2sum -= mag2[0];
//	mag2.erase(mag2.begin());
//	mag2.emplace_back(adc2->FetchOnce());
//	mag2sum += mag2[samples - 1];
//
//	mag3sum -= mag3[0];
//	mag3.erase(mag3.begin());
//	mag3.emplace_back(adc3->FetchOnce());
//	mag3sum += mag3[samples - 1];
//
//	mag4sum -= mag4[0];
//	mag4.erase(mag4.begin());
//	mag4.emplace_back(adc4->FetchOnce());
//	mag4sum += mag4[samples - 1];
//
//	mag5sum -= mag5[0];
//	mag5.erase(mag5.begin());
//	mag5.emplace_back(adc5->FetchOnce());
//	mag5sum += mag5[samples - 1];
//
//	adc0->FetchOnce() = mag0sum/samples;
//	adc1->FetchOnce() = mag1sum/samples;
//	adc2->FetchOnce() = mag2sum/samples;
//	adc3->FetchOnce() = mag3sum/samples;
//	adc4->FetchOnce() = mag4sum/samples;
//	adc5->FetchOnce() = mag5sum/samples;
//
//}

