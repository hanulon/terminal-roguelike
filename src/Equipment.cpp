#include "stdafx.h"
#include "Equipment.h"


Equipment::Equipment()
{
}


Equipment::~Equipment()
{
}

void Equipment::wearAsWeapon(Item * item)
{
	weaponEquipped = item;
}

void Equipment::wearAsArmor(Item * item)
{
	armorEquipped = item;
}
