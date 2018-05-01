#pragma once
#include <iostream>

using namespace std;

class Controller
{
public:
	Controller();
	~Controller();

	virtual int main() = 0;
};

