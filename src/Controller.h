#pragma once
#include <iostream>
#include <conio.h>

using namespace std;

class Controller
{
public:
	Controller();
	~Controller();

	virtual int main() = 0;
	virtual void refresh();

protected:
	virtual void printScreen() = 0;
	string trim(string str);
	void clearScreen();
};

