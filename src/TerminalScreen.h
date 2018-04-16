#pragma once

#include "Hero.h"
#include "Map.h"

class TerminalScreen
{
public:
	TerminalScreen(Hero* playerCharacter, Map* gameMap);
	~TerminalScreen();

	enum ScreenType
	{
		ClosingScreen,
		MainMenuScreen,
		ContinueScreen,
		NewGameScreen,
		GraveyardScreen,
		AboutScreen
	};

	void menusLoop();

private:
	ScreenType activeScreen;

	Hero* playerCharacter;
	Map* gameMap;

	void clearScreen();
	std::vector <std::string> splitString(std::string splitted);

	void printMainMenu(std::string additionalInfo = "");
	void printAboutMenu();
	void printNewGameMenu();

	void choiceMainMenu();
	void gameContinue();
	int processGameCommands();
	void processNewGameMenuCommands();
	void processTwoArgsNewGameCommand(std::string firstCommandToken, std::string secondCommandToken);
	void finishActionInNewGameMenu();
	void abortActionInNewGameMenu();
	void assignAttributeSkillActionInNewGameMenu(std::string attributeSkillName, int value);
};

