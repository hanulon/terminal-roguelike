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

void NonPlayerCharacter::moveInCircle()
{
	switch (circlePosition)
	{
	case 0:
		mapPosition.x++;
		circlePosition++;
		break;
	case 1:
		mapPosition.y++;
		circlePosition++;
		break;
	case 2:
		mapPosition.x--;
		circlePosition++;
		break;
	case 3:
		mapPosition.y--;
		circlePosition = 0;
		break;
	default:
		break;
	}
}
