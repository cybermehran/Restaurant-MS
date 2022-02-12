#pragma once
#include "Items.h"
#include "Customers.h"
class Orders : public Items, public Customers 

{
private: 
	 
	   float item_total_price;
	   int select_item_id;
	   int select_item_qty;
	   int select_category_OR_choice;
	    
   public:
	   
	   Orders();
	   void place_order();
	   void update_order();
	   void cancel_order(int customer_id_cancel_order);
	   void check_out();
};

