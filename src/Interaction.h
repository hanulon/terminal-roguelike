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
		std::vector <Interaction*> isOnceConditions;
		std::vector <DialogSkillAttrCondition> playerConditions;
		bool obstacleItemsRequired = false;
		bool playerItemsRequired = false;
		bool defaultInteractionSwitcher = false;
		bool unfriend = false;
	};

	std::vector <Interaction*> subInteractions;
	Interaction* subDefault = nullptr;
	void setPlayerAndObstacle(InteractiveObstacle* player, InteractiveObstacle* intObstacle);
	bool chosenOnce = false;
	std::string message;
	Conditions conditionsSet;
	Interaction* reaction();
	std::string getMessage();
	void realizeSideActions();

private:
	InteractiveObstacle* obstacle;
	InteractiveObstacle* player;
	bool checkAllConditions();
	void giveItemsToPlayer();
	void giveItemsToObstacle();
};

