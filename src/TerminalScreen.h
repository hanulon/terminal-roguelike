#pragma once

#include "Hero.h"
#include "NonPlayerCharacter.h"
#include "Map.h"
#include "ControllerToModelConnector.h"
#include "Controller.h"
#include "Item.h"

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
	MapObstacle* immovableObstacle;
	Item* droppedItem;
	Map* gameMap;
	Controller* userInterface;
	ControllerToModelConnector* linkFromController;
	vector <NonPlayerCharacter*> npcVector;
	void testMapInitialization();

	void updateUserController();
	void changeViewAndController(Controller* newInterface);
	void controllerAction();
	void endTurn();
	void npcsTakeActions();
	void playerMakesMove(Point step);
	void playerCrashesNpc(Hero* playerCharacter, NonPlayerCharacter* npc);
	void playerCrashesObstacle(Hero* playerCharacter, MapObstacle* obstacle);
	void npcMakesMove(NonPlayerCharacter* npc);
	void npcCrashesPlayer(Hero* playerCharacter, NonPlayerCharacter* npc);
	void npcCrashesNpc(NonPlayerCharacter* npc, NonPlayerCharacter* otherNpc);
	void npcCrashesObstacle(NonPlayerCharacter* npc, MapObstacle* obstacle);
	void assignAttributeSkillActionInNewGameMenu(std::string attributeSkillName, int value);
};

