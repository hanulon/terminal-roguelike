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

void Map::moveCreatureToDesiredPosition(Creature * creature, Point position)
{
	removeCreatureFromMapTile(creature->getMapPosition());
	addCreatureToMap(creature, position);
}

bool Map::isTheTileOccupied(Point position)
{
	Tile* tile = getTileByCoordinates(position);
	if (tile == nullptr)
		return true;
	if (tile->getGraphic() != 0)
		return true;
	return false;
}

Creature * Map::getCreatureFrom(Point position)
{
	if (isTheTileOccupied(position) == true)
		return getTileByCoordinates(position)->getCreature();
	return nullptr;
}

bool Map::areCoordinatesWithinBonds(Point position)
{
	if (position.x >= 0 && position.x < mapWidth && position.y >= 0 && position.y < mapHeight)
		return true;
	return false;
}

Tile * Map::getTileByCoordinates(Point coords)
{
	if (areCoordinatesWithinBonds(coords))
		return &map[coords.y][coords.x];
	return nullptr;
}
