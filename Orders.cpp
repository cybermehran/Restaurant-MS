#include "Orders.h"
#include <iostream>
using namespace std;
#include <fstream>
#include <iomanip>
Orders::Orders()
{
	int customer_id = 0;
	//int temp_cust_id = 0;
	//item_total_price;
}
void Orders::place_order()
{
	
	customer_id ++;
	temp_cust_id = &customer_id; // passing address of the customer id. so that to use it for display
	ifstream fin;
	ofstream write_orders;// take orders
	do {
		cout << " Categories\n" << endl;
		cout << "\t1. Pizza" << "\t2. Fries" << endl;
		cout << "\t3. Burger" << "\t4. Shake" << endl;
		cout << "\t0. Order Complete" << endl;
		//cout << "\t5. Ice Cream" << "\t6. Steak" << endl;

		cout << "--> Select Category " << endl;
		cin >> select_category_OR_choice;

		switch (select_category_OR_choice)
		{
		case 1://11111111111111111111111111111111111111111111111111
			write_orders.open("orders List.csv", ios::app); //new file creation to store customers orders with id
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
				if (strcmp(item_category, "pizza") == 0)
				{
					cout << setw(5) << item_id << setw(20) << item_name << setw(10)
						<< item_category << setw(12) << item_price_s << endl;
				}
			}
			fin.close();
			cout << "__________________________________________________\n" << endl;//bottom of available items
			// now taking the item id from the customer 	
			cout << "\nTo select, Enter item Id" << endl;
			cin >> select_item_id;
			cout << "\nEnter quantity you want" << endl;
			cin >> select_item_qty;

			// again open of Items file to match the item id so we can copy it to order list file
			fin.open("Items.csv");
			//fin.open("orders List.csv");
			while (!fin.eof())
			{
				fin >> item_id;
				fin >> item_name;
				fin >> item_category;
				fin >> item_price_s;
				if (item_id == select_item_id)
				{
					write_orders << item_id << " ";
					write_orders << item_name << " ";
					write_orders << item_category << " ";
					write_orders << item_price_s << " ";
					write_orders << select_item_qty << " ";
					write_orders << item_price_s * select_item_qty << " ";
					write_orders << customer_id << endl;
				}
			}
			fin.close();
			//header of selected items
			cout << "Item Included\n" << endl;
			//to show the value of customer id
			cout  <<"================================= Your Customer ID: " << *temp_cust_id << " ============================"<<endl;
			cout << "__________________________________________________________________________________" << endl;
			cout << setw(7) << "ID. " << setw(15) << "Name" << setw(15)
				<< "Category" << setw(12) << "Unit Price" << setw(10) <<"Item Qty"<< setw(8)<<"Price"<<setw(13)<<"Customer Id"<< endl;
			cout << "----------------------------------------------------------------------------------" << endl;
			
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

				if (customer_id == *temp_cust_id)
					//if (item_price_s < 500)
				{
					cout << setw(5) << item_id << setw(20) << item_name << setw(10) << item_category << setw(12) << item_price_s <<
						setw(10) << select_item_qty << setw(10) << item_total_price << setw(10) << customer_id << endl;

				}
			}
			fin.close();
			write_orders.close();
			cout << "___________________________________________________________________________________" << endl;//bottom line of selected items
			break;

		case 2://22222222222222222222222222222222222222222222222222222222222
			write_orders.open("orders List.csv", ios::app); //new file creation to store customers orders with id

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
				if (strcmp(item_category, "fries") == 0)
				{
					cout << setw(5) << item_id << setw(20) << item_name << setw(10)
						<< item_category << setw(12) << item_price_s << endl;
				}
			}
			fin.close();
			cout << "__________________________________________________\n" << endl;//bottom of available items
			// now taking the item id from the customer 	
			cout << "\nTo select, Enter item Id" << endl;
			cin >> select_item_id;
			cout << "\nEnter quantity you want" << endl;
			cin >> select_item_qty;

			// again open of Items file to match the item id so we can copy it to order list file
			fin.open("Items.csv");
			//fin.open("orders List.csv");
			while (!fin.eof())
			{
				fin >> item_id;
				fin >> item_name;
				fin >> item_category;
				fin >> item_price_s;
				if (item_id == select_item_id)
				{
					write_orders << item_id << " ";
					write_orders << item_name << " ";
					write_orders << item_category << " ";
					write_orders << item_price_s << " ";
					write_orders << select_item_qty << " ";
					write_orders << item_price_s * select_item_qty << " ";
					write_orders << customer_id << endl;
					
				}
			}
			fin.close();

			cout << "Item Included\n" << endl;
			//to show the value of customer id
			cout << "================================= Your Customer ID: " << *temp_cust_id << " ============================" << endl;

			cout << "__________________________________________________________________________________" << endl;
			cout << setw(7) << "ID. " << setw(15) << "Name" << setw(15)
				<< "Category" << setw(12) << "Unit Price" << setw(10) << "Item Qty" << setw(8) << "Price" << setw(13) << "Customer Id" << endl;
			cout << "----------------------------------------------------------------------------------" << endl;

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

				//if (*temp_cust_id == customer_id)
				{
					cout << setw(5) << item_id << setw(20) << item_name << setw(10) << item_category << setw(12) << item_price_s <<
						setw(10) << select_item_qty << setw(10) << item_total_price << setw(10) << customer_id << endl;
				}
			}
			fin.close();
			write_orders.close();
			cout << "__________________________________________________________________________________" << endl;
			//bottom line of selected items
			break;
		case 3://333333333333333333333333333333333333333333333333333333333333
			write_orders.open("orders List.csv", ios::app); //new file creation to store customers orders with id

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
				if (strcmp(item_category, "burger") == 0)
				{
					cout << setw(5) << item_id << setw(20) << item_name << setw(10)
						<< item_category << setw(12) << item_price_s << endl;
				}
			}
			fin.close();
			cout << "__________________________________________________\n" << endl;//bottom of available items

			// now taking the item id from the customer 	
			cout << "\nTo select, Enter item Id" << endl;
			cin >> select_item_id;
			cout << "\nEnter quantity you want" << endl;
			cin >> select_item_qty;

			// again open of Items file to match the item id so we can copy it to order list file
			fin.open("Items.csv");
			//fin.open("orders List.csv");
			while (!fin.eof())
			{
				fin >> item_id;
				fin >> item_name;
				fin >> item_category;
				fin >> item_price_s;
				if (item_id == select_item_id)
				{
					write_orders << item_id << " ";
					write_orders << item_name << " ";
					write_orders << item_category << " ";
					write_orders << item_price_s << " ";
					write_orders << select_item_qty << " ";
					write_orders << item_price_s * select_item_qty << " ";
					write_orders << customer_id << endl;
					//cout << setw(5) << item_id << setw(20) << item_name << setw(10)
					//	<< item_price_s << setw(12) << item_category << endl;

				}
			}
			fin.close();

			cout << "Item Included\n" << endl;
			//to show the value of customer id
			cout << "================================= Your Customer ID: " << *temp_cust_id << " ============================" << endl;

			cout << "__________________________________________________________________________________" << endl;
			cout << setw(7) << "ID. " << setw(15) << "Name" << setw(15)
				<< "Category" << setw(12) << "Unit Price" << setw(10) << "Item Qty" << setw(8) << "Price" << setw(13) << "Customer Id" << endl;
			cout << "----------------------------------------------------------------------------------" << endl;

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
				cout << setw(5) << item_id << setw(20) << item_name << setw(10) << item_category << setw(12) << item_price_s <<
					setw(10) << select_item_qty << setw(10) << item_total_price << setw(10) << customer_id << endl;
			}
			fin.close();
			write_orders.close();
			//bottom line of selected items
			cout << "__________________________________________________________________________________" << endl;

			break;

		case 4: //44444444444444444444444444444444444444444444444444444444444444444444444444444444
			write_orders.open("orders List.csv", ios::app); //new file creation to store customers orders with id

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
				if (strcmp(item_category, "shake") == 0)
				{
					cout << setw(5) << item_id << setw(20) << item_name << setw(10)
						<< item_category << setw(12) << item_price_s << endl;
				}
			}
			fin.close();
			cout << "__________________________________________________\n" << endl;//bottom of available items

			// now taking the item id from the customer 	
			cout << "\nTo select, Enter item Id" << endl;
			cin >> select_item_id;
			cout << "\nEnter quantity you want" << endl;
			cin >> select_item_qty;

			// again open of Items file to match the item id so we can copy it to order list file
			fin.open("Items.csv");
			//fin.open("orders List.csv");
			while (!fin.eof())
			{
				fin >> item_id;
				fin >> item_name;
				fin >> item_category;
				fin >> item_price_s;
				if (item_id == select_item_id)
				{
					write_orders << item_id << " ";
					write_orders << item_name << " ";
					write_orders << item_category << " ";
					write_orders << item_price_s << " ";
					write_orders << select_item_qty << " ";
					write_orders << item_price_s * select_item_qty << " ";
					write_orders << customer_id << endl;
					//cout << setw(5) << item_id << setw(20) << item_name << setw(10)
					//	<< item_price_s << setw(12) << item_category << endl;

				}
			}
			fin.close();

			cout << "Item Included\n" << endl;
			//to show the value of customer id
			cout << "================================= Your Customer ID: " << *temp_cust_id << " ============================" << endl;
			cout << "__________________________________________________________________________________" << endl;
			cout << setw(7) << "ID. " << setw(15) << "Name" << setw(15)
				<< "Category" << setw(12) << "Unit Price" << setw(10) << "Item Qty" << setw(8) << "Price" << setw(13) << "Customer Id" << endl;
			cout << "----------------------------------------------------------------------------------" << endl;

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
				cout << setw(5) << item_id << setw(20) << item_name << setw(10) << item_category << setw(12) << item_price_s <<
					setw(10) << select_item_qty << setw(10) << item_total_price << setw(10) << customer_id << endl;
			}
			fin.close();
			write_orders.close();
			//bottom line of selected items
			cout << "__________________________________________________________________________________" << endl;
			break;
		case 0:
			break;
		default:
			cout << "\nInvalid Entry. Try Again";
			break;
		}
		
	} while (select_category_OR_choice != 0);


}
