#include "stdafx.h"
#include "Item.h"


Item::Item(std::string name)
{
	this->name = name;
}


Item::~Item()
{
}

std::string Item::getName()
{
	return this->name;
}
