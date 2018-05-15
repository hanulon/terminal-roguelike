#pragma once
#include <iostream>
#include <conio.h>
#include "ControllerToModelConnector.h"

using namespace std;

class Controller
{
public:
	Controller();
	~Controller();

	virtual Controller* processUserInput() = 0;
	virtual void refresh();
	ControllerToModelConnector* getLink();
	void updateMessageForUser(std::string message);

protected:
	virtual void printScreen() = 0;
	void pressAnyKey();
	string trim(string str);
	void clearScreen();
	void printMessageForUser();

	static ControllerToModelConnector linkWithModel;
	Controller* returnedController;
	string messageForUser;
};

