#pragma once
#include"Car.h"
class Node
{
public:
	Car *car;
	Node* left;
	Node* right;
};
class Tree {
private :
	Node* root;

	void insert(Car *data, Node* aNode); //	Them Node Vao Cay
	bool search(Node* aNode, string key); // Tim Kiem Node Theo Mscn
	void print_Display(Node* aNode); // In Thong Tin DIsplay
	void print_Sound(Node* aNode); // In Thong Tin Sound;
	void print_General(Node* aNode); // In Thong Tin General
	void print_ALL_setting(Node* aNode); // In tat ca thonn tin
	void clear_Node(Node* aNdoe, Car car); // xoa node
	void overRide(Node* aNode, Car* car); // Ghi de node

	/*				Ghi thông tin ra file	setting			*/
	void write_to_file(Node* anode);

public:
	Tree();
	~Tree();

	void insert(Car *data);
	bool search(string key);
	void print_Display();
	void print_Sound();
	void print_General();
	void print_ALL_setting();
	void claer_Node();
	void overRide(Car *car);

	/*				Ghi thông tin ra file	setting			*/
	void write_to_file();

	int car_count = 1;
};

