#pragma once
class ControllerToModelConnector
{
public:
	ControllerToModelConnector();
	~ControllerToModelConnector();

	enum UserAction
	{
		NoAction,
		TurnEnded,
		NameChanged,
		AttrSkillChanged,
		TakeItemFromFloor
	};

	void endTurn();
	void makePlayerStep(Point step);
	void changeNewHeroAttributeSkill(std::string attributeSkillName, int value);
	void changeNewCharacterName(std::string);
	void takeItemFromYourTile();

	UserAction signalAction();
	void clearActionSignal();
	Point getPlayerStep();
	std::string getNewHeroName();
	std::string getAttributeSkillName();
	int getAttributeSkillValue();

private:
	UserAction actionType;
	Point step;
	std::string name;
	std::string attributeSkillName;
	int value;
};

