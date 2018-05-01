#include "stdafx.h"
#include "MainMenuController.h"


MainMenuController::MainMenuController()
{
}


MainMenuController::~MainMenuController()
{
}

int MainMenuController::main()
{
	char menuChoice = 0;
	cin >> menuChoice;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	if (menuChoice == '1')
	{
		return 1;
	}
	else if (menuChoice == '2')
	{
		return 2;
	}
	else if (menuChoice == '3')
	{
		return 3;
	}
	else if (menuChoice == '4')
	{
		return 4;
	}
	else if (menuChoice == '5')
	{
		return -1;
	}
	return 0;
}
