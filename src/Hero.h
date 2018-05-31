#pragma once
#include "Creature.h"
class Hero :
	public Creature
{
public:
	Hero() : Creature("New hero") {};
	~Hero();

	void setAttributeOrSkillHeroCreator(std::string attributeSkillName, int value);
	int getAttributePointsLeft();
	int getSkillPointsLeft();
	void interactWith(MapObstacle* obstacle);

private:
	int attributePointsLeft = 6;
	int skillPointsLeft = 12;
};