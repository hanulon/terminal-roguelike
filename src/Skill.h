#pragma once
#include "Attributes.h"

class Skill
{
public:
	Skill(std::string name, AttributeName connectedAttribute, unsigned int value = 0);
	~Skill();

	int getValue();
	std::string getName();
	std::string getShortName();
	AttributeName getConnectedAttribute();
	std::string getSkillOnCharacterSheet(Attributes* characterAttributes);
	void setValue(unsigned int value);
	void setName(std::string name);
	void setShortName(std::string shortName);
	void setConnectedAttribute(AttributeName attributeName);

	bool isMyName(std::string matchingName);

private:
	std::string name;
	std::string shortName;
	unsigned int value;
	AttributeName connectedAttribute;
};

