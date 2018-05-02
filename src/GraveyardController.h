#pragma once
#include "Controller.h"
class GraveyardController :
	public Controller
{
public:
	GraveyardController();
	~GraveyardController();

	Controller* main();

private:
	void printScreen();
};

