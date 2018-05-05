#pragma once
#include "Controller.h"
class MainMenuController :
	public Controller
{
public:
	MainMenuController();
	~MainMenuController();

	Controller* processUserInput();

private:
	void selectMenu(char userChoice);
	void printScreen();
	void printMenuOptions();
};

