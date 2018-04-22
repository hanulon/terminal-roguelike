#pragma once

#include "Attributes.h"
#include "Skill.h"
#include "Health.h"

class Creature
{
public:
	Creature(std::string name);
	~Creature();

	char getNameFirstLetter();
	std::string getCharacterSheet();
	std::string getGeneralInfo();
	void setMaximumHealthPoints(int healthPoints);
	void setCurrentHealthPoints(int healthPoints);
	void setArmorClass(int armorClass);
	void setAttributes(int might, int dexterity, int smarts);
	void setName(std::string name);
	void setMapPosition(int posX, int posY);
	Point getMapPosition();

	void setCombatSkillByName(std::string skillName, int value);
	void setOtherSkillByName(std::string skillName, int value);
	int getSkillByName(std::string skillName);

	void testInitialization();
protected:
	Attributes attributes;
private:
	Health characterHealth;
	std::string name;
	int armorClass;
	std::vector <Skill> combatSkills;
	std::vector <Skill> otherSkills;
	Point mapPosition;

	void setSkillByNameFromVector(std::string skillName, int value, std::vector <Skill> *skillVector);
	int getSkillByNameFromVector(std::string skillName, std::vector <Skill> *skillVector);
};

