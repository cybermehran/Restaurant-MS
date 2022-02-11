#pragma once
#include "Items.h"
class Orders : public Items
{
private: //float discount;
	   
	   float item_total_price;
	   int select_item_id;
	   int select_item_qty;
	   int select_category_OR_choice;
	   int customer_id;
	   int * temp_cust_id;
   public:
	   
	   Orders();
	   void place_order();
	   void update_order();
	   void delete_order();
};

