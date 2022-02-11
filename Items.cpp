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
	int count = 0;
	ifstream fin;
	ofstream fout;
	fout.open("Items.csv", ios::app);
	//cout << "Enter the id of the Item" << endl;
	//cin >> item_id;
	fin.open("Items.csv");
	while (!fin.eof())
	{
		fin >> item_id;
		fin >> item_name;
		fin >> item_category;
		fin >> item_price_s;
		if(item_id == count)// so that ids remain unique
		count++;// if it condition true then it update
		count++;// double increament would jump from the same number if item_id same to count
	}
	item_id =  count +1;
	fout << item_id << " ";
	//cin.get();
	cout << "Enter the name of the Item. NOTE: Use under score \"_\" instead of 'space' " << endl;
	cin>> item_name;
	fout << item_name<<" ";
	//cin.get();
	cout << "Enter the category of the item" << endl;
	cin >> item_category;
	fout << item_category << " ";

	cout << "Enter the price of the Item " << endl;
	cin>>item_price_s;
	fout << item_price_s << endl;

	/*cout << "Enter the price of the Item of medium size" << endl;
	cin>>item_price_m;
	cout << "Enter the price of the Item of large size" << endl;
	cin>>item_price_l;*/
	fin.close();
	fout.close();

		cout << "Item Added to List" << endl;
		//header of available items
		cout << "__________________________________________________" << endl;
		cout << setw(7) << "ID. " << setw(15) << "Name" << setw(15)
			<< "Category" << setw(12) << "Price" << endl;
		cout << "--------------------------------------------------" << endl;
		//first showing the list of items to customer for pizza category
		fin.open("Items.csv");
		while (!fin.eof())
		{
			fin >> item_id;
			fin >> item_name;
			fin >> item_category;
			fin >> item_price_s;
				cout << setw(5) << item_id << setw(20) << item_name << setw(10)
					<< item_category << setw(12) << item_price_s << endl;
		}
		fin.close();
		cout << "__________________________________________________\n" << endl;//bottom of available items list

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
		fin >> item_category;
		fin >> item_price_s;
		
		if (item_id != id)
		{
			nf << item_id << " ";
			nf << item_name << " ";
			nf << item_category << " ";
			nf << item_price_s << endl;
		}

			
	}
	fin.close();
	nf.close(); 
	remove("Items.csv");
	rename("temp.csv", "Items.csv");

	cout << "### Item Id " << id << " deleted. ###" << endl;
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
		fin >> item_category;
		fin >> item_price_s;
		
		if (item_id == id)
		{
			cout << "\tEnter new record for id : " << id<<endl;
			add_item();
		}
		else 
		{
			nf << item_id << " ";
			nf << item_name << " ";
			nf << item_category << " ";
			nf << item_price_s << endl;
		}


	}
	fin.close();
	nf.close();
	remove("Items.csv");
	rename("temp.csv", "Items.csv");

	cout << "### Record Updated ###" << endl;
}
//void Items::search_item()
//{}

void Items::show_all_item()
{
	ifstream fin;
	fin.open("Items.csv");
	cout << "__________________________________________________" << endl;
	cout << setw(7)<<"ID. " <<setw(15) << "Name" << setw(15) <<"Category"  << setw(12) << "Price" << endl;
	cout << "--------------------------------------------------" << endl;

	while (!fin.eof())
	{

		fin >> item_id;
		fin >> item_name;
		fin >> item_category;
		fin >> item_price_s;
			cout << setw(5) << item_id << setw(20)<< item_name << setw(10) << item_category << setw(12) << item_price_s << endl;

	}
	fin.close();
	cout << "__________________________________________________" << endl<<endl;
}
