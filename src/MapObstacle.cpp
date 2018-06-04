#include "stdafx.h"
#include "MapObstacle.h"


MapObstacle::MapObstacle(std::string name)
{
	this->name = name;
	this->myInventory = new Inventory();
}


MapObstacle::~MapObstacle()
{
}

void MapObstacle::setName(std::string name)
{
	this->name = name;
}

std::string MapObstacle::getName()
{
	return this->name;
}

char MapObstacle::getNameFirstLetter()
{
	return this->name[0];
}

void MapObstacle::setMapPosition(Point position)
{
	this->mapPosition = position;
}

Point MapObstacle::getMapPosition()
{
	return this->mapPosition;
}

void MapObstacle::setMyInteractions(Interaction * defaulty, Interaction * alternative)
{
	if (alternative == nullptr)
		alternative = defaulty;
	this->defaultInteraction = defaulty;
	this->alternativeInteraction = alternative;
}

void MapObstacle::switchDefaultInteraction()
{
	if (alternativeInteraction != nullptr)
	{
		Interaction* buffer = defaultInteraction;
		defaultInteraction = alternativeInteraction;
		alternativeInteraction = buffer;
	}
}

Interaction * MapObstacle::getMyDefaultInteraction()
{
	return defaultInteraction;
}

bool MapObstacle::canPlayerInteractWith()
{
	if(defaultInteraction != nullptr)
		return true;
	return false;
}

Inventory * MapObstacle::getInventory()
{
	return myInventory;
}
