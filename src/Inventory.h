#pragma once
#include "Item.h"

class Inventory
{
public:
	Inventory();
	~Inventory();

	void addNewItem(Item newItem);
	std::string getListOfPossessedItems();
	vector <Item> getAllItemsAndRemove();
	bool obstacleHasNoItems();

private:
	vector <Item> possessedItems;
};

