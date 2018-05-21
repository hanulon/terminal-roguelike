#pragma once
#include "MapObstacle.h"
#include "Item.h"

class Tile
{
public:
	char getGraphic();
	void clearTile();
	void addOccupant(MapObstacle* obstacle);
	void removeOccupant();
	MapObstacle* getOccupant();
	std::string getItemsNames();
	void addItem(Item newItem);
	Item getAndRemoveTopItem();

	Tile();
	~Tile();

private:
	char graphic;
	MapObstacle* tileOccupant;
	std::vector <Item> tileItems;
};

