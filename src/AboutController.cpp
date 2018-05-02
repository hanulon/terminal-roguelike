#include "stdafx.h"
#include "AboutController.h"


AboutController::AboutController()
{
}


AboutController::~AboutController()
{
}

Controller* AboutController::main()
{
	cout << "Press any key to return to the menu...";
	_getch(); //WINSPEC
	return new MainMenuController;
}

void AboutController::printScreen()
{
	cout << "\tTerminal Roguelike\n\tAbout\n\n";
	cout << "Author: Hanulon\n"
		"License: MIT\n"
		"Version: " + GAME_VERSION + "\n\n";
}
