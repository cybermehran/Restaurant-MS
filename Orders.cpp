#include "Orders.h"
#include <iostream>
using namespace std;
#include <fstream>
#include <iomanip>
Orders::Orders()
{
	item_quantity = 0;
	item_total_price = 0;
}
void Orders::place_order()
{
	int select_item_id;
	ifstream fin;
	ofstream write_orders;
	write_orders.open("orders List.csv");
	fin.open("Items.csv");
	cout << "__________________________________________________" << endl;
	cout << setw(7)<<"No. "<<setw(15)<<"Name"<<setw(15) 
		<< "Price" << setw(12) << "Category" << endl;
	cout << "--------------------------------------------------" << endl;

	while (!fin.eof())
	{

		fin >> item_id;
		fin >> item_name;
		fin >> item_price_s;
		fin >> item_category;
		if (strcmp(item_category, "pizza") == 0) 
		{
			cout << setw(5) << item_id << setw(20) << item_name << setw(10)
				<< item_price_s << setw(12) << item_category << endl;
		}
		cout << "Enter the item id " << endl;
			cin >> select_item_id;



	}
	fin.close();

}
