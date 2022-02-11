#pragma once
#include <iostream>
using namespace std;
class Customers
{
//private:
	
	

public:
	string customer_name;
	char customer_contact[11];
	int customer_id;
	int* temp_cust_id;
	Customers();
	void place_order(); // function overriding for orders class functions
	void update_order();// function overriding for orders class functions
	void cancel_order(int customer_id_cancel_order);// function overriding for orders class functions
};

