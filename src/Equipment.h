#pragma once
#include "Inventory.h"
class Equipment :
	public Inventory
{
public:
	Equipment();
	~Equipment();

	void wearAsWeapon(Item* item);
	void wearAsArmor(Item* item);

private:
	Item* weaponEquipped;
	Item* armorEquipped;
};

