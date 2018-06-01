#pragma once
#include "InteractiveObstacle.h"

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

	struct Conditions
	{
		std::vector <Interaction*> subInteractions;
		std::vector <Interaction*> isOnceConditions;
		std::vector <DialogSkillAttrCondition> playerConditions;
		bool obstacleItemsRequired = false;
		bool playerItemsRequired = false;
		bool interactionQuitter = false;
		bool defaultInteractionSwitcher = false;
		bool unfriend = false;
	};

	void setPlayerAndObstacle(InteractiveObstacle* player, InteractiveObstacle* intObstacle);
	void setInteractionEndAndDefaultChange(bool* interEnd);
	bool chosenOnce = false;
	std::string message;
	Conditions conditionsSet;
	bool reaction();

private:
	InteractiveObstacle* obstacle;
	InteractiveObstacle* player;
	bool* interactionEnd;
	bool checkAllConditions();
};

