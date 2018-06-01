#pragma once
#include "Controller.h"
class GameplayController :
	public Controller
{
public:
	GameplayController();
	~GameplayController();

	Controller* processUserInput();

private:
	enum KeyCodes
	{
		Key_Escape = 27,
		Key_Space = 32,
		Key_F_and_NumpadArrows = 0,
		Key_Arrows_and_Other = 224,
		Key_Help_0 = 47,
		Key_Help_1 = 63,
		Key_Help_2 = 104,
		Key_Inventory = 105,
		Key_Character_Sheet = 112,
		Key_Shoot = 115,
		Key_Take_Item = 116
	};

	enum ArrowKey
	{
		Arrow_Down = 80,
		Arrow_Right = 77,
		Arrow_Left = 75,
		Arrow_Up = 72
	};

	void displayHelp();
	Point playerMakesStep(ArrowKey arrowKey);
	void realizeUndocumentedComment(int keyPressed);
	void printScreen();
};

