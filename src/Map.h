#pragma once
#include "Tile.h"

class Map
{
public:
	Map();
	~Map();

	std::string printMap();
	void testingMapInitialization();
	void addCreatureToMap(Creature* creature, Point position);
	void removeCreatureFromMapTile(Point position);
	void moveCreatureToDesiredPosition(Creature* creature, Point position);
	bool isTheTileOccupied(Point position);
	Creature* getCreatureFrom(Point position);
	bool areCoordinatesWithinBonds(Point position);

private:
	static const unsigned int mapHeight = 20;
	static const unsigned int mapWidth = 40;
	Tile map[mapHeight][mapWidth];
	Tile* getTileByCoordinates(Point coords);
};

