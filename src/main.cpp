// main.cpp : Defines the entry point for the console application.
// WINSPEC - stands for 'Windows specific', this comment is used to mark the lines of code
//			that need to be changed when porting to linux
// Game Version: 0.0.2 (implemented basic map)

#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h> //WINSPEC
#include "Tile.h"

#define WINDOWS
//#define LINUX

using namespace std;

void clearConsole();
void terminalMainLoop();
void printMainMenu(string additionalInfo  = "");
int choiceMainMenu();
void printAboutMenu();
void initMap();
void printMap();


const unsigned int mapHeight = 20;
const unsigned int mapWidth = 40;
Tile map[mapHeight][mapWidth];

int main()
{
	initMap();

	printMap();

	system("pause");
	//terminalMainLoop();

    return 0;
}

void initMap()
{
	for (int y = 1; y < mapHeight-1; y++)
	{
		for (int x = 1; x < mapWidth-1; x++)
			map[y][x].clearTile();
	}
}

void printMap()
{
	for (int y = 0; y < mapHeight; y++)
	{
		for (int x = 0; x < mapWidth; x++)
			cout << map[y][x].getGraphic();
		cout << endl;
	}
}

void terminalMainLoop()
{
	static int menuChoice = -1; //main menu

	while (menuChoice)
	{
		clearConsole();
		switch (menuChoice)
		{
		case 1:
			printMainMenu("Continue - function not implemented yet!\n");
			menuChoice = choiceMainMenu();
			break;
		case 2:
			printMainMenu("New game - function not implemented yet!\n");
			menuChoice = choiceMainMenu();
			break;
		case 3:
			printMainMenu("Graveyard - function not implemented yet!\n");
			menuChoice = choiceMainMenu();
			break;
		case 4:
			printAboutMenu();
			menuChoice = -1;
			break;
		default:
			printMainMenu();
			menuChoice = choiceMainMenu();
			break;
		}
	}
}

void printMainMenu(string additionalInfo)
{
	cout << "\tTerminal Roguelike\n\n";
	cout << "Click the number to chose an option\n";
	cout << "1. Continue\n"
		"2. New game\n"
		"3. Graveyard\n"
		"4. About\n"
		"5. Exit\n";
	additionalInfo = "\n" + additionalInfo;
	cout <<	additionalInfo+">";
}

int choiceMainMenu()
{
	char menuChoice = 0;
	cin >> menuChoice;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	if (menuChoice == '1')
		return 1;
	else if (menuChoice == '2')
		return 2;
	else if (menuChoice == '3')
		return 3;
	else if (menuChoice == '4')
		return 4;
	else if (menuChoice == '5')
		return 0;
	return -1;
}

void printAboutMenu()
{
	cout << "\tTerminal Roguelike\n\tAbout\n\n";
	cout << "Author: Hanulon\n"
		"License: MIT\n"
		"Version: 0.0.1\n\n";
	cout << "Press any key to return to the menu...";
	_getch(); //WINSPEC
}

void clearConsole()
{
	#ifdef WINDOWS
		system("cls");
	#endif
	#ifdef LINUX
		system("clear");
	#endif
}