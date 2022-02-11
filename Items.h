#pragma once
#include <iostream>
using namespace std;

class Items
{
//private:
public:
	int item_id;
	string item_name;
	int item_price_s;
	//int item_price_m;
	//int item_price_l;
	//
	char item_category[12];
	//string item_category;
	//
//public:
	Items();
	void add_item();
	void delete_item(int id);
	void edit_item(int id);
	void show_all_item();
	//void search_item();
	
	
};


