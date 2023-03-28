
#pragma once
#include"Car.h"
#include"CommonInfo.h"
#include"ControlSystem.h"
#include"Display.h"
#include"Sound.h"
#include"General.h"
#include"tree.h"
#include<fstream>
#include<Windows.h>
#include<vector>
#include<set>
vector<CommonInfo> timezoneList;
vector<CommonInfo> languageList;
Tree* root = new Tree;

//Các biên count này để đếm số đối tượng trong các mảng 




/*			SETTING DISPLAY				*/
void setting_Display() {
	Car* car = new Car;
	
	car->input_info_car();

	bool isExisted = false; // giả sử khoá key chưa tồn tại mặc định là false;
	isExisted = root->search(car->getPersonalKey());
	if (isExisted) {
		Car display;
		string continues;
		system("cls");
		cout << "---> Xe " << root->car_count << " da ton tai!Thong tin xe se duoc ghi de!" << endl;
		cin.ignore();
		car->input_Display();
		root->overRide(car);
		while (!ValidateInput(continues, VALIDATE_INPUT_YES_NO)) {
			system("cls");
			cout << "TIEP TUC GHI  XE SO " << root->car_count +1 << " ? (y/n): ";
			getline(cin, continues);
			if (continues == "y" || continues == "Y") { // Nếu người dùng chọn Y thi tiếp tục nhập
				setting_Display();
			}
		}
	}
	else {
		cout << "----> Day la xe moi! Thong tin cai dat se duoc them vao danh sach" << endl;
		car->input_Display();
		root->insert(car);
		string continues;
		while (!ValidateInput(continues, VALIDATE_INPUT_YES_NO)) {
			system("cls");
			cout << "TIEP TUC GHI  XE SO " << root->car_count + 1 << " ? (y/n): ";
			getline(cin, continues);
			if (continues == "y" || continues == "Y") { // Nếu người dùng chọn Y thi tiếp tục nhập
				setting_Display();
			}
		}
	}

}



void setting_Sound() {
	Car* car = new Car;
	
	car->input_info_car();
	bool isExisited = false;
	isExisited = root->search(car->getPersonalKey());

	if (isExisited) {
		string continues;
		system("cls");
		cout << "---> Xe " << root->car_count << " da ton tai!Thong tin xe se duoc ghi de!" << endl;
		cin.ignore();
		car->input_Sound();
		root->overRide(car);

		while (!ValidateInput(continues, VALIDATE_INPUT_YES_NO)) {
			system("cls");
			cout << "TIEP TUC GHI XE SO " << root->car_count +1<< " ? (y/n): ";
			getline(cin, continues);
			if (continues == "y" || continues == "Y") { // Nếu người dùng chọn Y thi tiếp tục nhập
				setting_Sound();
			}
		}
	}
	else {
		cout << "----> Day la xe moi! Thong tin cai dat se duoc them vao danh sach" << endl;
		car->input_Sound();
		root->insert(car);
		string continues;
		while (!ValidateInput(continues, VALIDATE_INPUT_YES_NO)) {
			system("cls");
			cout << "TIEP TUC GHI DE XE SO " << root->car_count +1 << " ? (y/n): ";
			getline(cin, continues);
			if (continues == "y" || continues == "Y") { // Nếu người dùng chọn Y thi tiếp tục nhập
				setting_Sound();
			}
		}
		
	}
}



/*		NHAP THONG TIN GENERAL						*/
void setting_general() {
	Car* car = new Car; // tạo đối tượng car

	car->input_info_car();// nhập thông tin cho newSetting
	bool isExisited = root->search(car->getPersonalKey()); // tim key trung lap trong tree
	if (isExisited) { // neu tim thay thi ghi de du lieu moi vao v tri tim thay
		string continues;
		cout << "---> Xe " << root->car_count << " da ton tai!Thong tin xe se duoc ghi de!" << endl;
		INPUT_TIME_LANGUGE(car);
		root->overRide(car);

		while (!ValidateInput(continues, VALIDATE_INPUT_YES_NO)) {
			system("cls");
			cout << "TIEP TUC GHI XE SO " << root->car_count +1 << " ? (y/n): ";
			getline(cin, continues);
			if (continues == "y" || continues == "Y") {
				setting_general();
			}
		}
	}
	else {
		cout << "----> Day la xe moi! Thong tin cai dat se duoc them vao danh sach" << endl;
		// SETTING TIME
		INPUT_TIME_LANGUGE(car);
		root->insert(car);
		string continues;
		while (!ValidateInput(continues, VALIDATE_INPUT_YES_NO)) {
			system("cls");
			cout << "TIEP TUC GHI XE SO " << root->car_count + 1 << " ? (y/n): ";
			getline(cin, continues);
			if (continues == "y" || continues == "Y") {
				setting_general();
			}
		}

	}
}




