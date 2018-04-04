#include "stdafx.h"
#include "Tile.h"


char Tile::getGraphic()
{
	return this->graphic;
}

void Tile::clearTile()
{
	this->graphic = 0;
}

Tile::Tile()
{
	this->graphic = '#';
}


Tile::~Tile()
{
}
