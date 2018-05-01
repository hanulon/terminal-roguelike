#pragma once

#include "Hero.h"
#include "NonPlayerCharacter.h"
#include "Map.h"
#include "ViewManager.h"

class TerminalScreen
{
public:
	TerminalScreen(Hero* playerCharacter, Map* gameMap);
	~TerminalScreen();
	void menusLoop();

	enum TurnStatus
	{
		EndTurn,
		ContinueTurn
	};

	enum KeyCodes
	{
		Key_Escape = 27,
		Key_Space = 32,
		Key_F_and_NumpadArrows = 0,
		Key_Arrows_and_Other = 224
	};

	enum ArrowKey
	{
		Arrow_Down = 80,
		Arrow_Right = 77,
		Arrow_Left = 75,
		Arrow_Up = 72
	};

private:
	Hero* playerCharacter;
	NonPlayerCharacter* enemyCharacter;
	NonPlayerCharacter* friendlyCharacter;
	Map* gameMap;
	void (TerminalScreen::*currentDisplay)() = NULL;
	void testMapInitialization();
	ViewManager* gameView;

	void displayMainMenu();
	void displayContinue();
	void displayNewGameMenu();
	void displayGraveyard();
	void displayAbout();

	void inputMainMenu();
	void inputContinue();
	TurnStatus processGameCommands();
	void playerMoves(ArrowKey arrowKey);
	Point playerMakesStep(ArrowKey arrowKey);
	void npcsTakeActions();
	bool playerCrashesNPC(Hero* playerCharacter, Point playerStep, NonPlayerCharacter* npc);
	void npcMakesMove(NonPlayerCharacter* npc);
	void npcCrashesPlayer(Hero* playerCharacter, NonPlayerCharacter* npc);
	void inputNewGame();
	void processNewGameMenuCommandsWithArguments(std::string command);
	void processTwoArgsNewGameCommand(std::string firstCommandToken, std::string secondCommandToken);
	void finishActionInNewGameMenu();
	void abortActionInNewGameMenu();
	void assignAttributeSkillActionInNewGameMenu(std::string attributeSkillName, int value);
	void inputAbout();
	void inputGraveyard();
	void pressAnyKeyGoBackToMenu();

	std::vector <std::string> splitString(std::string splitted);
	std::string trim(std::string str);
};