const vector<string> explode(const string& s, const char& c)
{
	string buff{ "" };
	vector<string> v;

	for (auto n : s)
	{
		if (n != c)
			buff += n;
		else if (n == c && buff != "")
		{
			v.push_back(buff);
			buff = "";
		}
	}
	if (buff != "")
		v.push_back(buff);

	return v;
}

/* ############ HÀM TÁCH CHỮ TỪ 1 CHUỖI  ############## */
const vector<string> explode_in_file(const string& s)
{
	vector<string> res;
	string buff{ "" };
	vector<string> v;
	for (auto n : s)
	{
		if (n != ',' && n != ';' && n != ':')	//Ghi các giá trị không phải dấu , ;  vào buff .e.g Common: NAME // EMAIL // ODO 
			buff += n;
		else if ((n == ',' || n == ';' || n == ':') && buff != "")	//Nếu gặp phải các kí tự này thì ghi biến buff vào vector và reset biến buff để ghi dữ liệu mới
		{
			v.push_back(buff);
			buff = "";
		}
	}
	if (buff != "")	//Ghi những giá trị sau dấu phẩy cuối cùng vào vector
		v.push_back(buff);

	//LỌC MẢNG LẠI
	while (!v.empty()) {
		string a = v.back();	//Kiểm tra từng phần tử của mảng v sau khi tách các chuỗi ra
		if (a != "Common" && a != "Display" && a != "Sound" && a != "General") {	//Lấy các giá trị ngoài trừ ~ giá trị này
			res.push_back(a);
		}
		v.pop_back();
	}
	reverse(res.begin(), res.end());	//Vì khi lấy giá trị của vector là từ cuối lên đầu nên phải reverse lại vector res
	return res;
}



/*				Ghi thông tin ra file				*/
void writeDataToLocal() {
	root->write_to_file();
}


/*					ĐỌC THÔNG TIN TỪ FILE			*/

void load_File() {
	vector<string> user;
	ifstream file("Setting.txt");
	try
	{
		if (file.is_open()) {
			if (file.peek() == ifstream::traits_type::eof()) {	//Kiểm tra xem file Setting.txt có empty hay không
				cout << "\nNO DATA TO READ..." << endl;
				Sleep(2000);
				return;
			}
			else {
				cout << "\nSAVING DATA TO STORAGE..." << endl;
				Sleep(2000);
			}
			string data;
			while (getline(file, data)) {
				Car* listCar = new Car;
				
				user = explode_in_file(data);

				//CommonInfo information
				listCar->setCarName(user[0]);
				listCar->setEmail(user[1]);
				listCar->setPersonalKey(user[2]);
				listCar->set_odo(stoi(user[3]));
				listCar->setServiceRemind(stoi(user[4]));
				
				 //Display Information
				listCar->set_light_level(stoi(user[5]));
				listCar->set_screen_light_level(stoi(user[6]));
				listCar->set_taplo_light_level(stoi(user[7]));

				//Sound information
				listCar->set_media_level(stoi(user[8]));
				listCar->set_call_level(stoi(user[9]));
				listCar->set_navigation_level(stoi(user[10]));
				listCar->set_notification_level(stoi(user[11]));

				// General information
				listCar->set_timeZone(user[12]);
				listCar->set_language(user[13]);
				root->insert(listCar);

			}
			
		}
		else {
			throw "Open file fail";
		}
	}
	catch (const char* e)
	{
		cout << e << endl;
		file.close();
	}
	//Xóa nội dung file sau khi đọc để ghi dữ liệu mới vào
	ofstream file1("Setting.txt", ios::trunc);
	try {
		if (!file1.is_open()) {
			throw "Open file fail";
		}
		else {
			file1 << "";
		}
	}
	catch (exception& e) {
		cout << e.what() << endl;
		file1.close();
	}
}



/*		LOAD FILE TIME.TXT */

void downloadTimeZone() {
	ifstream read1("timezones.txt");
	string str_time;
	try {
		if (read1.is_open()) {
			while (read1.eof() == false) {
				getline(read1, str_time);
				vector<string> tmp = explode(str_time, '/');
				set<string> sp(tmp.begin(), tmp.end());
				vector<string> data(sp.begin(), sp.end());
				CommonInfo Common;
				if (data.size() >= 2) {
					Common.setNumber(data[1]);
					Common.setName(data[0]);
				}
				timezoneList.push_back(Common);

			}read1.close();
			/*sort(timezoneList.begin(), timezoneList.end(), [](CommonInfo& s1, CommonInfo& s2) {
				return s1.getNumber() < s2.getNumber();
				});*/
		}
		else throw "FAIL TO OPEN FILE";
	}
	catch (const char* e) {
		cout << e << endl;
		read1.close();
	}

}

