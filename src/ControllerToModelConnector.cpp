#include "stdafx.h"
#include "ControllerToModelConnector.h"


ControllerToModelConnector::ControllerToModelConnector()
{
	actionType = NoAction;
}


ControllerToModelConnector::~ControllerToModelConnector()
{
}

void ControllerToModelConnector::endTurn()
{
	this->actionType = TurnEnded;
}

void ControllerToModelConnector::makePlayerStep(Point step)
{
	this->step = step;
	endTurn();
}

void ControllerToModelConnector::changeNewHeroAttributeSkill(std::string attributeSkillName, int value)
{
	this->actionType = AttrSkillChanged;
	this->attributeSkillName = attributeSkillName;
	this->value = value;
}

void ControllerToModelConnector::changeNewCharacterName(std::string)
{
	this->actionType = NameChanged;
	this->name = name;
}

void ControllerToModelConnector::takeItemFromYourTile()
{
	this->actionType = TakeItemFromFloor;
}

ControllerToModelConnector::UserAction ControllerToModelConnector::signalAction()
{
	return this->actionType;
}

void ControllerToModelConnector::clearActionSignal()
{
	this->actionType = NoAction;
	this->step = Point();
	this->name = "";
	this->attributeSkillName = "";
	this->value = 0;
}

Point ControllerToModelConnector::getPlayerStep()
{
	return this->step;
}

std::string ControllerToModelConnector::getNewHeroName()
{
	return this->name;
}

std::string ControllerToModelConnector::getAttributeSkillName()
{
	return this->attributeSkillName;
}

int ControllerToModelConnector::getAttributeSkillValue()
{
	return this->value;
}
