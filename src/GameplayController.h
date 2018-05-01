#pragma once
#include "Controller.h"
class GameplayController :
	public Controller
{
public:
	GameplayController();
	~GameplayController();

	int main();

	enum KeyCodes
	{
		Key_Escape = 27,
		Key_Space = 32,
		Key_F_and_NumpadArrows = 0,
		Key_Arrows_and_Other = 224
	};

	enum ArrowKey
	{
		Arrow_Down = 80,
		Arrow_Right = 77,
		Arrow_Left = 75,
		Arrow_Up = 72
	};

private:
	int processGameCommands();
	Point playerMakesStep(ArrowKey arrowKey);
};

