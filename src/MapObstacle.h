#pragma once
#include "Item.h"
#include "InteractiveObstacle.h"
#include "Interaction.h"
#include "Inventory.h"

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

	void setMyInteractions(Interaction* defaulty, Interaction* alternative = nullptr);
	void switchDefaultInteraction();
	Interaction* getMyDefaultInteraction();
	virtual bool canPlayerInteractWith();

	Inventory* getInventory();

protected:
	std::string name;
	Point mapPosition;
	Interaction* defaultInteraction;
	Interaction* alternativeInteraction;

private:
	Inventory myInventory;
};

