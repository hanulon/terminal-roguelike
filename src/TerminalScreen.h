#pragma once

#include "Hero.h"
#include "Map.h"

class TerminalScreen
{
public:
	TerminalScreen(Hero* playerCharacter, Map* gameMap);
	~TerminalScreen();

	void menusLoop();

private:
	Hero* playerCharacter;
	Map* gameMap;

	void clearScreen();
	std::vector <std::string> splitString(std::string splitted);

	void printMainMenu(std::string additionalInfo = "");
	void printAboutMenu();
	void printNewGameMenu();

	int choiceMainMenu();
	void gameContinue();
	int processGameCommands();
	int processNewGameMenuCommands();
	void processTwoArgsNewGameCommand(std::string firstCommandToken, std::string secondCommandToken);
	int finishActionInNewGameMenu();
	int abortActionInNewGameMenu();
	void assignAttributeSkillActionInNewGameMenu(std::string attributeSkillName, int value);
};

