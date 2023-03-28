#include "Car.h"


bool is_email_valid(const std::string& email)
{
	// define a regular expression
	const std::regex pattern
	("(\\w+)(\\.|_)?(\\w*)@(\\w{5})(\\.(\\w+[com]))+");
	/*("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");*/
	// try to match the string with the regular expression
	return std::regex_match(email, pattern);
}

bool validate_key(string key) {
	regex patter("^[0-9]{8}$");
	return regex_match(key, patter);
}


void Car::input_info_car() {
	/*				ENTER OWNER NAME			*/
	system("cls");
	cout << "INPUT_Car Name: ";
	getline(cin, carName);
	while (!ValidateInput(carName, "^[a-zA-Z0-9 -]{3,15}$"))
	{
		system("cls");
		cout << "INPUT_Car Name: ";
		getline(cin, carName);
	}
	

	/*				ENTER PRIVATE KEY			*/
	cout << "INPUT_Personal_Key: ";
	getline(cin, personalkey);
	cin.clear(); //Xóa cờ lỗi trên cin để I/O làm việc chính xác hơn
	while (!validate_key(personalkey)) {		//Nếu ID nhập vào không hợp lệ thì nhập lại, các thông tin đã lưu
		system("cls");					//ở trên sẽ được hiển thị lại. Các thông tin ở dưới sẽ được thực hiện
		cout << "Car Name: " << carName << endl;
		cout << "Personal Key: ";
		getline(cin, personalkey);
		cin.clear();
	}
	


	/*				ENTER OWNER EMAIL			*/
	cout << "INPUT_Email: ";
	getline(cin, email);
	while (!is_email_valid(email)) {
		system("cls");
		cout << "Car Name: " << carName << endl;
		cout << "Personal Key: " << personalkey << endl;
		cout << "INPUT_Email: ";
		getline(cin, email);
		cin.clear();
	}
	/*				ENTER CAR ODO NUMBER			*/
	cout << "INPUT_Odo: ";
	string odo_tm;
	getline(cin, odo_tm);
	cin.clear();
	while (!ValidateInput(odo_tm, VALIDATE_INPUT_ODO_SERVICE)) {
		system("cls");
		cout << "Car NAme: " << carName << endl;
		cout << "Personal Key : " << personalkey << endl;
		cout << "Email " << email << endl;
		cout << "INPUT_Odo: ";
		getline(cin, odo_tm);
		cin.clear();
	}
	odo = stoi(odo_tm);
	/*				ENTER SERVICE REMIND NUMBER			  */
	cout << "INPUT_Rervice_Remind: ";
	string service_tmp;
	getline(cin, service_tmp);
	cin.clear();
	while (!ValidateInput(service_tmp, VALIDATE_INPUT_ODO_SERVICE)) {
		system("cls");
		cout << "Car NAme: " << carName << endl;
		cout << "Personal Key : " << personalkey << endl;
		cout << "Email " << email << endl;
		cout << "INPUT_Rervice_Remind: ";
		getline(cin, service_tmp);
		cin.clear();
	}
	serviceRemind = stoi(service_tmp);
};


void Car::print_info_car() {
	cout << setw(20) << left << "TEN CHU XE" << setw(20) << left << "Personal Key" << setw(20) << left;
	cout << "Email" << setw(20) << left << "ODO" << setw(20) << left << "SEVICES" << endl;
	cout << setw(20) << left << carName << setw(20) << left << personalkey;
	cout << setw(20) << left << email << setw(20) << left << odo << setw(20) << left << serviceRemind << endl;
	cout << endl;

}

string Car::getEmail() {
	return email;
}
string Car::getCarName() {
	return carName;
}
string Car::getPersonalKey() {
	return personalkey;
}
int Car::getOdo() {
	return odo;
}
int Car::getServiceRemind() {
	return serviceRemind;
}


void Car::setCarName(string name) {
	carName = name;
}
void Car::setEmail(string Email) {
	email = Email;
}
void Car::setPersonalKey(string key) {
	personalkey = key;
}
void Car::set_odo(int ODO) {
	odo = ODO;
}
void Car::setServiceRemind(int km) {
	serviceRemind = km;
}


Car::Car():Display() {
	carName = " ";
	email = " ";
	personalkey = " ";
	odo = 0;
	serviceRemind = 0;
};
Car::~Car() {};