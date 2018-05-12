#pragma once
#include "MapObstacle.h"

class Tile
{
public:
	char getGraphic();
	void clearTile();
	void addOccupant(MapObstacle* obstacle);
	void removeOccupant();
	MapObstacle* getOccupant();

	Tile();
	~Tile();

private:
	char graphic;
	MapObstacle* tileOccupant;
};

