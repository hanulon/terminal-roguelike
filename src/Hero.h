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

	void startInteractionWith(MapObstacle* obstacle);
	void passSubInteractionDecision(int dubNumber);
	std::string getInteractionMessage();
	bool hasOngoingInteractionEnded();
	int getSubinteractionsNumber();

private:
	Interaction* ongoingInteraction = nullptr;
	int attributePointsLeft = 6;
	int skillPointsLeft = 12;
};