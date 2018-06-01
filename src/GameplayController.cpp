#include "stdafx.h"
#include "GameplayController.h"

GameplayController::GameplayController()
{
}


GameplayController::~GameplayController()
{
}

Controller* GameplayController::processUserInput()
{
	int keyCode = _getch();
	switch (keyCode)
	{
	case Key_Escape:
		returnedController = new MainMenuController;
		break;
	case Key_Space:
		mainModel->endTurn();
		break;
	case Key_Help_0:
	case Key_Help_1:
	case Key_Help_2:
		displayHelp();
		break;
	case Key_Inventory:
		//inventory screen
		break;
	case Key_Character_Sheet:
		//character sheet screen
		break;
	case Key_Shoot:
		//shooting options
		break;
	case Key_Take_Item:
		mainModel->playerTakeItemFromFloor();
		break;
	case Key_F_and_NumpadArrows:
	case Key_Arrows_and_Other:
		mainModel->makePlayerStep(playerMakesStep(GameplayController::ArrowKey(_getch())));
		break;
	default:
		realizeUndocumentedComment(keyCode);
		break;
	}
	return returnedController;
}

void GameplayController::displayHelp()
{
	this->messageForUser = "Player instruction:\n"
		"Use arrows to move.\n"
		"Press 'i' to go to inventory screen.\n"
		"Press 'p' to go to player's character sheet screen.\n"
		"Press 's' to shoot.\n"
		"Press 't' to take item on floor.\n"
		"Press escape key to return to main menu.\n"
		"Press space key to end turn without moving your character.";
}

Point GameplayController::playerMakesStep(ArrowKey arrowKey)
{
	Point step;
	switch (arrowKey)
	{
	case Arrow_Down:
		step.y++;
		break;
	case Arrow_Right:
		step.x++;
		break;
	case Arrow_Left:
		step.x--;
		break;
	case Arrow_Up:
		step.y--;
		break;
	default:
		break;
	}
	return step;
}

void GameplayController::realizeUndocumentedComment(int keyPressed)
{
	this->messageForUser = "Pressed undocumented key code: " + to_string(keyPressed);
}

void GameplayController::printScreen()
{
	cout << mainModel->getDisplayedMap();
	cout << "HERO STATISTICS\n" << mainModel->getPlayerGeneralInfo() << endl;
	if (this->messageForUser.length() == 0)
		this->messageForUser = "Press h or ? to show help.";
	printMessageForUser();
}