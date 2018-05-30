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

void Interaction::setInteractionEndAndDefaultChange(bool * interEnd, bool * defaultInterChange)
{
	this->interactionEnd = interEnd;
	this->changeDefaultInteraction = defaultInterChange;
}

bool Interaction::reaction()
{
	if (checkAllConditions())
	{
		return true;
	}

	chosenOnce = true;
	if (obstacleItemsRequired)
	{
		vector <Item> itemsFromComputer = obstacle->getAllItemsAndRemove();
		for (int i = 0; i < itemsFromComputer.size(); i++)
		{
			player->addNewItem(itemsFromComputer[i]);
		}
	}
	if (playerItemsRequired)
	{
		vector <Item> itemsFromPlayer = player->getAllItemsAndRemove();
		for (int i = 0; i < itemsFromPlayer.size(); i++)
		{
			obstacle->addNewItem(itemsFromPlayer[i]);
		}
	}

	if (defaultInteractionSwitcher)
	{
		*changeDefaultInteraction = true;
	}

	if (*interactionEnd)
	{
		return false;
	}
	
	if (interactionQuitter)
	{
		*interactionEnd = true;
		cout << message;
		system("pause");
		return false;
	}
	if (subInteractions.size() == 0)
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
			if (keyCode > 0 && keyCode <= subInteractions.size())
			{
				subInteractions[keyCode - 1]->setPlayerAndObstacle(player, obstacle);
				subInteractions[keyCode - 1]->setInteractionEndAndDefaultChange(interactionEnd, changeDefaultInteraction);
				menuLoop = subInteractions[keyCode - 1]->reaction();
			}
		}
		return false;
	}
}

bool Interaction::checkAllConditions()
{
	for (int i = 0; i < isOnceConditions.size(); i++)
	{
		if (isOnceConditions[i]->chosenOnce == false)
		{
			return true;
		}
	}
	for (int i = 0; i < playerConditions.size(); i++)
	{
		if (!(player->getSkillByName(playerConditions[i].name) >= playerConditions[i].desiredValue))
		{
			return true;
		}
	}
	if (obstacleItemsRequired && obstacle->obstacleHasNoItems())
	{
		return true;
	}
	if (playerItemsRequired && player->obstacleHasNoItems())
	{
		return true;
	}
	return false;
}
