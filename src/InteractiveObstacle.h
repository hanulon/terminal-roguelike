#pragma once
#include "Inventory.h"

class InteractiveObstacle
{
public:
	InteractiveObstacle();
	~InteractiveObstacle();

	virtual Inventory* getInventory() = 0;
	virtual int getSkillByName(std::string skillName);
	virtual void unfriendMyself();
	virtual void switchDefaultInteraction() = 0;
};

