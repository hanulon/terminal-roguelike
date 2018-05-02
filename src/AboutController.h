#pragma once
#include "Controller.h"
class AboutController :
	public Controller
{
public:
	AboutController();
	~AboutController();

	Controller* main();

private:
	void printScreen();
};

