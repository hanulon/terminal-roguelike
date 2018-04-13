#include "stdafx.h"
#include "Hero.h"

Hero::~Hero()
{
}

void Hero::setAttributeOrSkillHeroCreator(std::string attributeSkillName, int value)
{
	int difference;
	int* attribute = this->attributes.getAttributePointerByStringName(attributeSkillName);
	if (attribute != nullptr && value > 0)
	{
		difference = value - *attribute;
		if (difference <= this->attributePointsLeft)
		{
			this->attributePointsLeft -= difference;
			*attribute = value;
		}
	}
	else
	{
		difference = value - this->getSkillByName(attributeSkillName);
		if (difference <= this->skillPointsLeft)
		{
			this->skillPointsLeft -= difference;
			this->setCombatSkillByName(attributeSkillName, value);
			this->setOtherSkillByName(attributeSkillName, value);
		}

	}
}

int Hero::getAttributePointsLeft()
{
	return this->attributePointsLeft;
}

int Hero::getSkillPointsLeft()
{
	return this->skillPointsLeft;
}
