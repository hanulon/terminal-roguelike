#pragma once
class Item
{
public:
	Item(std::string name);
	~Item();

	enum ItemType
	{
		Melee,
		Firearm,
		Armor,
		Wearable,
		Consumable,
		Unwearable
	};

	std::string getName();
	ItemType myType = Unwearable;
	std::string description;
	int bonus = 0;

private:
	std::string name;
};

