#pragma once
#include "Creature.h"
class NonPlayerCharacter :
	public Creature
{
public:
	NonPlayerCharacter(std::string name, bool isEnemy);
	~NonPlayerCharacter();

	Point tryToMove();
	void makeTriedMove();
	void unfriendMyself();
	bool canPlayerInteractWith();
	bool isEnemy;

private:
	int circlePosition;
	Point myNewPosition;

	void moveInCircle();
};

