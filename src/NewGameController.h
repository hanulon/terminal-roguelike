#pragma once
#include "Controller.h"
class NewGameController :
	public Controller
{
public:
	NewGameController();
	~NewGameController();

	Controller* processUserInput();

private:
	void interpretCommand(string command);
	void finishCmd();
	void interpretCommandWithArguments(string command);
	void interpretTwoArgumentedCommand(string firstCommandToken, string secondCommandToken);
	void printScreen();
	void printInstruction();
};

