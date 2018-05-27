#pragma once
#include "MapObstacle.h"
#include "Hero.h"

class Interaction
{
public:
	Interaction();
	~Interaction();

	struct DialogSkillAttrCondition
	{
		std::string name;
		int desiredValue;
	};

	static MapObstacle* obstacle;
	static Hero* player;
	static bool interactionEnd;
	static bool changeDefaultInteraction;
	bool chosenOnce = false;
	std::string message;
	bool reaction();
	std::vector <Interaction*> subInteractions;
	std::vector <Interaction*> isOnceConditions;
	std::vector <DialogSkillAttrCondition> playerConditions;
	bool obstacleItemsRequired = false;
	bool playerItemsRequired = false;
	bool interactionQuitter = false;
	bool defaultInteractionSwitcher = false;

private:
	bool checkAllConditions();
};

