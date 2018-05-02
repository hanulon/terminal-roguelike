#include "stdafx.h"
#include "Controller.h"
#include "Controller.h"


string Controller::gameMapState;
string Controller::playerSheet;
string Controller::playerShortInfo;
int Controller::attributePointsLeft;
int Controller::skillPointsLeft;

Controller::Controller()
{
	skillPointsLeft = 0;
}


Controller::~Controller()
{
}

void Controller::refresh()
{
	clearScreen();
	printScreen();
}

void Controller::updateAll(string gameMap, string sheet, string shortInfo, int attributePoints, int skillPoints)
{
	gameMapState = gameMap;
	playerSheet = sheet;
	playerShortInfo = shortInfo;
	attributePointsLeft = attributePoints;
	skillPointsLeft = skillPoints;
}

void Controller::pressAnyKey()
{
	cout << "Press any key to return to the menu...";
	_getch(); //WINSPEC
}

string Controller::trim(string str)
{
	int startPosition = 0;
	int endPosition = str.length() - 1;
	while (str[startPosition] == ' ')
		startPosition++;
	while (str[endPosition] == ' ')
		endPosition--;
	return str.substr(startPosition, endPosition - startPosition + 1);
}

void Controller::clearScreen()
{
	#ifdef WINDOWS
		system("cls");
	#endif
	#ifdef LINUX
		system("clear");
	#endif
}
