#pragma once

#include "Attributes.h"
#include "Skill.h"
#include "Health.h"

class Creature
{
public:
	Creature(std::string name);
	~Creature();

	std::string getCharacterSheet();
	void setMaximumHealthPoints(int healthPoints);
	void setCurrentHealthPoints(int healthPoints);
	void setArmorClass(int armorClass);
	void setAttributes(int might, int dexterity, int smarts);

	void setCombatSkillByName(std::string skillName, int value);
	void setOtherSkillByName(std::string skillName, int value);

private:
	Health characterHealth;
	std::string name;
	int armorClass;
	Attributes attr;
	std::vector <Skill> combatSkills;
	std::vector <Skill> otherSkills;

	void setSkillByNameFromVector(std::string skillName, int value, std::vector <Skill> *skillVector);
};

