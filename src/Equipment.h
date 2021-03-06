#pragma once
#include "Inventory.h"
class Equipment :
	public Inventory
{
public:
	Equipment();
	~Equipment();

	void wearAsWeapon(std::string itemName);
	void wearAsArmor(std::string itemName);
	Item* removeItem(std::string itemName);
	void unequipItem(std::string itemName);
	std::string useItemAndGetResponse(std::string itemName);
	std::string getItemDecription(std::string itemName);
	std::string getEquippedItemsList();
	int getArmorBonus();
	int getWeaponBonus();

private:
	Item* weaponEquipped;
	Item* armorEquipped;
};

