#include "stdafx.h"
#include "GameplayController.h"

string GameplayController::gameMapState;
string GameplayController::playerShortInfo;

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
		linkWithModel.endTurn();
		break;
	case Key_F_and_NumpadArrows:
	case Key_Arrows_and_Other:
		linkWithModel.makePlayerStep(playerMakesStep(GameplayController::ArrowKey(_getch())));
		break;
	default:
		realizeUndocumentedComment(keyCode);
		break;
	}
	return returnedController;
}

void GameplayController::updateMapAndOtherInfo(string gameMap, string shortPlayerInfo)
{
	gameMapState = gameMap;
	playerShortInfo = shortPlayerInfo;
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
	cout << gameMapState;
	cout << "HERO STATISTICS\n" << playerShortInfo << endl;
	printMessageForUser();
}