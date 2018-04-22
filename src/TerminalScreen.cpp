#include "stdafx.h"
#include "TerminalScreen.h"
#include <iostream>
#include <conio.h>

using namespace std;

TerminalScreen::TerminalScreen(Hero * playerCharacter, Map * gameMap)
{
	this->currentDisplay = &TerminalScreen::displayMainMenu;

	this->playerCharacter = playerCharacter;
	this->gameMap = gameMap;
}

TerminalScreen::~TerminalScreen(){}

void TerminalScreen::menusLoop()
{
	while (this->currentDisplay != NULL)
	{
		clearScreen();
		(this->*currentDisplay)();
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

void TerminalScreen::displayMainMenu()
{
	printMainMenu();
	choiceMainMenu();
}

void TerminalScreen::displayContinue()
{
	gameContinue();
}

void TerminalScreen::displayNewGameMenu()
{
	printNewGameMenu();
	processNewGameMenuCommands();
}

void TerminalScreen::displayGraveyard()
{
	printMainMenu("Graveyard - function not implemented yet!\n");
	choiceMainMenu();
}

void TerminalScreen::displayAbout()
{
	printAboutMenu();
	this->currentDisplay = &TerminalScreen::displayMainMenu;
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
	if (menuChoice == '1')
		this->currentDisplay = &TerminalScreen::displayContinue;
	else if (menuChoice == '2')
		this->currentDisplay = &TerminalScreen::displayNewGameMenu;
	else if (menuChoice == '3')
		this->currentDisplay = &TerminalScreen::displayGraveyard;
	else if (menuChoice == '4')
		this->currentDisplay = &TerminalScreen::displayAbout;
	else if (menuChoice == '5')
		this->currentDisplay = NULL;
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
	this->currentDisplay = &TerminalScreen::displayMainMenu;
}

int TerminalScreen::processGameCommands()
{
	this->currentDisplay = &TerminalScreen::displayContinue;
	int key = _getch();
	if (key == 27)
	{
		this->currentDisplay = &TerminalScreen::displayMainMenu;
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
	getline(cin, command);
	command = trim(command);
	if (command == "finished")
		finishActionInNewGameMenu();
	else if (command == "abort")
		abortActionInNewGameMenu();
	else
	{
		processNewGameMenuCommandsWithArguments(command);
		this->currentDisplay = &TerminalScreen::displayNewGameMenu;
	}
}

void TerminalScreen::processNewGameMenuCommandsWithArguments(std::string command)
{
	vector <string> tokenizedCommand = splitString(command);
	if (tokenizedCommand[0] == "name")
		playerCharacter->setName(command.substr(5));
	else if (tokenizedCommand.size() == 2)
	{
		processTwoArgsNewGameCommand(tokenizedCommand[0], tokenizedCommand[1]);
	}
}

void TerminalScreen::processTwoArgsNewGameCommand(std::string firstCommandToken, std::string secondCommandToken)
{
	try
	{
		int value = stoi(secondCommandToken);
		assignAttributeSkillActionInNewGameMenu(firstCommandToken, value);
	}
	catch (const std::exception&){}
}

void TerminalScreen::finishActionInNewGameMenu()
{
	cout << "Procedure of saving and starting the game" << endl;
	system("pause");
	this->currentDisplay = &TerminalScreen::displayContinue;
}

void TerminalScreen::abortActionInNewGameMenu()
{
	this->currentDisplay = &TerminalScreen::displayMainMenu;
}

void TerminalScreen::assignAttributeSkillActionInNewGameMenu(string attributeSkillName, int value)
{
	if (value >= 0)
		playerCharacter->setAttributeOrSkillHeroCreator(attributeSkillName, value);
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

std::string TerminalScreen::trim(std::string str)
{
	int startPosition = 0;
	int endPosition = str.length() - 1;
	while (str[startPosition] == ' ')
		startPosition++;
	while (str[endPosition] == ' ')
		endPosition--;
	return str.substr(startPosition, endPosition - startPosition + 1);
}
