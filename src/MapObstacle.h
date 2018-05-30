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
	virtual void interactWith(InteractiveObstacle* player);
	void setMyInteractions(Interaction* defaulty, Interaction* alternative = nullptr);

protected:
	std::string name;
	Point mapPosition;
	vector <Item> possessedItems;
	bool useAlternativeInteraction = false;
	Interaction* defaultInteraction;
	Interaction* alternativeInteraction;
};

