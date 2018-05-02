#include "stdafx.h"
#include "MainMenuController.h"


MainMenuController::MainMenuController()
{
}


MainMenuController::~MainMenuController()
{
}

Controller* MainMenuController::main()
{
	char menuChoice = 0;
	cin >> menuChoice;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	if (menuChoice == '1')
	{
		return new GameplayController;
	}
	else if (menuChoice == '2')
	{
		return new NewGameController;
	}
	else if (menuChoice == '3')
	{
		return new GraveyardController;
	}
	else if (menuChoice == '4')
	{
		return new AboutController;
	}
	else if (menuChoice == '5')
	{
		return nullptr;
	}
	return this;
}

void MainMenuController::printScreen()
{
	cout << "\tTerminal Roguelike\n\n";
	cout << "Click the number to chose an option\n";
	cout << "1. Continue\n"
		"2. New game\n"
		"3. Graveyard\n"
		"4. About\n"
		"5. Exit\n";
	//additionalInfo = "\n" + additionalInfo;
	//cout << additionalInfo + ">";
	cout << "\n>";
}
