/*
 * lcdmenu.cpp
 *
 *  Created on: Jun 2, 2018
 *      Author: ZeonTuring
 */

//#include <config.h>
#include <lcdmenu.h>
#include <function.h>

/*
 * @brief	loop condition, order, PD, mode
 *
 *
 */

//void LcdMenu::PrintP1()
//{
//	lcd->ClrScr();
////	sprintf(str,"%s Motor",[&](Motor* motor){if (motor->GetSPD() == 0) return "Start"; else return "Stop";}(motor));
//	lcd->WriteString("Loop Condition", inverse == 0 ? true : false);
//	lcd->GotoXY(0,1);
//	//sprintf(str, "kP: %f", kP);
//	lcd->WriteString("Magnetic", inverse == 1 ? true : false);
//	lcd->GotoXY(0, 2);
//	//sprintf(str, "kI: %f", kI);
//	lcd->WriteString("PD", inverse == 2 ? true : false);
//	lcd->GotoXY(0, 3);
////	sprintf(str, "kD: %f", kD);
//	lcd->WriteString("Save", inverse == 3 ? true : false);
//}
//
////void LcdMenu::PrintM1P2()
////{
////	lcd->ClrScr();
////	lcd->WriteString("Save ", inverse == 4 ? true : false);
////	lcd->GotoXY(0, 1);
////	lcd->WriteString("Load Default", inverse == 5 ? true : false);
////	lcd->GotoXY(0, 2);
////	lcd->WriteString("Exit", inverse == 6 ? true : false);
////}
//
//void LcdMenu::Tune(uint8_t choice)
//{
//	bool back = false;
//	lcd->ClrScr();
//	lcd->GotoXY(3,2);
//	switch(choice)
//	{
//	case 0:	lcd->WriteString("kP: ");break;
//	case 1:	lcd->WriteString("kI: ");break;
//	case 2:	lcd->WriteString("kD: ");break;
//
//	}
//	sprintf(str,"%f",pid[choice]);
//	lcd->WriteString(str,true);
//	SystemPause(300);
//
//	while (!back)
//	{	while (joystick->GetState() == Joystick::State::kIdle);
//	state = joystick->GetState();
//	switch(state)
//	{
//	case Joystick::State::kUp: pid[choice]+=0.1; lcd->GotoXY(7,2); lcd->WriteString("         "); lcd->GotoXY(7,2); sprintf(str,"%f",pid[choice]); lcd->WriteString(str);  break;
//	case Joystick::State::kDown: pid[choice]-=0.1; lcd->GotoXY(7,2); lcd->WriteString("         "); lcd->GotoXY(7,2); sprintf(str,"%f",pid[choice]); lcd->WriteString(str);  break;
//	case Joystick::State::kCenter: back = true; break;
//	}
//	SystemPause(200);
//	}
//}
//
//void LcdMenu::TuneLoopCondition1(uint8_t order)
//{
//	lcd->ClrScr();
//	exit = false;
//	inverse = 0;
//	char str[22];
//	lcd->GotoXY(0,0);
//	lcd->WriteString("   ,    ,");
//	while (!exit)
//	{
////	lcd->GotoXY(0,1);
////	sprintf(str,"Fsum: %lu",loopOrder[order].FrontSum,inverse == 0 ? true : false);
////	lcd->WriteString(str);
////
////	lcd->GotoXY(0, 2);
////	sprintf(str, "Rsum: %lu", loopOrder[order].RearSum,inverse == 1 ? true : false);
////	lcd->WriteString(str);
////
////	lcd->GotoXY(0, 3);
////	sprintf(str, "Dsum: %lu", loopOrder[order].DiffSum,inverse == 2 ? true : false);
//	lcd->WriteString(str);
//
//		sprintf(str,"%lu",adc0->FetchOnce() + adc1->FetchOnce());
//		lcd->GotoXY(0,0);
//		lcd->WriteString(str);
//
//		sprintf(str,"%lu",adc4->FetchOnce() + adc5->FetchOnce());
//		lcd->GotoXY(5,0);
//		lcd->WriteString(str);
//
//		sprintf(str,"%lu",adc0->FetchOnce() + adc1->FetchOnce() - adc4->FetchOnce() - adc5->FetchOnce());
//		lcd->GotoXY(10,0);
//		lcd->WriteString(str);
//
//
//	switch(joystick->GetState())
//	{
//		case Joystick::State::kUp: inverse -= inverse - 1 < 0 ? 0 : 1;break;
//		case Joystick::State::kDown: inverse += inverse + 1 > 2 ? 0 : 1;break;
////		case Joystick::State::kLeft:
////			[&](uint8_t inverse)
////			{
////				switch (inverse)
////				{
////				case 0 : loopOrder[order].FrontSum -= 1; break;
////				case 1 : loopOrder[order].RearSum -= 1; break;
////				case 2 : loopOrder[order].DiffSum -= 1; break;
////				}
////			}(inverse); break;
////		case Joystick::State::kRight:
////			[&](uint8_t inverse)
////						{
////							switch (inverse)
////							{
////							case 0 : loopOrder[order].FrontSum += 1; break;
////							case 1 : loopOrder[order].RearSum += 1; break;
////							case 2 : loopOrder[order].DiffSum += 1; break;
////							}
////						}(inverse); break;
//	}
//	}
//}
//
//void LcdMenu::TuneLoopCondition()
//{
//	lcd->ClrScr();
//	exit = false;
//	inverse = 0;
//	lcd->WriteString("loop50",inverse == 0 ? true : false);
//
//	lcd->GotoXY(0,1);
//	lcd->WriteString("loop60",inverse == 1 ? true : false);
//
//	lcd->GotoXY(0,2);
//	lcd->WriteString("loop100",inverse == 2 ? true : false);
//
//	SystemPause(300);
//	while(!exit)
//	{
//	while (joystick->GetState() == Joystick::State::kIdle);
//	state = joystick->GetState();
//	switch (state) {
//	case Joystick::State::kUp:
//		inverse -= inverse - 1 < 0 ? 0 : 1;
//		break;
//	case Joystick::State::kDown:
//		inverse += inverse + 1 > 2 ? 0 : 1;
//		break;
//	case Joystick::State::kCenter:
//		TuneLoopCondition1(inverse);
//		break;
//	case Joystick::State::kLeft:
//		exit = true;
//		break;
//	}
//	}
//
//}
//
//void LcdMenu::CheckInput(uint8_t inverse)
//{
//	switch(inverse)
//	{
//	case 0 : TuneLoopCondition(); break;
//	case 1 : Tune(0); break;
//	case 2 : Tune(1); break;
//	case 3 : Tune(2); break;
//	case 4 : SaveSetting(); break;
//	case 5 : LoadDefault(); break;
//	}
//}
//
//void LcdMenu::run()
//{
//	motor->SetSPD(0);
//
//	exit = false;
//	page = 1;
//	inverse = 0;
//
//	while (!exit)
//	{
//		PrintP1();
//
//
//		SystemPause(300);
//		while (joystick->GetState() == Joystick::State::kIdle);
//		state = joystick->GetState();
//		switch(state)
//		{
//		case Joystick::State::kUp: inverse -= inverse - 1 < 0 ? 0 : 1;  break;
//		case Joystick::State::kDown:  inverse += inverse + 1 > 2 ? 0 : 1;break;
//		case Joystick::State::kCenter: CheckInput(inverse); exit = false; break;
//		case Joystick::State::kLeft: exit = true; break;
//		}
//
//	}
//	lcd->ClrScr();
//	LcdInit(false);
//	SystemPause(300);
//}


