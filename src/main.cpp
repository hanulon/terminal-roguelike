// main.cpp : Defines the entry point for the console application.
// WINSPEC - stands for 'Windows specific', this comment is used to mark the lines of code
//			that need to be changed when porting to linux
// Game Version: 0.0.2 (implemented basic map)

#include "stdafx.h"
#include <iostream>
#include <conio.h> //WINSPEC
#include "Tile.h"
#include "Creature.h"

#define WINDOWS
//#define LINUX

using namespace std;

vector <string> splitString(string splitted);
void clearConsole();
void terminalMainLoop();
void printMainMenu(string additionalInfo  = "");
int choiceMainMenu();
void printAboutMenu();

int processNewGameMenuCommands();
int finishActionInNewGameMenu();
int abortActionInNewGameMenu();
int assignAttributeSkillActionInNewGameMenu(string attributeSkillName, int value);
void printNewGameMenu();

void initMap();
void printMap();
void initCreature();


const unsigned int mapHeight = 20;
const unsigned int mapWidth = 40;
Tile map[mapHeight][mapWidth];

int attributePointsLeft = 6;
int skillPointsLeft = 12;
Creature creature = Creature("Zdzisiek");

int main()
{
	//initMap();

	//printMap();

	//initCreature();

	//cout << creature.getCharacterSheet();

	//system("pause");
	terminalMainLoop();

    return 0;
}

void initCreature()
{
	creature.setMaximumHealthPoints(10);
	creature.setCurrentHealthPoints(9);
	creature.setArmorClass(1);
	creature.setAttributes(6, 8, 10);
	creature.setCombatSkillByName("Close Combat", 1);
	creature.setCombatSkillByName("Evade", 0);
	creature.setCombatSkillByName("Firearms", 2);
	creature.setCombatSkillByName("Parry", 2);

	creature.setOtherSkillByName("Athletics", 0);
	creature.setOtherSkillByName("Hacking", 1);
	creature.setOtherSkillByName("Hide", 1);
	creature.setOtherSkillByName("Knowledge", 0);
	creature.setOtherSkillByName("Perception", 4);
	creature.setOtherSkillByName("Persuasion", 0);
	creature.setOtherSkillByName("Thievery", 3);
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
					creature.setName(command.substr(5));
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
	{
		int difference;
		int* attribute = creature.attr.getAttributePointerByStringName(attributeSkillName);
		if (attribute != nullptr && value > 0)
		{
			difference = value - *attribute;
			if (difference <= attributePointsLeft)
			{
				attributePointsLeft -= difference;
				*attribute = value;
			}
		}
		else
		{
			difference = value - creature.getSkillByName(attributeSkillName);
			if (difference <= skillPointsLeft)
			{
				skillPointsLeft -= difference;
				creature.setCombatSkillByName(attributeSkillName, value);
				creature.setOtherSkillByName(attributeSkillName, value);
			}
			
		}
	}

	return 2;
}

void printNewGameMenu()
{

	cout << creature.getCharacterSheet() <<endl;
	cout << "Attribute points left: " << attributePointsLeft << endl <<
		"Skill points left: " << skillPointsLeft << endl <<
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