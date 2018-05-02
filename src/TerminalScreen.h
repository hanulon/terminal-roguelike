#pragma once

#include "Hero.h"
#include "NonPlayerCharacter.h"
#include "Map.h"

class TerminalScreen
{
public:
	TerminalScreen();
	TerminalScreen(Hero* playerCharacter, Map* gameMap);
	~TerminalScreen();
	void menusLoop();

private:
	Hero* playerCharacter;
	NonPlayerCharacter* enemyCharacter;
	NonPlayerCharacter* friendlyCharacter;
	Map* gameMap;
	Controller* userInterface;
	void testMapInitialization();

	void changeViewAndController(Controller* newInterface);
	void controllerAction();
	void npcsTakeActions();
	void playerMakesMove(Point step);
	bool playerCrashesNPC(Hero* playerCharacter, Point playerStep, NonPlayerCharacter* npc);
	void npcMakesMove(NonPlayerCharacter* npc);
	void npcCrashesPlayer(Hero* playerCharacter, NonPlayerCharacter* npc);
	void assignAttributeSkillActionInNewGameMenu(std::string attributeSkillName, int value);
};

