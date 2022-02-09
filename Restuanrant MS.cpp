#include <iostream>
#include "Items.h"
#include "Orders.h"
using namespace std;

int main()
{
	Items i;
	Orders o;
	
	int option,id1, id2;
	//customer control area
	do
	{
		cout << "Enter your Choice" << endl;
		cout << "1. Place a order" << endl;
		cout << "2. Update a order" << endl;
		cout << "3. Delete a delete" << endl;
		cout << "4. Show Order List" << endl;
		//cout << "5. " << endl;
		cout << "0. Exit" << endl;

		cin >> option;
		switch (option)
		{
		case 1:

			//i.add_item();
			o.place_order();
			break;
		case 2:
			cout << "update order" << endl;
			
			//i.edit_item(id1);
			break;
		case 3:
			cout << "Order update delete" << endl;
			
			//o.delete_order;
			break;
		case 4:
			//o.update_order();
			break;
		case 5:
			//
			break;
		case 0:
			break;
		default:
			cout << "\nInvalid Entry. Try Again";
			break;
		}



	} while (option != 0);

	//admin control area

	do
	{
		cout << "Enter your Choice" << endl;
		cout << "1. Add an Item in the List" << endl;
		cout << "2. Update an Item in the List" << endl;
		cout << "3. Delete an item in the list" << endl;
		cout << "4. Search an item in the List" << endl;
		cout << "5. Show all items in the List" << endl;
		cout << "0. Exit" << endl;

		cin >> option;
		switch (option)
		{
		case 1:
			i.add_item();
			break;
		case 2:
			cout << "Enter item id for update it data" << endl;
			cin >> id1;
			i.edit_item(id1);
			break;
		case 3:
			cout << "Enter item id for update it data" << endl;
			cin >> id2;
			i.delete_item(id2);
			break;
		case 4:
			 i.search_item();
			break;
		case 5:
			i.show_all_item();
			break;
		default:
			cout << "Invalid Entry. Try Again";
			break;
		}



	} while (option != 0);
	

}