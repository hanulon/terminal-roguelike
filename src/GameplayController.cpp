#include "stdafx.h"
#include "GameplayController.h"


GameplayController::GameplayController()
{
}


GameplayController::~GameplayController()
{
}

Controller* GameplayController::main()
{
	int key = _getch();
	switch (key)
	{
	case Key_Escape:
		return new MainMenuController;
	case Key_Space:
		_STEP_MADE = EndTurn;
		return this;
	case Key_F_and_NumpadArrows:
	case Key_Arrows_and_Other:
		_STEP = playerMakesStep(GameplayController::ArrowKey(_getch()));
		_STEP_MADE = EndTurn;
		return this;
	default:
		cout << key << endl;
		system("pause");
		break;
	}
	return this;
}

void GameplayController::printScreen()
{
	cout << gameMapState;
	cout << "HERO STATISTICS\n" << playerShortInfo << endl;
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
