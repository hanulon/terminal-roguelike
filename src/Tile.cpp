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
	clearTile();
}

MapObstacle * Tile::getOccupant()
{
	return this->tileOccupant;
}
