#include "tree.h"
#include<fstream>
Tree::Tree() {
	root = NULL;
}
Tree::~Tree() {

}

/*					Them vao vao cay						*/

void Tree::insert(Car* car, Node* leaf) {

	if (car->getPersonalKey() < leaf->car->getPersonalKey()) {
		if (leaf->left != NULL) {
			insert(car, leaf->left);
		}
		else {
			leaf->left = new Node;
			leaf->left->car = car;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
			car_count++;
		}
	}
	else if (car->getPersonalKey() > leaf->car->getPersonalKey()) {
		if (leaf->right != NULL) {
			insert(car, leaf->right);
		}
		else {
			leaf->right = new Node;
			leaf->right->car = car;
			leaf->right->right = NULL;
			leaf->right->left = NULL;
			car_count++;
		}
	}
	
}

void Tree::insert(Car* car) {
	if (root != NULL) {
		insert(car, root);
	}
	else {
		root = new Node;
		root->car = car;
		root->left = NULL;
		root->right = NULL;
	}
}

/*					Tim kiem cay 						*/

bool  Tree::search(Node* aNode, string key) {
	if (aNode != NULL) {
		if (key == aNode->car->getPersonalKey()) {
			return aNode;
		}
		if (key < aNode->car->getPersonalKey()) {
			return search(aNode->left, key);
		}
		else if (key > aNode->car->getPersonalKey()) {
			return search(aNode->right, key);
		}
	}
	else {
		return false;
	}
}
bool Tree::search(string key) {
	return search(root, key);
}

/*					Ghi de Node						*/
void Tree::overRide(Node* aNode, Car* car) {
	if (aNode) {
		overRide(aNode->left, car);
		overRide(aNode->right, car);
		if (car->getPersonalKey() == aNode->car->getPersonalKey()) {
			aNode->car = car;
		}
	}
	else {
		printf("Node is NULL");
	}
}

void Tree::overRide(Car* car) {
	overRide(root, car);
}
vector<Car> dscar;
/*					Print Display				*/
void Tree::print_Display(Node* aNode) {
	if (aNode != NULL) {
	
			print_Display(aNode->left);
			
			cout << setw(20) << left << "-------------------------------------" << endl;
			cout << "--- INFOMATION SETTING: " << endl;
			aNode->car->print_info_car();
			cout << "--- INFOMATION DISPLAY: " << endl;
			aNode->car->print_Display();
			cout << setw(20) << left << "-------------------------------------" << endl;
			print_Display(aNode->right);
			
	}

}

void Tree::print_Display() {
	print_Display(root);

}

/*					Print Sound				*/
void Tree::print_Sound(Node* aNode) {
	if (aNode != NULL) {
			print_Sound(aNode->left);
		
			cout << setw(20) << left << "-------------------------------------" << endl;
			cout << "--- INFOMATION SETTING: " << endl;
			aNode->car->print_info_car();
			cout << "--- SETTING SOUND: " << endl;
			aNode->car->print_Sound();
			cout << setw(20) << left << "-------------------------------------" << endl;
			print_Sound(aNode->right);
			
	}


}

void Tree::print_Sound() {
	print_Sound(root);

	/*					Print General				*/

}void Tree::print_General(Node* aNode) {
	if(aNode != NULL) {
		print_General(aNode->left);
		
		cout << setw(20) << left << "-------------------------------------" << endl;
		cout << "--- INFOMATION SETTING: " << endl;
		aNode->car->print_info_car();
		cout << "--- SETTING GENERAL: " << endl;
		aNode->car->print_general();
		cout << setw(20) << left << "-------------------------------------" << endl;
		print_General(aNode->right);
		
	}
}

void Tree::print_General() {
	print_General(root);

	/*					Print all				*/
}void Tree::print_ALL_setting(Node* aNode) {
	if (aNode != NULL) {
		print_ALL_setting(aNode->left);
		cout << " ---  Print  ALL --- " << endl;
		cout << setw(20) << left << "-------------------------------------" << endl;
		cout << "--- INFOMATION SETTING: " << endl;
		aNode->car->print_info_car();
		cout << "--- SETTING DISPLAY: " << endl;
		aNode->car->print_Display();
		cout << "--- SETTING SOUND: " << endl;
		aNode->car->print_Sound();
		cout << "--- SETTING GENERAL: " << endl;
		aNode->car->print_general();
		cout << setw(20) << left << "-------------------------------------" << endl;
		print_ALL_setting(aNode->right);
	}
}

void Tree::print_ALL_setting() {
	print_ALL_setting(root);
}
/*				ghi thong tin ra file					*/	
void Tree::write_to_file(Node *aNode) {
	ofstream fileout("Setting.txt", ios::out |ios::app);
	try {
		if(fileout.is_open()){
			if (aNode != NULL) {
				write_to_file(aNode->left);
				fileout << "Common: " << aNode->car->getCarName() << ", " << aNode->car->getEmail() << ","<< aNode->car->getPersonalKey() << ", " << aNode->car->getOdo() << ", " << aNode->car->getServiceRemind() << ";";
				fileout << "Display: " << aNode->car->get_light_level() << ", "<< aNode->car->get_screen_light_level() << ", " << aNode->car->get_taplo_light_level() << ";";
				fileout << "Sound: " << aNode->car->get_media_level() << ", " <<aNode->car->get_call_level() << ", " << aNode->car->get_navigation_level() << ", " << aNode->car->get_notification_level() << ";";
				fileout << "General: " << aNode->car->get_timeZone() << ", " <<aNode->car->get_language() << endl;
				write_to_file(aNode->right);
			
			}
			
		}
		else {
			throw "FAIL TO WRITE TO FILE";
		}
	}
	catch (exception e) {
		cout << e.what() << endl;
		
	}
	fileout.close();
	
}

void Tree::write_to_file() {
	write_to_file(root);
}