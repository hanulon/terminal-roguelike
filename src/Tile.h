#pragma once
#include "Creature.h"

class Tile
{
public:
	char getGraphic();
	void clearTile();
	void addCreature(Creature* creatureOnMe);

	Tile();
	~Tile();

private:
	char graphic;
	Creature* creatureOnTile;
};

