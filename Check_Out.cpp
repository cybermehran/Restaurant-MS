#include "Check_Out.h"
#include <iostream>
using namespace std;
#include <fstream>
#include <iomanip>
void Check_Out::check_out()
{
	system("cls");
	int item_id;
	string item_name;
	string item_category;
	int  item_price_s;
	int  select_item_qty;
	int  item_total_price;
	int  customer_id;
	int customer_id_checkout;
	ifstream fin;
	ofstream write_orders;
	cout << "\n------------------------- C H E C K O U T  P A G E ----------------------------\n";
	cout << "\nEnter Your Customer ID" << endl;
	cin >> customer_id_checkout;
	cout << "=========================== Invoice of Customer ID: " << customer_id_checkout << " ==========================" << endl;
	cout << "________________________________________________________________________________" << endl;
	cout << setw(7) << "ID. " << setw(15) << "Name" << setw(15)
		<< "Category" << setw(12) << "Unit Price" << setw(10) << "Item Qty" << setw(8) << "Price" << setw(13) << "Customer Id" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;

	fin.open("orders List.csv");
	while (!fin.eof())
	{
		fin >> item_id;
		fin >> item_name;
		fin >> item_category;
		fin >> item_price_s;
		fin >> select_item_qty;
		fin >> item_total_price;
		fin >> customer_id;


		if (customer_id == customer_id_checkout)
		{
			cout << setw(5) << item_id << setw(20) << item_name << setw(10) << item_category << setw(12) << item_price_s <<
				setw(10) << select_item_qty << setw(10) << item_total_price << setw(10) << customer_id << endl;
			total_bill = total_bill + item_total_price;
		}
	}
	fin.close();
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << setw(15) << "TOTAL PRICE " << setw(50) << "Rs." << total_bill << "/-" << endl;
	cout << "________________________________________________________________________________\n" << endl;
	
	cout <<setw(47) <<"T H A N K   Y O U\n" << endl;
	cout << setw(55) << "F O R   S H O P P I N G   H E R E\n\n" << endl;

	cout << "________________________________________________________________________________\n" << endl;



}
