#pragma once
class Item
{
public:
	Item(std::string name);
	~Item();

	std::string getName();

private:
	std::string name;
};

