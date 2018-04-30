#include "stdafx.h"
#include "Tile.h"


Tile::Tile()
{
	this->graphic = '#';
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
	this->creatureOnTile = NULL;
	clearTile();
}
