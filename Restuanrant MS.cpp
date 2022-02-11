#include <iostream>
#include "Items.h"
#include "Orders.h"
using namespace std;

void admin();
void customer();
int main()
{
	cout << "\t\t\t##########################################" <<endl;
	cout << "\t\t\t            R E S T U A R A N T "<<endl;
	cout<<"\t\t\t     M A N A G E M E N T   S Y S T E M" << endl;
	cout << "\t\t\t##########################################\n" << endl<<endl;
	int press;
	
	cout << "Select 1: Customer" << endl;
	cout << "Select 2: Admin" << endl;
	cin >> press;

	switch (press)
	{
	case 1:
		customer();
		break;
	case 2:
		admin();
		break;
	case 0:
		break;
	default:
		cout << "Invalid entry, please try again";
		break;
	}
	
	

	
}
//admin control area
void admin()
{
	Items i;
	int option,id1, id2;
	do
	{
		
		cout << "Enter your Choice" << endl;
		cout << "1. Add an Item in the List" << endl;
		cout << "2. Update an Item in the List" << endl;
		cout << "3. Delete an item in the list" << endl;
		//cout << "4. Search an item in the List" << endl;
		cout << "4. Show all items in the List" << endl;
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
			cout << "Enter item id to delete its data" << endl;
			cin >> id2;
			i.delete_item(id2);
			break;
		case 4:
			i.show_all_item();
			break;
		//case 5:
			//i.search_item();
			//break;
		default:
			cout << "Invalid Entry. Try Again";
			break;
		}



	} while (option != 0);


}
//customer control area
void customer()
{
	int option;
	int customer_id_cancel_order;

	Orders o;
	//Customers* c;
	//c = new place_order();
	do
	{
		cout << "Enter your Choice" << endl;
		cout << "1. Place a order" << endl;
		cout << "2. Update a order" << endl;
		cout << "3. Cancel order" << endl;
		//cout << "4. Show Order List" << endl;
		//cout << "5. " << endl;
		cout << "0. Exit" << endl;

		cin >> option;
		switch (option)
		{
		case 1:
			o.place_order();
			break;
		case 2:
			cout << "update order" << endl;

			o.update_order();
			break;
		case 3://cancel order
			
			cout << "Enter your Customer ID" << endl;
			cin >> customer_id_cancel_order;
			//cout << "Order  delete" << endl;
			o.cancel_order( customer_id_cancel_order);
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

}