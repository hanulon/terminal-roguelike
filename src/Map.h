#pragma once
#include "Tile.h"

class Map
{
public:
	Map();
	~Map();

	std::string printMap();
	void testingMapInitialization();
	void addObstacleToMap(MapObstacle* obstacle, Point position);
	void removeObstacleFromMapTile(Point position);
	void moveCreatureToDesiredPosition(MapObstacle* creature, Point position);
	bool isTheTileOccupied(Point position);
	MapObstacle* getObstacleFrom(Point position);
	bool areCoordinatesWithinBonds(Point position);
	std::string getItemsNamesFrom(Point position);
	void addItemTo(Point position, Item newItem);
	Item getAndRemoveTopItemFrom(Point position);

private:
	static const unsigned int mapHeight = 20;
	static const unsigned int mapWidth = 40;
	Tile map[mapHeight][mapWidth];
	Tile* getTileByCoordinates(Point coords);
};

