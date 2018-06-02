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

Interaction* Interaction::reaction()
{
	if (subInteractions.size() == 0)
	{
		system("pause");
		return subDefault;
	}
	else
	{
		int keyCode;
		while (true)
		{
			keyCode = _getch() - 48;
			if (keyCode > 0 && keyCode <= subInteractions.size())
			{
				subInteractions[keyCode - 1]->setPlayerAndObstacle(player, obstacle);
				if (subInteractions[keyCode - 1]->checkAllConditions())
				{
					return subInteractions[keyCode - 1];
				}
			}
		}
	}
}

std::string Interaction::getMessage()
{
	chosenOnce = true;
	return message;
}

void Interaction::realizeSideActions()
{
	giveItemsToPlayer();
	giveItemsToObstacle();

	if (conditionsSet.defaultInteractionSwitcher)
	{
		obstacle->switchDefaultInteraction();
	}

	if (conditionsSet.unfriend)
	{
		obstacle->unfriendMyself();
	}
}

Interaction * Interaction::reactToDecision(int subNumber)
{
	if (subInteractions.size() == 0)
	{
		return subDefault;
	}
	else if(subNumber>0 && subNumber<=subInteractions.size())
	{
		subInteractions[subNumber - 1]->setPlayerAndObstacle(player, obstacle);
		if (subInteractions[subNumber - 1]->checkAllConditions())
		{
			return subInteractions[subNumber - 1];
		}
	}
	return this;
}

bool Interaction::checkAllConditions()
{
	for (int i = 0; i < conditionsSet.isOnceConditions.size(); i++)
	{
		if (conditionsSet.isOnceConditions[i]->chosenOnce == false)
		{
			return false;
		}
	}
	for (int i = 0; i < conditionsSet.playerConditions.size(); i++)
	{
		if (!(player->getSkillByName(conditionsSet.playerConditions[i].name) >= conditionsSet.playerConditions[i].desiredValue))
		{
			return false;
		}
	}
	if (conditionsSet.obstacleItemsRequired && obstacle->obstacleHasNoItems())
	{
		return false;
	}
	if (conditionsSet.playerItemsRequired && player->obstacleHasNoItems())
	{
		return false;
	}
	return true;
}

void Interaction::giveItemsToPlayer()
{
	if (conditionsSet.obstacleItemsRequired)
	{
		vector <Item> itemsFromComputer = obstacle->getAllItemsAndRemove();
		for (int i = 0; i < itemsFromComputer.size(); i++)
		{
			player->addNewItem(itemsFromComputer[i]);
		}
	}
}

void Interaction::giveItemsToObstacle()
{
	if (conditionsSet.playerItemsRequired)
	{
		vector <Item> itemsFromPlayer = player->getAllItemsAndRemove();
		for (int i = 0; i < itemsFromPlayer.size(); i++)
		{
			obstacle->addNewItem(itemsFromPlayer[i]);
		}
	}
}
