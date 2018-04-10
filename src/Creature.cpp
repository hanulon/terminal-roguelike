#include "stdafx.h"
#include "Creature.h"

using namespace std;

Creature::Creature(string name)
{
	this->name = name;
	this->characterHealth.currentHealthPoints = this->characterHealth.maximumHealthPoints = 1;
	this->armorClass = 0;

	this->combatSkills.push_back(Skill("Close Combat", Might));
	this->combatSkills.push_back(Skill("Evade", Dexterity));
	this->combatSkills.push_back(Skill("Firearms", Dexterity));
	this->combatSkills.push_back(Skill("Parry", Might));

	this->otherSkills.push_back(Skill("Athletics", Might));
	this->otherSkills.push_back(Skill("Hacking", Smarts));
	this->otherSkills.push_back(Skill("Hide", Dexterity));
	this->otherSkills.push_back(Skill("Knowledge", Smarts));
	this->otherSkills.push_back(Skill("Perception", Smarts));
	this->otherSkills.push_back(Skill("Persuasion", Smarts));
	this->otherSkills.push_back(Skill("Thievery", Dexterity));
}


Creature::~Creature()
{
}

string Creature::getCharacterSheet()
{
	string characterSheet = this->name + "\n";
	characterSheet += this->characterHealth.getHealthOnCharacterSheet();
	characterSheet += "\tAC: " + to_string(this->armorClass);
	characterSheet += this->attr.getAttributesOnCharacterSheet();
	characterSheet += "\n\nCOMBAT SKILLS\n";
	for (int i = 0; i < this->combatSkills.size(); i++)
		characterSheet += (this->combatSkills[i]).getSkillOnCharacterSheet(&(this->attr));
	characterSheet += "\nOTHER SKILLS\n";
	for (int i = 0; i < this->otherSkills.size(); i++)
		characterSheet += (this->otherSkills[i]).getSkillOnCharacterSheet(&(this->attr));
	//characterSheet += this->athletics.getSkillOnCharacterSheet(&(this->attr));
	//characterSheet += this->hacking.getSkillOnCharacterSheet(&(this->attr));
	//characterSheet += this->hide.getSkillOnCharacterSheet(&(this->attr));
	//characterSheet += this->knowledge.getSkillOnCharacterSheet(&(this->attr));
	//characterSheet += this->perception.getSkillOnCharacterSheet(&(this->attr));
	//characterSheet += this->persuasion.getSkillOnCharacterSheet(&(this->attr));
	//characterSheet += this->thievery.getSkillOnCharacterSheet(&(this->attr));

	return characterSheet;
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
	this->attr.setAttributes(might, dexterity, smarts);
}

void Creature::setCombatSkillByName(std::string skillName, int value)
{
	this->setSkillByNameFromVector(skillName, value, &(this->combatSkills));
}

void Creature::setOtherSkillByName(std::string skillName, int value)
{
	this->setSkillByNameFromVector(skillName, value, &(this->otherSkills));
}

void Creature::setSkillByNameFromVector(std::string skillName, int value, std::vector<Skill>* skillVector)
{
	for (int i = 0; i < skillVector->size(); i++)
	{
		if ((*skillVector)[i].isMyName(skillName))
			(*skillVector)[i].setValue(value);
	}
}
