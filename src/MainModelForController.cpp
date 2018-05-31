#include "stdafx.h"
#include "MainModelForController.h"


MainModelForController::MainModelForController()
{
}


MainModelForController::~MainModelForController()
{
}

void MainModelForController::initMe()
{
	linkFromController = new ControllerToModelConnector();
}

void MainModelForController::changeNewCharacterName(std::string name)
{
	linkFromController->changeNewCharacterName(name);
}

void MainModelForController::changeNewHeroAttributeSkill(std::string attributeSkillName, int value)
{
	linkFromController->changeNewHeroAttributeSkill(attributeSkillName, value);
}

void MainModelForController::endTheTurn()
{
	linkFromController->endTurn();
}

void MainModelForController::takeItemFromYourTile()
{
	linkFromController->takeItemFromYourTile();
}

void MainModelForController::makePlayerStep(Point step)
{
	linkFromController->makePlayerStep(step);
}

ControllerToModelConnector::UserAction MainModelForController::signalAction()
{
	return linkFromController->signalAction();
}

std::string MainModelForController::getNewHeroName()
{
	return linkFromController->getNewHeroName();
}

std::string MainModelForController::getAttributeSkillName()
{
	return linkFromController->getAttributeSkillName();
}

int MainModelForController::getAttributeSkillValue()
{
	return linkFromController->getAttributeSkillValue();
}

void MainModelForController::clearActionSignal()
{
	linkFromController->clearActionSignal();
}

Point MainModelForController::getPlayerStep()
{
	return linkFromController->getPlayerStep();
}
