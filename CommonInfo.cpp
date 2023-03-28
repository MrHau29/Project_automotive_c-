#include "CommonInfo.h"
bool ValidateInput(string str, const char* regExp) {
	regex regexInput(regExp);
	if (regex_match(str, regexInput))	//Kiem tra giá trị nhập từ bàn phím có match với định dạng cho sẵn hay không
		return true;
	return false;
}