#pragma once
#include "Item.h"
#include "InteractiveObstacle.h"

class MapObstacle : public InteractiveObstacle
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
	bool obstacleHasNoItems();

	bool interactable = false;

protected:
	std::string name;
	Point mapPosition;
	vector <Item> possessedItems;
};

