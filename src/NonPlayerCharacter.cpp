#include "stdafx.h"
#include "NonPlayerCharacter.h"


NonPlayerCharacter::NonPlayerCharacter(std::string name, bool isEnemy) : Creature(name)
{
	this->isEnemy = isEnemy;
	int circlePosition = 0;
}

NonPlayerCharacter::~NonPlayerCharacter()
{
}

Point NonPlayerCharacter::tryToMove()
{
	myNewPosition = mapPosition;
	moveInCircle();
	return myNewPosition;
}

void NonPlayerCharacter::makeTriedMove()
{
	mapPosition = myNewPosition;
}

void NonPlayerCharacter::unfriendMyself()
{
	isEnemy = true;
}

bool NonPlayerCharacter::canPlayerInteractWith()
{
	if (defaultInteraction == nullptr || isEnemy)
		return false;
	return true;
}

void NonPlayerCharacter::moveInCircle()
{
	switch (circlePosition)
	{
	case 0:
		myNewPosition.x++;
		circlePosition++;
		break;
	case 1:
		myNewPosition.y++;
		circlePosition++;
		break;
	case 2:
		myNewPosition.x--;
		circlePosition++;
		break;
	case 3:
		myNewPosition.y--;
		circlePosition = 0;
		break;
	default:
		break;
	}
}