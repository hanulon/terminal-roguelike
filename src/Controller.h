#pragma once
#include <iostream>
#include <conio.h>
#include "MainModelForController.h"

using namespace std;

class Controller
{
public:
	Controller();
	~Controller();

	virtual Controller* processUserInput() = 0;
	virtual void refresh();
	void updateMessageForUser(std::string message);
	static MainModelForController* mainModel;

protected:
	virtual void printScreen() = 0;
	void pressAnyKey();
	string trim(string str);
	void clearScreen();
	void printMessageForUser();

	Controller* returnedController;
	string messageForUser;
};

