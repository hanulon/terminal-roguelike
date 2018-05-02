#pragma once
#include "Controller.h"
class MainMenuController :
	public Controller
{
public:
	MainMenuController();
	~MainMenuController();

	Controller* main();

private:
	void printScreen();
};

