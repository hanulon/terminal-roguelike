#include "stdafx.h"
#include "Inventory.h"


Inventory::Inventory()
{
}


Inventory::~Inventory()
{
}

void Inventory::addNewItem(Item* newItem)
{
	this->possessedItems.push_back(newItem);
}

std::string Inventory::getListOfPossessedItems()
{
	std::string listOfItems = "";
	for (int i = 0; i < possessedItems.size(); i++)
	{
		listOfItems += possessedItems[i]->getName() + "\n";
	}
	return listOfItems;
}

vector<Item*> Inventory::getAllItemsAndRemove()
{
	vector <Item*> items = possessedItems;
	possessedItems.clear();
	return items;
}

bool Inventory::obstacleHasNoItems()
{
	if (possessedItems.size() > 0)
		return false;
	return true;
}

Item* Inventory::getItemByName(std::string itemName)
{
	for (int i = 0; i < possessedItems.size(); i++)
	{
		if (possessedItems[i]->getName() == itemName)
			return possessedItems[i];
	}
	return nullptr;
}

int Inventory::getItemIndexByName(std::string itemName)
{
	for (int i = 0; i < possessedItems.size(); i++)
	{
		if (possessedItems[i]->getName() == itemName)
			return i;
	}
	return -1;
}

void Inventory::removeItemFromVector(Item * toRemove)
{
	vector <Item*> possItems;
	for (int i = 0; i < possessedItems.size(); i++)
	{
		if (toRemove != possessedItems[i])
		{
			possItems.push_back(possessedItems[i]);
		}
	}
	possessedItems = possItems;
}
