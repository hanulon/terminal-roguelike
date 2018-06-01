#include "stdafx.h"
#include "Interaction.h"


Interaction::Interaction()
{
}


Interaction::~Interaction()
{
}

void Interaction::setPlayerAndObstacle(InteractiveObstacle * player, InteractiveObstacle* intObstacle)
{
	this->player = player;
	this->obstacle = intObstacle;
}

void Interaction::setInteractionEndAndDefaultChange(bool * interEnd)
{
	this->interactionEnd = interEnd;
}

bool Interaction::reaction()
{
	if (checkAllConditions())
	{
		return true;
	}

	chosenOnce = true;
	if (conditionsSet.obstacleItemsRequired)
	{
		vector <Item> itemsFromComputer = obstacle->getAllItemsAndRemove();
		for (int i = 0; i < itemsFromComputer.size(); i++)
		{
			player->addNewItem(itemsFromComputer[i]);
		}
	}
	if (conditionsSet.playerItemsRequired)
	{
		vector <Item> itemsFromPlayer = player->getAllItemsAndRemove();
		for (int i = 0; i < itemsFromPlayer.size(); i++)
		{
			obstacle->addNewItem(itemsFromPlayer[i]);
		}
	}

	if (conditionsSet.defaultInteractionSwitcher)
	{
		obstacle->switchDefaultInteraction();
	}

	if (conditionsSet.unfriend)
	{
		obstacle->unfriendMyself();
	}

	if (*interactionEnd)
	{
		return false;
	}
	
	if (conditionsSet.interactionQuitter)
	{
		*interactionEnd = true;
		cout << message;
		system("pause");
		return false;
	}
	if (conditionsSet.subInteractions.size() == 0)
	{
		cout << message;
		system("pause");
		return true;
	}
	else
	{
		bool menuLoop = true;
		while (menuLoop)
		{
			cout << message;
			int keyCode = _getch() - 48;
			if (keyCode > 0 && keyCode <= conditionsSet.subInteractions.size())
			{
				conditionsSet.subInteractions[keyCode - 1]->setPlayerAndObstacle(player, obstacle);
				conditionsSet.subInteractions[keyCode - 1]->setInteractionEndAndDefaultChange(interactionEnd);
				menuLoop = conditionsSet.subInteractions[keyCode - 1]->reaction();
			}
		}
		return false;
	}
}

bool Interaction::checkAllConditions()
{
	for (int i = 0; i < conditionsSet.isOnceConditions.size(); i++)
	{
		if (conditionsSet.isOnceConditions[i]->chosenOnce == false)
		{
			return true;
		}
	}
	for (int i = 0; i < conditionsSet.playerConditions.size(); i++)
	{
		if (!(player->getSkillByName(conditionsSet.playerConditions[i].name) >= conditionsSet.playerConditions[i].desiredValue))
		{
			return true;
		}
	}
	if (conditionsSet.obstacleItemsRequired && obstacle->obstacleHasNoItems())
	{
		return true;
	}
	if (conditionsSet.playerItemsRequired && player->obstacleHasNoItems())
	{
		return true;
	}
	return false;
}
