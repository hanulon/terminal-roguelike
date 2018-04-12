// main.cpp : Defines the entry point for the console application.
// WINSPEC - stands for 'Windows specific', this comment is used to mark the lines of code
//			that need to be changed when porting to linux
// Game Version: 0.0.2 (implemented basic map)

#include "stdafx.h"
#include <iostream>
#include <conio.h> //WINSPEC
#include "Tile.h"
#include "Hero.h"
#include "Creature.h"
#include "Map.h"

#define WINDOWS
//#define LINUX

using namespace std;

vector <string> splitString(string splitted);
void clearConsole();
void terminalMainLoop();
void printMainMenu(string additionalInfo  = "");
int choiceMainMenu();
void printAboutMenu();
void gameContinue();

int processGameCommands();
int processNewGameMenuCommands();
int finishActionInNewGameMenu();
int abortActionInNewGameMenu();
int assignAttributeSkillActionInNewGameMenu(string attributeSkillName, int value);
void printNewGameMenu();


Hero playerCharacter;
Map gameMap;

int main()
{
	terminalMainLoop();

    return 0;
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
			gameContinue();
			menuChoice = -1;
			break;
		case 2:
			printNewGameMenu();
			menuChoice = processNewGameMenuCommands();
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

void gameContinue()
{
	gameMap.testingMapInitialization();
	gameMap.addCreatureToMap(&playerCharacter, 10, 4);
	do
	{
		clearConsole();
		cout<<gameMap.printMap();
		cout << "HERO STATISTICS\n" << playerCharacter.getGeneralInfo() << endl;
	} while (processGameCommands() > 0);
}

int processGameCommands()
{
	int key = _getch();
	if (key == 27)
		return 0;
	if (key == -32) // arrows
		key = _getch();
	if (key == 0) // F1-12
		key = _getch();
	cout << key;



	system("pause");
	return 1;
}

int processNewGameMenuCommands()
{
	string command;
	vector <string> tokenizedCommand;
	while (true)
	{
		getline(cin, command);
		if (command == "finished")
			return finishActionInNewGameMenu();
		else if (command == "abort")
			return abortActionInNewGameMenu();
		else
		{
			tokenizedCommand = splitString(command);
			try
			{
				int value = stoi(tokenizedCommand[1]);
				if (tokenizedCommand.size() == 2)
					return assignAttributeSkillActionInNewGameMenu(tokenizedCommand[0], value);
			}
			catch (const std::exception&)
			{
				if (tokenizedCommand[0] == "name")
					playerCharacter.setName(command.substr(5));
				return 2;
			}
		}
	}
	return -1;
}

int finishActionInNewGameMenu()
{
	cout << "Procedure of saving and starting the game" << endl;
	system("pause");
	return 1; //continue
}

int abortActionInNewGameMenu()
{
	return -1;
}

int assignAttributeSkillActionInNewGameMenu(string attributeSkillName, int value)
{
	if (value >= 0)
		playerCharacter.setAttributeOrSkillHeroCreator(attributeSkillName, value);

	return 2;
}

void printNewGameMenu()
{

	cout << playerCharacter.getCharacterSheet() <<endl;
	cout << "Attribute points left: " << playerCharacter.getAttributePointsLeft() << endl <<
		"Skill points left: " << playerCharacter.getSkillPointsLeft() << endl <<
		"Instruction: assign skill and attribute points to your statistics, by typing: 'skill_name desired_value' and hitting 'enter'. Example: Might 3" << endl <<
		"Type 'name character_name' to give your character a new name, example: 'name Zdzislaw'"<<endl<<
		"Type 'finished' and hit enter, when you are ready to start the game." << endl <<
		"Type 'abort' and hit enter, if you want to return to main menu." << endl << endl << ">";
}

vector<string> splitString(string splitted)
{
	size_t  start = 0, end = 0;
	string theDelimiter = " ";
	vector <string> theStringVector;

	while (end != string::npos)
	{
		end = splitted.find(theDelimiter, start);

		// If at end, use length=maxLength.  Else use length=end-start.
		theStringVector.push_back(splitted.substr(start,
			(end == string::npos) ? string::npos : end - start));

		// If at end, use start=maxSize.  Else use start=end+delimiter.
		start = ((end > (string::npos - theDelimiter.size()))
			? string::npos : end + theDelimiter.size());
	}

	return theStringVector;
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