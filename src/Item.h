#pragma once
class Item
{
public:
	Item(std::string name);
	~Item();

	enum Type
	{
		Weapon,
		Armor,
		Unwearable
	};

	std::string getName();
	Type myType = Unwearable;
	std::string description;

private:
	std::string name;
};

