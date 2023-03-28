
#pragma once
#include"Car.h"
#include"CommonInfo.h"
#include"Display.h"
#include"Sound.h"
#include"General.h"
#include<fstream>

#define MAX 100

const vector<string> explode(const string& s, const char& c);
const vector<string> explode_in_file(const string& s);


/*			SETTING DISPLAY,SOUND, GENREAL				*/
void setting_Display();
void setting_general();
void setting_Sound();


/*			MENU LANGUAGE, TIME					*/
void menu_language();
void menu_time();

/*		NHAP THONG TIN LANGUAGE VA TIME		*/
void INPUT_TIME_LANGUGE(General *g);



/*		PRINT  DISPLAY, SOUND, GENERAL, ALL	 SETTING	*/
void print_Display_Setting();
void print_Sound_setting();
void print_Genera_setting();
void print_all_setting();



/*				MENU LUA CHON THONG TIN MUON CAI DAT			*/
void input_infomation();

/*				MENU XUAT THONG TIN  CAI DAT			*/
void Print_info_seeting();

/*				MEUNU SELECT OPTION								*/
void menu();
void start();

/*				Ghi thông tin ra file	setting			*/
void writeDataToLocal();
/*					ĐỌC THÔNG TIN TỪ FILESETTING		*/

//void load_File();

/*		LOAD FILE TIME.TXT */
/*		LOAD FILE LANGUAGE.TXT			*/
void downloadTimeZone();
void downloadLanguage();
