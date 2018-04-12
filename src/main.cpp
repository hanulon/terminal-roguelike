// main.cpp : Defines the entry point for the console application.
// WINSPEC - stands for 'Windows specific', this comment is used to mark the lines of code
//			that need to be changed when porting to linux
// Game Version: 0.0.3 (implemented character on map)

#include "stdafx.h"
#include "Hero.h"
#include "Map.h"
#include "TerminalScreen.h"


using namespace std;

int main()
{
	Hero playerCharacter;
	Map gameMap;
	TerminalScreen gameConsole(&playerCharacter, &gameMap);

	gameConsole.menusLoop();

    return 0;
}