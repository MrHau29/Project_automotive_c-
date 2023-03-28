#include "General.h"
void General::Input_general(General& a, General& b)
{
	
	timeZone = a.get_timeZone();
	language = b.get_language();
}

void General::print_general() {
	
	cout << setw(20) << "timeZone" << setw(20) << "language" << endl;
	cout << setw(20) << timeZone << setw(20) << language << endl;
	cout << endl;
}

string General::get_language() {
	return language;
}


string General::get_timeZone() {
	return timeZone;
}

void General::set_timeZone(string data) {
	timeZone = data;

}
void General::set_language(string data) {
	language = data;

}
General::General() {
	language = "English";
	timeZone = "GMT-00-00";
};

General::~General() {
}
