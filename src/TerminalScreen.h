#pragma once

#include "Hero.h"
#include "NonPlayerCharacter.h"
#include "Map.h"

class TerminalScreen
{
public:
	TerminalScreen(Hero* playerCharacter, Map* gameMap);
	~TerminalScreen();
	void menusLoop();
private:
	Hero* playerCharacter;
	NonPlayerCharacter* enemyCharacter;
	NonPlayerCharacter* friendlyCharacter;
	Map* gameMap;
	void (TerminalScreen::*currentDisplay)() = NULL;

	void displayMainMenu();
	void displayContinue();
	void displayNewGameMenu();
	void displayGraveyard();
	void displayAbout();

	void clearScreen();
	void printMainMenu(std::string additionalInfo = "");
	void printAboutMenu();
	void printNewGameMenu();

	void choiceMainMenu();
	void gameContinue();
	int processGameCommands();
	Point playerMakesStep(int keyChar);
	bool playerCrashesNPC(Hero* playerCharacter, Point playerStep, NonPlayerCharacter* npc);
	void npcCrashesPlayer(Hero* playerCharacter, NonPlayerCharacter* npc);
	void processNewGameMenuCommands();
	void processNewGameMenuCommandsWithArguments(std::string command);
	void processTwoArgsNewGameCommand(std::string firstCommandToken, std::string secondCommandToken);
	void finishActionInNewGameMenu();
	void abortActionInNewGameMenu();
	void assignAttributeSkillActionInNewGameMenu(std::string attributeSkillName, int value);

	std::vector <std::string> splitString(std::string splitted);
	std::string trim(std::string str);
};

