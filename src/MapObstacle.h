#pragma once
#include "Item.h"
#include "InteractiveObstacle.h"
#include "Interaction.h"

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
	void setMyInteractions(Interaction* defaulty, Interaction* alternative = nullptr);
	void switchDefaultInteraction();
	Interaction* getMyDefaultInteraction();

protected:
	std::string name;
	Point mapPosition;
	vector <Item> possessedItems;
	Interaction* defaultInteraction;
	Interaction* alternativeInteraction;
};

