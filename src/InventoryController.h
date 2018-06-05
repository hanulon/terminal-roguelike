#pragma once
#include "Controller.h"
class InventoryController :
	public Controller
{
public:
	InventoryController();
	~InventoryController();

	Controller* processUserInput();

protected:
	void printScreen();
	std::string selectedItemName = "";
};

