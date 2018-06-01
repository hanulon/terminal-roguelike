#pragma once

class MainModelForController
{
public:
	MainModelForController();
	~MainModelForController();

	enum UserAction
	{
		NoAction,
		TurnEnded,
		NameChanged,
		AttrSkillChanged,
		TakeItemFromFloor
	};

	void changeNewCharacterName(std::string name);
	void changeNewHeroAttributeSkill(std::string attributeSkillName, int value);
	void endTheTurn();
	void takeItemFromYourTile();
	void makePlayerStep(Point step);

protected:
	UserAction signalAction();
	std::string getNewHeroName();
	std::string getAttributeSkillName();
	int getAttributeSkillValue();
	void clearActionSignal();
	Point getPlayerStep();

private:
	UserAction actionType;
	Point step;
	std::string name;
	std::string attributeSkillName;
	int value;
};

