#include "Sound.h"

void Sound::input_Sound() {
	
	string media, call, navi, noti;
	/*	         ENTER MEDIA VOLUME         */
	cout << "Media_Level: ";
	getline(cin, media);
	cin.clear();
	while (!ValidateInput(media, VALIDATE_INPUT_DISPLAY_SOUND)) {
		system("cls");
		cout << "Media_Level: ";
		getline(cin, media);
		cin.clear();
	}
	media_level = stoi(media);

	/*	         ENTER CALL VOLUME         */
	cout << "CAll_Level: ";
	getline(cin, call);
	cin.clear();
	while (!ValidateInput(call, VALIDATE_INPUT_DISPLAY_SOUND)) {
		system("cls");
		cout << "CAll_Level: ";
		getline(cin, call);
		cin.clear();
	}
	media_level = stoi(call);

	/*	         ENTER NAVIGATION VOLUME         */

	cout << "Navigation_Level: ";
	getline(cin, navi);
	cin.clear();
	while (!ValidateInput(navi, VALIDATE_INPUT_DISPLAY_SOUND)) {
		system("cls");
		cout << "Navigation_Level: ";
		getline(cin, navi);
		cin.clear();
	}
	navigation_level = stoi(navi);

	/*	         ENTER NOTIFICATION VOLUME         */
	cout << "Notification_Level: ";
	getline(cin, noti);
	cin.clear();
	while (!ValidateInput(noti, VALIDATE_INPUT_DISPLAY_SOUND)) {
		system("cls");
		cout << "Notification_Level: ";
		getline(cin, noti);
		cin.clear();
	}
	notification_level = stoi(noti);


}
void Sound::print_Sound() {
	
	cout << setw(20) << left << "Media_Level" << setw(20) << left << "CAll_Level";
	cout << setw(20) << left << "Navigation_LevelL" << setw(20) << left << "Notification_Level" << endl;
	cout << setw(20) << left << media_level << setw(20) << left << call_level << setw(20) << left << navigation_level;
	cout << setw(25) << left << notification_level << endl;
}

int Sound::get_media_level() {
	return media_level;
}
int Sound::get_call_level() {
	return call_level;
}
int Sound::get_navigation_level() {
	return navigation_level;
}
int Sound::get_notification_level() {
	return notification_level;
}

void Sound::set_media_level(int media) {
	media_level = media;
}
void Sound::set_call_level(int call) {
	call_level = call;
}
void Sound::set_navigation_level(int navigation) {
	navigation_level = navigation;
}
void Sound::set_notification_level(int notification) {
	notification_level = notification;
}

Sound::Sound() {
	media_level = 0;
	call_level = 0;
	navigation_level = 0;
	notification_level = 0;
};
Sound::~Sound() {
};
