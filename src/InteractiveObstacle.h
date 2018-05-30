#pragma once
#include "Item.h"

class InteractiveObstacle
{
public:
	InteractiveObstacle();
	~InteractiveObstacle();

	virtual vector <Item> getAllItemsAndRemove() = 0;
	virtual void addNewItem(Item newItem) = 0;
	virtual bool obstacleHasNoItems() = 0;
	virtual int getSkillByName(std::string skillName);
	virtual void unfriendMyself();
};

