#include "stdafx.h"
#include "Controller.h"
#include "Controller.h"


MainModelForController* Controller::mainModel = nullptr;

Controller::Controller()
{
	returnedController = this;
}


Controller::~Controller()
{
}

void Controller::refresh()
{
	clearScreen();
	printScreen();
}

void Controller::updateMessageForUser(std::string message)
{
	this->messageForUser = message;
}

void Controller::dialogModeOn(bool on)
{
}

void Controller::pressAnyKey()
{
	cout << "Press any key to return to the menu...";
	_getch(); //WINSPEC
}

string Controller::trim(string str)
{
	int startPosition = 0;
	int endPosition = str.length() - 1;
	while (str[startPosition] == ' ')
		startPosition++;
	while (str[endPosition] == ' ')
		endPosition--;
	return str.substr(startPosition, endPosition - startPosition + 1);
}

void Controller::clearScreen()
{
	#ifdef WINDOWS
		system("cls");
	#endif
	#ifdef LINUX
		system("clear");
	#endif
}

void Controller::printMessageForUser()
{
	if (messageForUser.length() > 0)
	{
		cout << endl << this->messageForUser << endl;
		this->messageForUser = "";
	}
}