// ad
//vector<Car> ds_car;
//vector<Car> AddToArray(Node* tree, vector<Car> arr) {
//	
//	if (tree == NULL) return arr;
//	if (tree->left != NULL) arr = AddToArray(tree->left, arr);
//
//	arr.push_back(tree->car);
//
//	if (tree->right != NULL) arr = AddToArray(tree->right, arr);
//	return arr;
//}




/*		LOAD FILE LANGUAGE.TXT			*/
void downloadLanguage() {
	ifstream f;
	f.open("languages.txt");
	string str_language;
	try {
		if (f.is_open()) {
			while (f.eof() == false) { // doc den cuoi file
				getline(f, str_language); //nhap dl vao str_languae
				vector<string> data = explode(str_language, '/');
				CommonInfo Common;
				if (data.size() >= 2) {
					Common.setNumber(data[0]);
					Common.setName(data[1]);
				}
				languageList.push_back(Common);

			}
		}
		else {
			throw "FAIL TO OPEN FILE";
		}
	}
	catch (const char* e) {
		cout << e << endl;
		f.close();
	}
	sort(languageList.begin(), languageList.end(), [](CommonInfo& s1, CommonInfo& s2) {
		return s1.getName() < s2.getName();
		});

}
/*			MENU LANGUAGE					*/

void menu_language() {
	for (int i = 0; i < languageList.size(); i++) {
		languageList[i].printLang(i);
	}
}

/*			MENU TIME					*/
void menu_time() {
	for (int i = 0; i < timezoneList.size(); i++) {
		timezoneList[i].printTime(i);
	}
}


/*			NHAP THONG TIN LANGUAGE VA TIME					*/
void INPUT_TIME_LANGUGE(General *g) {

	string input_time, input_langue;
	do
	{
		do {
			system("cls");
			cout << "--- SELECT TIMEZONE DATA ---" << endl;
			menu_time();
			cout << "Ban chon: ";
			getline(cin, input_time);

		} while (!ValidateInput(input_time, VALIDATE_INPUT_SCREEN));

	} while (stoi(input_time) > 31);
	g->set_timeZone(timezoneList[stoi(input_time)].getNumber());

	//SETTING LANGUAGE
	do
	{
		do {
			system("cls");
			cout << "--- SELECT LANGUAGE DATA ---" << endl;
			menu_language();// hiển thị menu ngôn ngữ
			cout << "Ban chon: ";
			getline(cin,input_langue);
		} while (!ValidateInput(input_langue, VALIDATE_INPUT_SCREEN));

	} while (stoi(input_langue) > 29);
	g->set_language(languageList[stoi(input_langue)].getName());
}
//

/*		PRINT  DISPLAY					*/
void print_Display_Setting() {
	system("cls");
	cout << " ---  Print  Display --- " << endl;
	root->print_Display();
};

/*		PRINT  SOUND					*/
void print_Sound_setting() {
		system("cls");
		cout << " ---  Print  Sound --- " << endl;
		root->print_Sound();
		cout << endl;
};

/*		PRINT GENERAL				*/
void print_Genera_setting() {
	system("cls");
	cout << " ---  Print  General --- " << endl;
	root->print_General();
	cout << endl;
}

/*		PRINT ALL SETTING	*/
void print_all_setting() {
	system("cls");

	root->print_ALL_setting();
	cout << endl;
}


void start() {
	cout << setw(25) << " =========================================" << endl;
	cout << setw(25) << " |         ==*== HELLO ==*==             |" << endl;
	cout << setw(25) << " =========================================" << endl;
	cout << endl;
	cout << "CHECKING DATA FROM STORAGE..." << endl;
	cout << endl;
	cout << "LOADING";
	cout << endl;
	Sleep(500);
	cout << endl;
	cout << "SUCCESSFULLY..." << endl;
	load_File();
	cout << "\nLOADING MAIN SCREEN..." << endl;
	Sleep(500);
	menu();
}



