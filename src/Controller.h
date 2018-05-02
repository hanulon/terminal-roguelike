#pragma once
#include <iostream>
#include <conio.h>

using namespace std;

class Controller
{
public:
	Controller();
	~Controller();

	virtual Controller* main() = 0;
	virtual void refresh();
	void updateAll(string gameMap, string sheet, string shortInfo, int attributePoints, int skillPoints);

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

