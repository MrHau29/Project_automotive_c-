#include "Display.h"

void Display::input_Display() {
	
	string light_level_tm, screen_light_level_tm, taplo_light_level_tm;
	/*			ENTER LIGHT LEVEL       */
	cout << "LIGHT LEVEL: ";
	getline(cin, light_level_tm);
	cin.clear();
	while (!ValidateInput(light_level_tm, VALIDATE_INPUT_DISPLAY_SOUND)) {
		system("cls");
		cout << "LIGHT LEVEL: ";
		getline(cin, light_level_tm);
		cin.clear();
	}
	light_level = stoi(light_level_tm);

	/*			ENTER SCREEN LEVEL       */
	cout << "SCREEN LIGHT LEVEL: ";
	getline(cin, screen_light_level_tm);
	cin.clear();
	while (!ValidateInput(screen_light_level_tm, VALIDATE_INPUT_DISPLAY_SOUND)) {
		system("cls");
		cout << "LIGHT LEVEL: ";
		getline(cin, screen_light_level_tm);
		cin.clear();
	}
	screen_light_level = stoi(screen_light_level_tm);


	/*			ENTER TAPLO LIGHT LEVEL       */
	cout << "TAPLO LIGHT LEVEL: ";
	getline(cin, taplo_light_level_tm);
	cin.clear();
	while (!ValidateInput(taplo_light_level_tm, VALIDATE_INPUT_DISPLAY_SOUND))
	{
		system("cls");
		cout << "TAPLO LIGHT LEVEL : ";
		getline(cin, taplo_light_level_tm);
		cin.clear();
	}taplo_light_level = stoi(taplo_light_level_tm);
}

//phuong thuc xuat thong tin
void Display::print_Display() {
	
	cout << setw(20) << left << "LIGHT LEVEL" << setw(20) << left << "SCREEN LIGHT LEVEL";
	cout << setw(20) << left << "TAPLO LIGHT LEVEL" << endl;
	cout << setw(20) << left << light_level << setw(20) << left << screen_light_level;
	cout << setw(20) << left << taplo_light_level << endl;
	cout << endl;
}

// vì light_level là private nên phải sd get để lấy thônn tin 
int Display::get_light_level() {
	return light_level;
}
// set giá trị cho lighLevevl
void Display::set_light_level(int lightLevel) {
	light_level = lightLevel;
}

int Display::get_screen_light_level() {
	return screen_light_level;
};

void Display::set_screen_light_level(int screen_lightLevel) {
	screen_light_level = screen_lightLevel;
}

int Display::get_taplo_light_level() {
	return taplo_light_level;
}

void Display::set_taplo_light_level(int taplo_lightLevel) {
	taplo_light_level = taplo_lightLevel;
}
// khơi tạo mặc định
Display::Display() {
	light_level = 0;
	screen_light_level = 0;
	taplo_light_level = 0;
};
Display::~Display() {};