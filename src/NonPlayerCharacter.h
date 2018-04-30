#pragma once
#include "Creature.h"
class NonPlayerCharacter :
	public Creature
{
public:
	NonPlayerCharacter(std::string name, bool isEnemy);
	~NonPlayerCharacter();

	void moveInCircle();
	bool isEnemy;

private:
	int circlePosition;
};

