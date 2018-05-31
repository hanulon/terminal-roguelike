#pragma once
#include "ControllerToModelConnector.h"

class MainModelForController
{
public:
	MainModelForController();
	~MainModelForController();

	void initMe();
	void changeNewCharacterName(std::string name);
	void changeNewHeroAttributeSkill(std::string attributeSkillName, int value);
	void endTheTurn();
	void takeItemFromYourTile();
	void makePlayerStep(Point step);

protected:
	ControllerToModelConnector::UserAction signalAction();
	std::string getNewHeroName();
	std::string getAttributeSkillName();
	int getAttributeSkillValue();
	void clearActionSignal();
	Point getPlayerStep();

private:
	ControllerToModelConnector* linkFromController;
};

