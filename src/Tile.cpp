#include "stdafx.h"
#include "Tile.h"


Tile::Tile()
{
	this->graphic = '#';
	this->creatureOnTile = nullptr;
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

void Tile::addCreature(Creature* creatureOnMe)
{
	this->creatureOnTile = creatureOnMe;
	this->graphic = creatureOnMe->getNameFirstLetter();
}

void Tile::removeCreature()
{
	this->creatureOnTile = nullptr;
	clearTile();
}

Creature * Tile::getCreature()
{
	return this->creatureOnTile;
}
