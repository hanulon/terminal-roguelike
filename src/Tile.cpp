#include "stdafx.h"
#include "Tile.h"


Tile::Tile()
{
	this->graphic = '#';
	this->tileOccupant = nullptr;
}

Tile::~Tile(){}

char Tile::getGraphic()
{
	return this->graphic;
}

void Tile::clearTile()
{
	this->graphic = 0;
}

void Tile::addOccupant(MapObstacle* obstacle)
{
	this->tileOccupant = obstacle;
	this->graphic = obstacle->getNameFirstLetter();
}

void Tile::removeOccupant()
{
	this->tileOccupant = nullptr;
	if (tileItems.size() > 0)
		this->graphic = tileItems[0].getName()[0];
	else
		clearTile();
}

MapObstacle * Tile::getOccupant()
{
	return this->tileOccupant;
}

std::string Tile::getItemsNames()
{
	std::string itemsNames = "";
	for (int i = 0; i < tileItems.size(); i++)
	{
		itemsNames += tileItems[i].getName() + "\n";
	}
	return itemsNames;
}

void Tile::addItem(Item newItem)
{
	this->tileItems.push_back(newItem);
	if (graphic == 0)
		this->graphic = newItem.getName()[0];
}
