#include "stdafx.h"
#include "Skill.h"


Skill::Skill(std::string name, AttributeName connectedAttribute, unsigned int value)
{
	this->name = name;
	this->value = value;
	this->connectedAttribute = connectedAttribute;
}


Skill::~Skill()
{
}

int Skill::getValue()
{
	return this->value;
}

std::string Skill::getName()
{
	return this->name;
}

std::string Skill::getShortName()
{
	return this->shortName;
}

AttributeName Skill::getConnectedAttribute()
{
	return this->connectedAttribute;
}

std::string Skill::getSkillOnCharacterSheet(Attributes* characterAttributes)
{
	std::string skillSheet = this->name + "\t";
	if(this->name.length() < 8)
		skillSheet += "\t";
	skillSheet += Attributes::shortNamesOfAttributes[this->connectedAttribute];
	skillSheet += ":\t" + std::to_string(this->value) + "\t(";
	skillSheet += std::to_string(this->value + characterAttributes->getAttributeByEnum(this->connectedAttribute)) + ")\n";
	
	return skillSheet;
}

void Skill::setValue(unsigned int value)
{
	this->value = value;
}

void Skill::setName(std::string name)
{
	this->name = name;
}

void Skill::setShortName(std::string shortName)
{
	this->shortName = shortName;
}

void Skill::setConnectedAttribute(AttributeName attributeName)
{
	this->connectedAttribute = attributeName;
}

bool Skill::isMyName(std::string matchingName)
{
	if (this->name == matchingName)
		return true;
	return false;
}