/*				MENU LUA CHON THONG TIN MUON CAI DAT			*/
void input_infomation() {
	string input;
	do
	{	// nhập số nguyên từ 1 - 4
		
		system("cls");
		cout << " -*-*-*-*- SELECT OPTION -*-*-*- " << endl;
		cout << " --- 1. Display Setting  --- " << endl;
		cout << " --- 2. Sound Setting    --- " << endl;
		cout << " --- 3. General Setting  --- " << endl;
		cout << " --- 4. Back --- " << endl;
		getline(cin, input);
	} while (!ValidateInput(input, VALIDATE_INPUT_SCREEN));
	int key = stoi(input);
	switch (key)
	{
	case 1: {
		system("cls");
		cout << " --- Nhap Thong Tin Display --- " << endl;
		setting_Display();
		break;
	}
	case 2: {
		system("cls");
		cout << " --- Nhap Thong Tin Sound --- " << endl;
	
		setting_Sound();
		break;
	}
	case 3: {
		system("cls");
		cout << " --- Nhap Thong Tin General --- " << endl;

		setting_general();
		break;
	}
	case 4: {
		cout << " --- Back --- " << endl;
		menu();
	}
	default: {
		cout << "NOT MATCHED ANY KEY" << endl;
		cout << "Close SYSTEM" << endl;
		system("Pause");
		exit(0);
	}
	}

}

/*				MENU XUAT THONG TIN  CAI DAT			*/
void Print_info_seeting() {

	string selection;
	do
	{
		system("cls");
		cout << " --- 1. Print Thong Tin Display --- " << endl;
		cout << " --- 2. Print Thong Tin Sound   --- " << endl;
		cout << " --- 3. Print Thong Tin General --- " << endl;
		cout << " --- 4. Print All thong tin     --- " << endl;
		cout << " --- 5. WRITE TO FILE     --- " << endl;
		cout << " --- 6. Back     --- " << endl;
		getline(cin, selection);
	} while (!ValidateInput(selection, VALIDATE_INPUT_SCREEN));
	int key = stoi(selection);
	switch (key) {
	case 1: {
		cout << "Ban chon : " << key << endl;
		cout << " --- Print Thong Tin Display --- " << endl;
		
		print_Display_Setting();
		system("pause");
		break;
	}
	case 2: {
		cout << "Ban Chon : " << key << endl;
		cout << " --- Print Thong Tin Sound --- " << endl;
		print_Sound_setting();
		system("pause");
		break;
	}
	case 3: {
		cout << "Ban Chon : " << key << endl;
		cout << " --- Print thong tin General --- " << endl;
		print_Genera_setting();
		system("pause");
		break;
	}
	case 4: {
		cout << "Ban Chon : " << key << endl;
		cout << " --- Print All Thong Tin --- " << endl;
		print_all_setting();
		system("pause");
		break;

	}case 5: {
		cout << "Ban Chon : " << key << endl;
		cout << " --- 5. WRITE TO FILE     --- " << endl;
		writeDataToLocal();
		system("pause");
		break;
	}
	case 6:
	{
		cout << "Ban Chon : " << key << endl;
		cout << " --- BACK --- " << endl;
		menu();
		system("pause");
		break;
	}
	default : {
		cout << "NOT MATCHED ANY KEY" << endl;
		cout << "Close SYSTEM" << endl;
		system("Pause");
		exit(0);
	}

	}
};




/*					MEUNU SELECT OPTION					*/
void menu() {
	string set;
	while (1) {
		do
		{
			system("cls");
			cout << " *-*-*-*-*-*-*- SELECT MENU *-*-*-*-*-*-* " << endl;
			cout << " --- 1. Input Setting Information  --- " << endl;
			cout << " --- 2. Print Setting Information  --- " << endl;
			cout << " --- 3. -----   Exit  ----- " << endl;
			cout << "Ban chon: "; getline(cin, set);

			system("cls");
		} while (!ValidateInput(set, VALIDATE_INPUT_SCREEN));
		int key = stoi(set);
		switch (key)
		{
		case 1: {
			cout << " -*-*-*-*- SELECT OPTION -*-*-*- " << endl;
			cout << " --- 1. Display Setting  --- " << endl;
			cout << " --- 2. Sound Setting    --- " << endl;
			cout << " --- 3. General Setting  --- " << endl;
			cout << " --- 4. Back --- " << endl;
			input_infomation();
			break;
		}
		case 2: {
			cout << " --- 1. Print Thong Tin Display --- " << endl;
			cout << " --- 2. Print Thong Tin Sound   --- " << endl;
			cout << " --- 3. Print Thong Tin General --- " << endl;
			cout << " --- 4. Print All thong tin     --- " << endl;
			cout << " --- 5. WRITE TO FILE     --- " << endl;
			cout << " --- 6. Back     --- " << endl;
			Print_info_seeting();
			break;
		}
		case 3: {
			cout << setw(25) << " =========================================" << endl;
			cout << setw(25) << " |         ==*== GooD ByE ==*==          |" << endl;
			cout << setw(25) << " =========================================" << endl;
			system("pause");
			exit(0);
		}
		default: {
			cout << "NOT MATCHED ANY KEY" << endl;
			cout << "Close SYSTEM" << endl;
			system("Pause");
			exit(0);
		}

		}
	}
}