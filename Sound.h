#pragma once
#include"CommonInfo.h"
//khai bao lopcin Sound ke thua tu lop cha Setting
class Sound 
{
private:
	int media_level;
	int call_level;
	int navigation_level;
	int notification_level;
public:
	Sound();
	~Sound();
	void input_Sound();
	void print_Sound();

	int get_media_level();
	int get_call_level();
	int get_navigation_level();
	int get_notification_level();

	void set_media_level(int media);
	void set_call_level(int call);
	void set_navigation_level(int navigation);
	void set_notification_level(int notification);
};

