#pragma once
#include"CommonInfo.h"
class General {

private:
	string timeZone;
	string language;
public:
	General();
	~General();

	void Input_general(General& a, General& b);
	void print_general();

	string get_language();
	string get_timeZone();

	void set_timeZone(string data);
	void set_language(string data);
};
