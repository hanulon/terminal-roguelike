#pragma once
#include "Controller.h"
class AboutController :
	public Controller
{
public:
	AboutController();
	~AboutController();

	int main();

private:
	void printScreen();
};

