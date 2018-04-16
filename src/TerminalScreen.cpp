#include "stdafx.h"
#include "TerminalScreen.h"
#include <iostream>
#include <conio.h>


using namespace std;

TerminalScreen::TerminalScreen(Hero * playerCharacter, Map * gameMap)
{
	this->activeScreen = -1; //main menu

	this->playerCharacter = playerCharacter;
	this->gameMap = gameMap;
}

TerminalScreen::~TerminalScreen()
{
}

void TerminalScreen::menusLoop()
{
	while (this->activeScreen)
	{
		clearScreen();
		switch (this->activeScreen)
		{
		case 1:
			gameContinue();
			this->activeScreen = -1;
			break;
		case 2:
			printNewGameMenu();
			processNewGameMenuCommands();
			break;
		case 3:
			printMainMenu("Graveyard - function not implemented yet!\n");
			choiceMainMenu();
			break;
		case 4:
			printAboutMenu();
			this->activeScreen = -1;
			break;
		default:
			printMainMenu();
			choiceMainMenu();
			break;
		}
	}
}

void TerminalScreen::clearScreen()
{
	#ifdef WINDOWS
			system("cls");
	#endif
	#ifdef LINUX
			system("clear");
	#endif
}

vector<string> TerminalScreen::splitString(string splitted)
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

void TerminalScreen::printMainMenu(string additionalInfo)
{
	cout << "\tTerminal Roguelike\n\n";
	cout << "Click the number to chose an option\n";
	cout << "1. Continue\n"
		"2. New game\n"
		"3. Graveyard\n"
		"4. About\n"
		"5. Exit\n";
	additionalInfo = "\n" + additionalInfo;
	cout << additionalInfo + ">";
}

void TerminalScreen::printAboutMenu()
{
	cout << "\tTerminal Roguelike\n\tAbout\n\n";
	cout << "Author: Hanulon\n"
		"License: MIT\n"
		"Version: 0.0.1\n\n";
	cout << "Press any key to return to the menu...";
	_getch(); //WINSPEC
}

void TerminalScreen::printNewGameMenu()
{
	cout << playerCharacter->getCharacterSheet() << endl;
	cout << "Attribute points left: " << playerCharacter->getAttributePointsLeft() << endl <<
		"Skill points left: " << playerCharacter->getSkillPointsLeft() << endl <<
		"Instruction: assign skill and attribute points to your statistics, by typing: 'skill_name desired_value' and hitting 'enter'. Example: Might 3" << endl <<
		"Type 'name character_name' to give your character a new name, example: 'name Zdzislaw'" << endl <<
		"Type 'finished' and hit enter, when you are ready to start the game." << endl <<
		"Type 'abort' and hit enter, if you want to return to main menu." << endl << endl << ">";
}

void TerminalScreen::choiceMainMenu()
{
	char menuChoice = 0;
	cin >> menuChoice;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	this->activeScreen = -1;
	if (menuChoice == '1')
		this->activeScreen = 1;
	else if (menuChoice == '2')
		this->activeScreen = 2;
	else if (menuChoice == '3')
		this->activeScreen = 3;
	else if (menuChoice == '4')
		this->activeScreen = 4;
	else if (menuChoice == '5')
		this->activeScreen = 0;
}

void TerminalScreen::gameContinue()
{
	gameMap->testingMapInitialization();
	gameMap->addCreatureToMap(playerCharacter, 10, 4);
	do
	{
		clearScreen();
		cout << gameMap->printMap();
		cout << "HERO STATISTICS\n" << playerCharacter->getGeneralInfo() << endl;
	} while (processGameCommands() > 0);
}

int TerminalScreen::processGameCommands()
{
	this->activeScreen = 1;
	int key = _getch();
	if (key == 27)
	{
		this->activeScreen = 0;
		return 0;
	}
	else
	{
		if (key == -32) // arrows
			key = _getch();
		if (key == 0) // F1-12
			key = _getch();
	}

	cout << key << endl;

	system("pause");
	return 1;
}

void TerminalScreen::processNewGameMenuCommands()
{
	string command;
	vector <string> tokenizedCommand;
	this->activeScreen = -1;

	getline(cin, command);
	if (command == "finished")
		finishActionInNewGameMenu();
	else if (command == "abort")
		abortActionInNewGameMenu();
	else
	{
		tokenizedCommand = splitString(command);
		if (tokenizedCommand[0] == "name")
			playerCharacter->setName(command.substr(5));
		else if (tokenizedCommand.size() == 2)
		{
			processTwoArgsNewGameCommand(tokenizedCommand[0], tokenizedCommand[1]);
		}
		this->activeScreen = 2;
	}
}

void TerminalScreen::processTwoArgsNewGameCommand(std::string firstCommandToken, std::string secondCommandToken)
{
	try
	{
		int value = stoi(secondCommandToken);
		assignAttributeSkillActionInNewGameMenu(firstCommandToken, value);
	}
	catch (const std::exception&)
	{

	}
}

void TerminalScreen::finishActionInNewGameMenu()
{
	cout << "Procedure of saving and starting the game" << endl;
	system("pause");
	this->activeScreen = 1; //continue
}

void TerminalScreen::abortActionInNewGameMenu()
{
	this->activeScreen = -1;
}

void TerminalScreen::assignAttributeSkillActionInNewGameMenu(string attributeSkillName, int value)
{
	if (value >= 0)
		playerCharacter->setAttributeOrSkillHeroCreator(attributeSkillName, value);
}
