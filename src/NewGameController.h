#pragma once
#include "Controller.h"
class NewGameController :
	public Controller
{
public:
	NewGameController();
	~NewGameController();

	Controller* main();

private:
	void printScreen();
	void processTwoArgsNewGameCommand(string firstCommandToken, string secondCommandToken);
	vector <string> splitString(string splitted);
};

