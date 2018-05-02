#include "stdafx.h"
#include "GraveyardController.h"


GraveyardController::GraveyardController()
{
}


GraveyardController::~GraveyardController()
{
}

Controller * GraveyardController::main()
{
	pressAnyKey();
	return new MainMenuController;
}

void GraveyardController::printScreen()
{
	cout << "\tTerminal Roguelike\n\tGraveyard\n\n";
	cout << "Graveyard is closed! A powerful lich has cursed the land, your fallen heroes cannot be buried...\n\n";
}
