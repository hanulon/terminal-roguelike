#include "stdafx.h"
#include "GameplayController.h"


GameplayController::GameplayController()
{
}


GameplayController::~GameplayController()
{
}

int GameplayController::main()
{
	return processGameCommands();
}

int GameplayController::processGameCommands()
{
	int key = _getch();
	switch (key)
	{
	case Key_Escape:
		return 0;
	case Key_Space:
		_STEP_MADE = EndTurn;
		return 1;
	case Key_F_and_NumpadArrows:
	case Key_Arrows_and_Other:
		_STEP = playerMakesStep(GameplayController::ArrowKey(_getch()));
		_STEP_MADE = EndTurn;
		return 1;
	default:
		cout << key << endl;
		system("pause");
		break;
	}
	return 1;
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
