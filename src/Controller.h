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

protected:
	string trim(string str);
};

