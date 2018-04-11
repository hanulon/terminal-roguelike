#include "stdafx.h"
#include "Attributes.h"

static const std::string shortNames[] = { "(N)","(M)","(D)","(S)" };
const std::string* Attributes::shortNamesOfAttributes = shortNames;

Attributes::Attributes()
{
	this->might = 1;
	this->dexterity = 1;
	this->smarts = 1;
}


Attributes::~Attributes()
{
}

int Attributes::getMight()
{
	return this->might;
}

int Attributes::getDexterity()
{
	return this->dexterity;
}

int Attributes::getSmarts()
{
	return this->smarts;
}

int Attributes::getAttributeByEnum(AttributeName attributeName)
{
	switch (attributeName)
	{
	case Might:
		return this->might;
	case Dexterity:
		return this->dexterity;
	case Smarts:
		return this->smarts;
	}
}

int* Attributes::getAttributePointerByStringName(std::string name)
{
	if (name == "Might")
		return &(this->might);
	else if (name == "Dexterity")
		return &(this->dexterity);
	else if (name == "Smarts")
		return &(this->smarts);
	return nullptr;
}

std::string Attributes::getAttributesOnCharacterSheet()
{
	std::string attributeSheet = "\nATTRIBUTES\n";
	attributeSheet += "MIGHT: " + std::to_string(this->might);
	attributeSheet += "\tDEXTERITY: " + std::to_string(this->dexterity);
	attributeSheet += "\tSMARTS: " + std::to_string(this->smarts);

	return attributeSheet;
}

void Attributes::setAttributes(int might, int dexterity, int smarts)
{
	this->might = might;
	this->dexterity = dexterity;
	this->smarts = smarts;
}
