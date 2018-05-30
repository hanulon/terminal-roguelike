#include "stdafx.h"
#include "MapObstacle.h"


MapObstacle::MapObstacle(std::string name)
{
	this->name = name;
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

void MapObstacle::addNewItem(Item newItem)
{
	this->possessedItems.push_back(newItem);
}

std::string MapObstacle::getListOfPossessedItems()
{
	std::string listOfItems = "";
	for (int i = 0; i < possessedItems.size(); i++)
	{
		listOfItems += possessedItems[i].getName() + "\n";
	}
	return listOfItems;
}

vector<Item> MapObstacle::getAllItemsAndRemove()
{
	vector <Item> items = possessedItems;
	possessedItems.clear();
	return items;
}

bool MapObstacle::obstacleHasNoItems()
{
	if (possessedItems.size() > 0)
		return false;
	return true;
}

void MapObstacle::interactWith(InteractiveObstacle * player)
{
	bool endOfInteraction = false;
	Interaction* currentDialog;
	while (!endOfInteraction)
	{
		if (this->useAlternativeInteraction)
			currentDialog = this->alternativeInteraction;
		else
			currentDialog = this->defaultInteraction;
		currentDialog->setInteractionEndAndDefaultChange(&endOfInteraction, &(this->useAlternativeInteraction));
		currentDialog->setPlayerAndObstacle(player, this);
		currentDialog->reaction();
	}
}

void MapObstacle::setMyInteractions(Interaction * defaulty, Interaction * alternative)
{
	if (alternative == nullptr)
		alternative = defaulty;
	this->defaultInteraction = defaulty;
	this->alternativeInteraction = alternative;
}
