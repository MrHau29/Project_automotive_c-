#pragma once
#include<iostream>
#include<string>
#include<regex>
#include<iomanip>
#include "CommonInfo.h"
#include"Display.h"
#include"General.h"
#include"Sound.h"
using namespace std;
class Car :public Display ,public Sound, public General
{
private:
	string carName;
	string email;
	string personalkey;
	int odo;
	int serviceRemind;

public:
	string getCarName();
	string getEmail();

	string getPersonalKey();
	int getOdo();
	int getServiceRemind();

	void setCarName(string name);
	void setEmail(string Email);
	void setPersonalKey(string key);
	void set_odo(int ODO);
	void setServiceRemind(int km);


	void input_info_car();
	void print_info_car();

	Car();
	~Car();
};