#include "stdafx.h"
#include "MainMenuController.h"


MainMenuController::MainMenuController()
{
}


MainMenuController::~MainMenuController()
{
}

Controller* MainMenuController::processUserInput()
{
	char menuChoice = 0;
	cin >> menuChoice;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	selectMenu(menuChoice);
	return returnedController;
}

void MainMenuController::selectMenu(char userChoice)
{
	switch (userChoice)
	{
	case '1':
		returnedController = new GameplayController;
		break;
	case '2':
		returnedController = new NewGameController;
		break;
	case '3':
		returnedController = new GraveyardController;
		break;
	case '4':
		returnedController = new AboutController;
		break;
	case '5':
		returnedController = nullptr;
		break;
	default:
		this->messageForUser =
			"You have typed wrong command! Choose one of the numbers above and press enter.";
		break;
	}
}

void MainMenuController::printScreen()
{
	cout << "\tTerminal Roguelike\n\n";
	cout << "Click the number to chose an option\n";
	printMenuOptions();
	printMessageForUser();
	cout << ">";
}

void MainMenuController::printMenuOptions()
{
	cout << "1. Continue\n"
		"2. New game\n"
		"3. Graveyard\n"
		"4. About\n"
		"5. Exit\n";
}
