#include "Items.h"

#include <iomanip>
#include <iostream>
using namespace std;
#include <string>
#include <fstream>
Items::Items()
{
	int item_price_s=0;
	//int item_price_m=0;
	//int item_price_l=0;
	//item_total_price = 0;

}
void Items::add_item()
{
	ofstream fout;
	fout.open("items.csv", ios::app);
	cout << "Enter the id of the Item" << endl;
	cin >> item_id;
	fout << item_id << " ";
	//cin.get();
	cout << "Enter the name of the Item. NOTE: Use under score \"_\" instead of 'space' " << endl;
	cin>> item_name;
	fout << item_name<<" ";
	//cin.get();
	cout << "Enter the price of the Item of small size" << endl;
	cin>>item_price_s;
	fout << item_price_s << " ";

	/*cout << "Enter the price of the Item of medium size" << endl;
	cin>>item_price_m;
	cout << "Enter the price of the Item of large size" << endl;
	cin>>item_price_l;*/

	cout << "Enter the category of the item" << endl;
	cin>>item_category;
	fout << item_category<<endl;

	fout.close();
}
void Items::delete_item(int id)
{
	ofstream nf;
	ifstream fin;
	fin.open("Items.csv");
	nf.open("temp.csv");
	while (!fin.eof())
	{
		fin >> item_id;
		fin >> item_name;
		fin >> item_price_s;
		fin >> item_category;
		if (item_id != id)
		{
			nf << item_id << " ";
			nf << item_name << " ";
			nf << item_price_s << " ";
			nf << item_category << endl;
		}

			
	}
	fin.close();
	nf.close(); 
	remove("Items.csv");
	rename("temp.csv", "Items.csv");
}
void Items::edit_item(int id)
{
	ofstream nf;
	ifstream fin;
	fin.open("Items.csv");
	nf.open("temp.csv");
	while (!fin.eof())
	{
		fin >> item_id;
		fin >> item_name;
		fin >> item_price_s;
		fin >> item_category;
		if (item_id == id)
		{
			cout << "\tEnter new record for id : " << id<<endl;
			add_item();
		}
		else 
		{
			nf << item_id << " ";
			nf << item_name << " ";
			nf << item_price_s << " ";
			nf << item_category << endl;
		}


	}
	fin.close();
	nf.close();
	remove("Items.csv");
	rename("temp.csv", "Items.csv");

}
void Items::search_item()
{

}

void Items::show_all_item()
{
	ifstream fin;
	fin.open("Items.csv");
	cout << "__________________________________________________" << endl;
	cout << setw(7)<<"No. "<<setw(15) << "Name" << setw(15) << "Price" << setw(12) << "Category" << endl;
	cout << "--------------------------------------------------" << endl;

	while (!fin.eof())
	{

		fin >> item_id;
		fin >> item_name;
		fin >> item_price_s;
		fin >> item_category;
		//if (item_id < 20)
		//if (strcmp(item_category ,"pizza")==0)
			cout << setw(5) << item_id << setw(20)<< item_name << setw(10) << item_price_s << setw(12) << item_category << endl;
		

	}
	fin.close();
}
