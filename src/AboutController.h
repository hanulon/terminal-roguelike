#pragma once
#include "Controller.h"
class AboutController :
	public Controller
{
public:
	AboutController();
	~AboutController();

	Controller* processUserInput();

private:
	void printScreen();
};

