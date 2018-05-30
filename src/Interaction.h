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
	void setPlayerAndObstacle(InteractiveObstacle* player, InteractiveObstacle* intObstacle);
	void setInteractionEndAndDefaultChange(bool* interEnd, bool* defaultInterChange);
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
	bool unfriend = false;

private:
	InteractiveObstacle* obstacle;
	InteractiveObstacle* player;
	bool* interactionEnd;
	bool* changeDefaultInteraction;
	bool checkAllConditions();
};

