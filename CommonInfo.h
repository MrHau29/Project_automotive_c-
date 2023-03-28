#ifndef COMMON_H_
#define COMMON_H_

#include <iostream>
#include <iomanip>
#include <string>
#include<regex>
using namespace std;
const auto VALIDATE_EMAIL = "^\\w+\\@\\w+\\.\\w+(\\.\\w+)*$";	//Định dạng email là: name@abc.xyz(.vn)
const auto VALIDATE_ID = "^\\d{8}$";	//MSCN phải bao gồm 8 số
const auto VALIDATE_INPUT_ODO_SERVICE = "^\\d+$";  
const auto VALIDATE_INPUT_DISPLAY_SOUND = "^\\d+$"; // nhap so trong khoang 1 - 5
const auto VALIDATE_INPUT_SCREEN = "^\\d+$";	//input nhập vào phải là số
const auto VALIDATE_INPUT_YES_NO = "^y$|^n$|^Y$|^N$";	//Các câu hỏi yes/no chỉ nhập vào y or n


bool ValidateInput(string str, const char* regExp);


class CommonInfo {
public:
	string getNumber() {
		return number;
	}

	string getName() {
		return name;
	}

	void setNumber(string data) {
		number = data;
	}

	void setName(string data) {
		name = data;
	}

	void printTime(int i) {
		cout << setw(2) << i << ": " << setw(15) << number << name << endl;
	}
	void printLang(int i) {
		cout << setw(2) << i << " : " << name << endl;
	}

private:
	string number;
	string name;
};
#endif // COMMON_H_
