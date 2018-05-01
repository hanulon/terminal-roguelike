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
