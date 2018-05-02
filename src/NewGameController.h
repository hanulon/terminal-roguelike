#pragma once
#include "Controller.h"
class NewGameController :
	public Controller
{
public:
	NewGameController();
	~NewGameController();

	int main();
	void refresh();

private:
	void processTwoArgsNewGameCommand(string firstCommandToken, string secondCommandToken);
	vector <string> splitString(string splitted);
};

