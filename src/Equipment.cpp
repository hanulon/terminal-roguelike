#include "stdafx.h"
#include "Equipment.h"


Equipment::Equipment()
{
}


Equipment::~Equipment()
{
}

void Equipment::wearAsWeapon(std::string itemName)
{
	Item* wearable = getItemByName(itemName);
	if(wearable->myType == wearable->Weapon)
		weaponEquipped = wearable;
}

void Equipment::wearAsArmor(std::string itemName)
{
	Item* wearable = getItemByName(itemName);
	if (wearable->myType == wearable->Armor)
		armorEquipped = wearable;
}

Item* Equipment::removeItem(std::string itemName)
{
	int itemIdx = getItemIndexByName(itemName);
	if (itemIdx > -1)
	{
		Item* drop = possessedItems[itemIdx];
		unequipItem(drop->getName());
		removeItemFromVector(drop);
		return drop;
	}
	return nullptr;
}

void Equipment::unequipItem(std::string itemName)
{
	Item* wearable = getItemByName(itemName);
	if (wearable == weaponEquipped)
	{
		weaponEquipped = nullptr;
	}
	else if (wearable == armorEquipped)
	{
		armorEquipped = nullptr;
	}
}

std::string Equipment::getItemDecription(std::string itemName)
{
	Item* item = getItemByName(itemName);
	string type = "";
	if ( item->myType == item->Weapon )
	{
		type = "Weapon";
	}
	else if (item->myType == item->Armor)
	{
		type = "Armor";
	}
	else
	{
		type = "Not wearable";
	}
	return item->getName() + " | " + item->description + " | " + type;
}

std::string Equipment::getEquippedItemsList()
{
	string equipped = "";
	if (weaponEquipped != nullptr)
	{
		equipped += "Weapon: " + weaponEquipped->getName() + "\n";
	}
	if (armorEquipped != nullptr)
	{
		equipped += "Armor: " + armorEquipped->getName() + "\n";
	}
	return equipped;
}