void LcdMenu::Tune(uint8_t position,bool increase)
{
	switch(position)
	{
	case 0: outloopsum += increase == true ? 1 : -1 ; break;
	case 1: outloopback += increase == true ? 1 : -1 ; break;
	case 2: inloopsum += increase == true ? 1 : -1 ; break;
	case 3: curlin += increase == true ? 10 : -10 ; break;
	case 4: curlout += increase == true ? 10 : -10 ; break;
	case 5: curlinterim += increase == true ? 0.2 : 0.2 ; break;
	}
}

void LcdMenu::SaveSetting()
{
//	__disable_irq();

//	uint8_t * mem = new uint8_t [50];
//	memcpy(mem, &outloopsum, 4);
//	SystemPause(100);bool t2 = flash->Write(255,0,mem,4);SystemPause(100);

	flash->Write(255,0,&outloopsum,4);
	flash->Write(254,0,&outloopback,4);
	flash->Write(253,0,&inloopsum,4);
	flash->Write(252,0,(uint8_t*)&curlin,4);
	flash->Write(251,0,(uint8_t*)&curlout,4);
	flash->Write(250,0,(uint8_t*)&curlinterim,4);
//	__enable_irq();
//	lcd->ClrScr();
//	uint8_t* tempptr;
//	SystemPause(100);
//	tempptr = flash->Read(252,0,4);
//	char str[22];
//	sprintf(str,"%d",*(int*)tempptr);
//	lcd->WriteString(str);
}

