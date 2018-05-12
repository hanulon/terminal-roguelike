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

void Map::addObstacleToMap(MapObstacle * obstacle, Point position)
{
	map[position.y][position.x].addOccupant(obstacle);
}

void Map::removeObstacleFromMapTile(Point position)
{
	this->map[position.y][position.x].removeOccupant();
}

void Map::moveCreatureToDesiredPosition(MapObstacle * creature, Point position)
{
	removeObstacleFromMapTile(creature->getMapPosition());
	addObstacleToMap(creature, position);
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

MapObstacle * Map::getObstacleFrom(Point position)
{
	if (isTheTileOccupied(position) == true)
		return getTileByCoordinates(position)->getOccupant();
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
