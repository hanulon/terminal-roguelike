#include "stdafx.h"
#include "Inventory.h"


Inventory::Inventory()
{
}


Inventory::~Inventory()
{
}

void Inventory::addNewItem(Item newItem)
{
	this->possessedItems.push_back(newItem);
}

std::string Inventory::getListOfPossessedItems()
{
	std::string listOfItems = "";
	for (int i = 0; i < possessedItems.size(); i++)
	{
		listOfItems += possessedItems[i].getName() + "\n";
	}
	return listOfItems;
}

vector<Item> Inventory::getAllItemsAndRemove()
{
	vector <Item> items = possessedItems;
	possessedItems.clear();
	return items;
}

bool Inventory::obstacleHasNoItems()
{
	if (possessedItems.size() > 0)
		return false;
	return true;
}