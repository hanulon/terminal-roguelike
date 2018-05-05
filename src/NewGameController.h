#pragma once
#include "Controller.h"
class NewGameController :
	public Controller
{
public:
	NewGameController();
	~NewGameController();

	Controller* processUserInput();

	static void updatePlayerSheet(string sheet);
	static void updateCreationPointsLeft(int attributePoints, int skillPoints);

private:
	void interpretCommand(string command);
	void finishCmd();
	void interpretCommandWithArguments(string command);
	void interpretTwoArgumentedCommand(string firstCommandToken, string secondCommandToken);
	void printScreen();
	void printInstruction();
	vector <string> splitString(string splitted);

	static string playerSheet;
	static int attributePointsLeft;
	static int skillPointsLeft;
};