void LcdMenu::run()
{
	motor->SetSPD(0);
	motorPWR->Set(0);
	char str[22];
	bool print = false;
	exit = false;
	page = 1;
	inverse = 0;
	uint32_t previoustime = Systick::GetTime()+5000;
	lcd->ClrScr();
	lcd->GotoXY(0,1);
	//sprintf(str,"L: %u R: %u",curlL,curlR);
	lcd->WriteString("OLS:     OLB:");
	lcd->GotoXY(0,2);
	//sprintf(str,"P: %.3f D: %.2f",kP,kD);
	lcd->WriteString("ILS:     Cin:");
	lcd->GotoXY(0,3);
	lcd->WriteString("Cout:     Cint:");

	lcd->Clear(5,1,3);
	sprintf(str,"%u",outloopsum);
	lcd->WriteString(str,inverse == 0 ? true : false);

	lcd->Clear(14,1,3);
	sprintf(str,"%u",outloopback);
	lcd->WriteString(str,inverse == 1 ? true : false);

	lcd->Clear(5,2,3);
	sprintf(str,"%u",inloopsum);
	lcd->WriteString(str,inverse == 2 ? true : false);

	lcd->Clear(14,2,4);
	sprintf(str,"%d",curlin);
	lcd->WriteString(str,inverse == 3 ? true : false);

	lcd->Clear(5,3,4);
	sprintf(str,"%d",curlout);
	lcd->WriteString(str,inverse == 4 ? true : false);

	lcd->Clear(15,3,3);
	sprintf(str,"%d",curlinterim);
	lcd->WriteString(str,inverse == 5 ? true : false);

	SystemPause(300);
	while (!exit)
	{
		if(previoustime<=Systick::GetTime()){
		sprintf(str,"%.1f,%.1f,%.1f,%.1f",adc2->FetchOnce()*a0Comp,adc3->FetchOnce()*a1Comp,adc4->FetchOnce()*a4Comp,adc5->FetchOnce()*a5Comp);
		lcd->Clear(0,0,20);
		lcd->WriteString(str);
		previoustime = Systick::GetTime()  + 5000;
		}
	//	PrintP1();
		if (print == true)
		{
//			switch(inverse)
//			{
//			case 0:
			lcd->Clear(5,1,3);
			sprintf(str,"%u",outloopsum);
			lcd->WriteString(str,inverse == 0 ? true : false);
//			break;
//			case 1:
			lcd->Clear(14,1,3);
			sprintf(str,"%u",outloopback);
			lcd->WriteString(str,inverse == 1 ? true : false);
//			break;
//			case 2:
			lcd->Clear(5,2,3);
			sprintf(str,"%u",inloopsum);
			lcd->WriteString(str,inverse == 2 ? true : false);

//			break;
//			case 3:
				lcd->Clear(14,2,4);
			sprintf(str,"%d",curlin);
			lcd->WriteString(str,inverse == 3 ? true : false);
//			break;
//			case 4:
			lcd->Clear(5,3,4);
			sprintf(str,"%d",curlout);
			lcd->WriteString(str,inverse == 4 ? true : false);
//			break;
//			case 5:
			lcd->Clear(15,3,3);
			sprintf(str,"%d",curlinterim);
			lcd->WriteString(str,inverse == 5 ? true : false);
			//break;
			//}
			print = false;
		}



		if (joystick->GetState() != Joystick::State::kIdle)
		{
		switch(joystick->GetState())
		{
		case Joystick::State::kUp: Tune(inverse,true); print = true; break;
		case Joystick::State::kDown:  Tune(inverse,false); print = true; break;
		case Joystick::State::kRight: inverse += inverse + 1 > 5 ? 0 : 1; print = true; break;
		case Joystick::State::kLeft: inverse -= inverse - 1 < 0 ? 0 : 1; print = true; break;
		case Joystick::State::kCenter: SaveSetting(); exit = true; break;
		}
		SystemPause(300);
		}


	}
	lcd->ClrScr();
	//LcdInit(false);
	SystemPause(300);
}


