#pragma once
#include "Item.h"

class MapObstacle
{
public:
	MapObstacle(std::string name);
	virtual ~MapObstacle();

	void setName(std::string name);
	std::string getName();
	char getNameFirstLetter();
	void setMapPosition(Point position);
	Point getMapPosition();
	void addNewItem(Item newItem);
	std::string getListOfPossessedItems();
	vector <Item> getAllItemsAndRemove();

	bool interactable = false;

protected:
	std::string name;
	Point mapPosition;
	vector <Item> possessedItems;
};

