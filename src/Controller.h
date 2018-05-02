#pragma once
#include <iostream>
#include <conio.h>

using namespace std;

enum UserAction
{
	NoAction,
	TurnEnded,
	NameChanged,
	AttrSkillChanged
};

struct UserControllerMessage
{
	UserAction actionType = NoAction;
	Point step;
	std::string name;
	std::string attributeSkillName;
	int value;
};

class Controller
{
public:
	Controller();
	~Controller();

	virtual Controller* main() = 0;
	virtual void refresh();
	void updateAll(string gameMap, string sheet, string shortInfo, int attributePoints, int skillPoints);
	static UserControllerMessage userControllerMessage;

protected:
	virtual void printScreen() = 0;
	void pressAnyKey();
	string trim(string str);
	void clearScreen();

	static string gameMapState;
	static string playerSheet;
	static string playerShortInfo;
	static int attributePointsLeft;
	static int skillPointsLeft;
};

