#pragma once

#include "MapObstacle.h"
#include "Attributes.h"
#include "Skill.h"
#include "Health.h"
#include "Equipment.h"

class Creature : public MapObstacle
{
public:
	Creature(std::string name);
	~Creature();

	std::string getCharacterSheet();
	std::string getGeneralInfo();
	void setMaximumHealthPoints(int healthPoints);
	void setCurrentHealthPoints(int healthPoints);
	void setArmorClass(int armorClass);
	void setAttributes(int might, int dexterity, int smarts);

	void setCombatSkillByName(std::string skillName, int value);
	void setOtherSkillByName(std::string skillName, int value);
	int getSkillByName(std::string skillName);

	void testInitialization();

	Inventory* getInventory();
	Equipment* getEquipment();

protected:
	Attributes attributes;

private:
	Health characterHealth;
	int armorClass;
	std::vector <Skill> combatSkills;
	std::vector <Skill> otherSkills;
	Equipment* myEquipment;

	void setSkillByNameFromVector(std::string skillName, int value, std::vector <Skill> *skillVector);
	int getSkillByNameFromVector(std::string skillName, std::vector <Skill> *skillVector);
};

