#pragma once
#include "Items.h"
class Orders : public Items
{
private: //float discount;
	   int item_quantity;
	   float item_total_price;
   public:
	   Orders();
	   void place_order();
};

