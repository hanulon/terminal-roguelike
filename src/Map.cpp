#include "stdafx.h"
#include "Map.h"


Map::Map()
{
}


Map::~Map(){}

std::string Map::printMap()
{
	std::string mapAsString = "";
	for (int y = 0; y < mapHeight; y++)
	{
		for (int x = 0; x < mapWidth; x++)
			mapAsString += map[y][x].getGraphic();
		mapAsString += "\n";
	}
	return mapAsString;
}

void Map::testingMapInitialization()
{
	for (int y = 1; y < mapHeight - 1; y++)
	{
		for (int x = 1; x < mapWidth - 1; x++)
			map[y][x].clearTile();
	}
}

void Map::addCreatureToMap(Creature * creature, Point position)
{
	map[position.y][position.x].addCreature(creature);
}

void Map::removeCreatureFromMapTile(Point position)
{
	this->map[position.y][position.x].removeCreature();
}
