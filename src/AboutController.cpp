#include "stdafx.h"
#include "AboutController.h"


AboutController::AboutController()
{
}


AboutController::~AboutController()
{
}

int AboutController::main()
{
	cout << "Press any key to return to the menu...";
	_getch(); //WINSPEC
	return 0;
}

void AboutController::refresh()
{
	clearScreen();
	cout << "\tTerminal Roguelike\n\tAbout\n\n";
	cout << "Author: Hanulon\n"
		"License: MIT\n"
		"Version: " + GAME_VERSION + "\n\n";
}
