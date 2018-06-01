#include "stdafx.h"
#include "MainModelForController.h"


MainModelForController::MainModelForController()
{
}


MainModelForController::~MainModelForController()
{
}

void MainModelForController::changeNewCharacterName(std::string name)
{
	this->actionType = NameChanged;
	this->name = name;
}

void MainModelForController::changeNewHeroAttributeSkill(std::string attributeSkillName, int value)
{
	this->actionType = AttrSkillChanged;
	this->attributeSkillName = attributeSkillName;
	this->value = value;
}

void MainModelForController::endTheTurn()
{
	this->actionType = TurnEnded;
}

void MainModelForController::takeItemFromYourTile()
{
	this->actionType = TakeItemFromFloor;
}

void MainModelForController::makePlayerStep(Point step)
{
	this->step = step;
	endTheTurn();
}

MainModelForController::UserAction MainModelForController::signalAction()
{
	return this->actionType;
}

std::string MainModelForController::getNewHeroName()
{
	return this->name;
}

std::string MainModelForController::getAttributeSkillName()
{
	return this->attributeSkillName;
}

int MainModelForController::getAttributeSkillValue()
{
	return this->value;
}

void MainModelForController::clearActionSignal()
{
	this->actionType = NoAction;
	this->step = Point();
	this->name = "";
	this->attributeSkillName = "";
	this->value = 0;
}

Point MainModelForController::getPlayerStep()
{
	return this->step;
}
