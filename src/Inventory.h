#pragma once
#include "Item.h"

class Inventory
{
public:
	Inventory();
	~Inventory();

	void addNewItem(Item* newItem);
	std::string getListOfPossessedItems();
	vector <Item*> getAllItemsAndRemove();
	bool obstacleHasNoItems();

protected:
	Item* getItemByName(std::string itemName);
	int getItemIndexByName(std::string itemName);
	vector <Item*> possessedItems;
	void removeItemFromVector(Item* toRemove);
};

