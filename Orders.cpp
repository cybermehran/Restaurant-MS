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
	int select_item_qty;
	int select_category;
	ifstream fin;
	ofstream write_orders;// take orders

	cout << " Categories\n" << endl;
	cout  << "\t1. Pizza"  << "\t2. Fries" << endl;
	cout  << "\t3. Burger" <<"\t4. Steak" << endl;
	cout  << "\t5. Ice Cream" << "\t6. Shakes" << endl;
	cout << "  *** Select Category ***" << endl;
	cin >> select_category;

	write_orders.open("orders List.csv", ios::app); //new file creation to store customers orders with id
	
	cout << "__________________________________________________" << endl;
	cout << setw(7)<<"ID. "<<setw(15)<<"Name"<<setw(15) 
		<< "Price" << setw(12) << "Category" << endl;
	cout << "--------------------------------------------------" << endl;
	//first showing the list of items to customer for pizza category
	fin.open("Items.csv");
	while (!fin.eof())
	{
		fin >> item_id;
		fin >> item_name;
		fin >> item_price_s;
		fin >> item_category;
		if (strcmp(item_category, "shake") == 0) 
		{
			cout << setw(5) << item_id << setw(20) << item_name << setw(10)
				<< item_price_s << setw(12) << item_category << endl;
		}
		}
	fin.close();

	// now taking the item id from the customer 	
	cout << "\nTo select, Enter item Id" << endl;
	cin >> select_item_id;

	// again open of Items file to match the item id so we can copy it to order list file
	fin.open("Items.csv");
	//fin.open("orders List.csv");
	while (!fin.eof())
	{
		fin >> item_id;
		fin >> item_name;
		fin >> item_price_s;
		fin >> item_category;
		if (item_id == select_item_id)
		{
			write_orders << item_id<<" ";
			write_orders << item_name << " ";
			write_orders << item_price_s << " ";
			write_orders << item_category << endl;
			//cout << setw(5) << item_id << setw(20) << item_name << setw(10)
			//	<< item_price_s << setw(12) << item_category << endl;

		}
	}
	fin.close();
	
	cout << "Item Included\n" << endl;
	fin.open("orders List.csv");
	while (!fin.eof())
	{
		fin >> item_id;
		fin >> item_name;
		fin >> item_price_s;
		fin >> item_category;
		cout<< setw(5) << item_id << setw(20) << item_name << setw(10)<< item_price_s << setw(12) << item_category << endl;
	}
	fin.close();
	//write_orders.close();
	 


}
