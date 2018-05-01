#pragma once
#include "Controller.h"
class NewGameController :
	public Controller
{
public:
	NewGameController();
	~NewGameController();

	int main();

private:
	void processTwoArgsNewGameCommand(string firstCommandToken, string secondCommandToken);
	vector <string> splitString(string splitted);
};

