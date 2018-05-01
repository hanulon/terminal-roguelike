#include "stdafx.h"
#include "ViewManager.h"
#include <iostream>

using namespace std;


ViewManager::ViewManager()
{
	this->activeScreen = &ViewManager::mainMenu;
	this->activeScreen = 0;
}


ViewManager::~ViewManager()
{
}

void ViewManager::refresh()
{
	clearScreen();
	(this->*activeScreen)();
}

void ViewManager::updateNewGamePointsLeft(int attributes, int skills)
{
	attributePointsLeft = attributes;
	skillPointsLeft = skills;
}

void ViewManager::updatePlayerSheet(std::string sheet)
{
	this->playerSheet = sheet;
}

void ViewManager::updatePlayerShortInfo(std::string shortInfo)
{
	this->playerShortInfo = shortInfo;
}

void ViewManager::updateMap(std::string map)
{
	this->gameMapState = map;
}

void ViewManager::openMainMenu()
{
	this->activeScreen = &ViewManager::mainMenu;
}

void ViewManager::openGameplay()
{
	this->activeScreen = &ViewManager::gameplay;
}

void ViewManager::openNewGame()
{
	this->activeScreen = &ViewManager::newGame;
}

void ViewManager::openGraveyard()
{
	this->activeScreen = &ViewManager::graveyard;
}

void ViewManager::openAbout()
{
	this->activeScreen = &ViewManager::about;
}

void ViewManager::clearScreen()
{
	#ifdef WINDOWS
		system("cls");
	#endif
	#ifdef LINUX
		system("clear");
	#endif
}

void ViewManager::mainMenu()
{
	cout << "\tTerminal Roguelike\n\n";
	cout << "Click the number to chose an option\n";
	cout << "1. Continue\n"
		"2. New game\n"
		"3. Graveyard\n"
		"4. About\n"
		"5. Exit\n";
	//additionalInfo = "\n" + additionalInfo;
	//cout << additionalInfo + ">";
	cout << "\n>";
}

void ViewManager::gameplay()
{
	cout << this->gameMapState;
	cout << "HERO STATISTICS\n" << this->playerShortInfo << endl;
}

void ViewManager::newGame()
{
	cout << this->playerSheet << endl;
	cout << "Attribute points left: " << attributePointsLeft << endl <<
		"Skill points left: " << skillPointsLeft << endl <<
		"Instruction: assign skill and attribute points to your statistics, by typing: 'skill_name desired_value' and hitting 'enter'. Example: Might 3" << endl <<
		"Type 'name character_name' to give your character a new name, example: 'name Zdzislaw'" << endl <<
		"Type 'finished' and hit enter, when you are ready to start the game." << endl <<
		"Type 'abort' and hit enter, if you want to return to main menu." << endl << endl << ">";
}

void ViewManager::graveyard()
{
	cout << "\tTerminal Roguelike\n\tGraveyard\n\n";
	cout << "Graveyard is closed! A powerful lich has cursed the land, your fallen heroes cannot be buried...\n\n";
}

void ViewManager::about()
{
	cout << "\tTerminal Roguelike\n\tAbout\n\n";
	cout << "Author: Hanulon\n"
		"License: MIT\n"
		"Version: " + GAME_VERSION + "\n\n";
}
