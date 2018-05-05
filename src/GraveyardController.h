#pragma once
#include "Controller.h"
class GraveyardController :
	public Controller
{
public:
	GraveyardController();
	~GraveyardController();

	Controller* processUserInput();

private:
	void printScreen();
};

