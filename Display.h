#pragma once
#include"CommonInfo.h"
#include<iomanip>
// khai bao lop con Display ke thua tu lop cha Car
class Display 
{
private:
	int light_level;
	int screen_light_level;
	int taplo_light_level;
public:
	Display();
	~Display();
	void input_Display();
	void print_Display();

	int get_light_level();
	int get_screen_light_level();
	int get_taplo_light_level();

	void set_light_level(int light_level);
	void set_screen_light_level(int screen_lightLevel);
	void set_taplo_light_level(int taplo_lightLevel);
};