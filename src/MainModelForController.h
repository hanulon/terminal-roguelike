#pragma once

class MainModelForController
{
public:
	MainModelForController();
	~MainModelForController();

	virtual void changeNewCharacterName(std::string name) = 0;
	virtual void changeNewHeroAttributeSkill(std::string attributeSkillName, int value) = 0;
	virtual void makePlayerStep(Point step) = 0;
	virtual void endTurn() = 0;
	virtual void playerTakeItemFromFloor() = 0;

	virtual std::string getDisplayedMap() = 0;
	virtual std::string getPlayerCharacterSheet() = 0;
	virtual std::string getPlayerGeneralInfo() = 0;
	virtual int getPlayerAttributePointsLeft() = 0;
	virtual int getPlayerSkillPointsLeft() = 0;

};

