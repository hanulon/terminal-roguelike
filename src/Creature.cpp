#include "stdafx.h"
#include "Creature.h"

using namespace std;

Creature::Creature(string name) : MapObstacle(name)
{
	this->characterHealth.currentHealthPoints = this->characterHealth.maximumHealthPoints = 1;
	this->armorClass = 0;
	this->combatSkills.push_back(Skill("Melee", Attributes::Might));
	this->combatSkills.push_back(Skill("Evade", Attributes::Dexterity));
	this->combatSkills.push_back(Skill("Firearms", Attributes::Dexterity));
	this->combatSkills.push_back(Skill("Parry", Attributes::Might));
	this->otherSkills.push_back(Skill("Athletics", Attributes::Might));
	this->otherSkills.push_back(Skill("Hacking", Attributes::Smarts));
	this->otherSkills.push_back(Skill("Hide", Attributes::Dexterity));
	this->otherSkills.push_back(Skill("Knowledge", Attributes::Smarts));
	this->otherSkills.push_back(Skill("Perception", Attributes::Smarts));
	this->otherSkills.push_back(Skill("Persuasion", Attributes::Smarts));
	this->otherSkills.push_back(Skill("Thievery", Attributes::Dexterity));

	this->myEquipment = new Equipment();
}

Creature::~Creature(){}


string Creature::getCharacterSheet()
{
	string characterSheet = this->name + "\n";
	characterSheet += this->characterHealth.getHealthOnCharacterSheet();
	characterSheet += "\tAC: " + to_string(getArmorClass());
	characterSheet += this->attributes.getAttributesOnCharacterSheet();
	characterSheet += "\n\nCOMBAT SKILLS\n";
	for (int i = 0; i < this->combatSkills.size(); i++)
		characterSheet += (this->combatSkills[i]).getSkillOnCharacterSheet(&(this->attributes));
	characterSheet += "\nOTHER SKILLS\n";
	for (int i = 0; i < this->otherSkills.size(); i++)
		characterSheet += (this->otherSkills[i]).getSkillOnCharacterSheet(&(this->attributes));
	return characterSheet;
}

std::string Creature::getGeneralInfo()
{
	std::string generalInfo = this->name + "\t";
	generalInfo += this->characterHealth.getHealthOnCharacterSheet();
	generalInfo += "\tAC: " + to_string(getArmorClass());
	generalInfo += "\tMelee bonus: " + to_string(getMeleeAttack() + getSkillByName("Melee"));
	generalInfo += "\nEquipped items:\n";
	generalInfo += getEquipment()->getEquippedItemsList();
	return generalInfo;
}

void Creature::setMaximumHealthPoints(int healthPoints)
{
	this->characterHealth.maximumHealthPoints = healthPoints;
}

void Creature::setCurrentHealthPoints(int healthPoints)
{
	this->characterHealth.currentHealthPoints = healthPoints;
}

void Creature::setArmorClass(int armorClass)
{
	this->armorClass = armorClass;
}

void Creature::setAttributes(int might, int dexterity, int smarts)
{
	this->attributes.setAttributes(might, dexterity, smarts);
}

void Creature::setCombatSkillByName(std::string skillName, int value)
{
	this->setSkillByNameFromVector(skillName, value, &(this->combatSkills));
}

void Creature::setOtherSkillByName(std::string skillName, int value)
{
	this->setSkillByNameFromVector(skillName, value, &(this->otherSkills));
}

int Creature::getSkillByName(std::string skillName)
{
	int skillValue = getSkillByNameFromVector(skillName, &(this->combatSkills));
	if(skillValue < 0)
		skillValue = getSkillByNameFromVector(skillName, &(this->otherSkills));
	return skillValue;
}

int Creature::getMeleeAttack()
{
	return myEquipment->getWeaponBonus();
}

void Creature::testInitialization()
{
	this->setMaximumHealthPoints(10);
	this->setCurrentHealthPoints(9);
	this->setArmorClass(1);
	this->setAttributes(6, 8, 10);
	this->setCombatSkillByName("Melee", 1);
	this->setCombatSkillByName("Evade", 0);
	this->setCombatSkillByName("Firearms", 2);
	this->setCombatSkillByName("Parry", 2);
	this->setOtherSkillByName("Athletics", 0);
	this->setOtherSkillByName("Hacking", 1);
	this->setOtherSkillByName("Hide", 1);
	this->setOtherSkillByName("Knowledge", 0);
	this->setOtherSkillByName("Perception", 4);
	this->setOtherSkillByName("Persuasion", 0);
	this->setOtherSkillByName("Thievery", 3);
}

Inventory * Creature::getInventory()
{
	return myEquipment;
}

Equipment * Creature::getEquipment()
{
	return myEquipment;
}

void Creature::setSkillByNameFromVector(std::string skillName, int value, std::vector<Skill>* skillVector)
{
	for (int i = 0; i < skillVector->size(); i++)
	{
		if ((*skillVector)[i].isMyName(skillName))
			(*skillVector)[i].setValue(value);
	}
}

int Creature::getSkillByNameFromVector(std::string skillName, std::vector<Skill>* skillVector)
{
	for (int i = 0; i < skillVector->size(); i++)
	{
		if ((*skillVector)[i].isMyName(skillName))
			return (*skillVector)[i].getValue();
	}
	return -1;
}

int Creature::getArmorClass()
{
	return this->armorClass + getEquipment()->getArmorBonus();
}
