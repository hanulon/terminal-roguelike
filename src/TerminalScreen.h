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
	MapObstacle* computerTerminalObstacle;
	Item* droppedItem;
	Map* gameMap;
	Controller* userInterface;
	ControllerToModelConnector* linkFromController;
	vector <NonPlayerCharacter*> npcVector;
	void testMapInitialization();

	void updateUserController();
	void changeViewAndController(Controller* newInterface);
	void controllerAction();
	void playerTakeItemFromFloor();
	void endTurn();
	void playerMakesMove(Point step);
	void npcsTakeActions();
	void initializeFriendlyInteraction();
	void initializeInteraction();
	void npcMakesMove(NonPlayerCharacter* npc);
	void npcCrashesPlayer(Hero* playerCharacter, NonPlayerCharacter* npc);
	void npcCrashesNpc(NonPlayerCharacter* npc, NonPlayerCharacter* otherNpc);
	void npcCrashesObstacle(NonPlayerCharacter* npc, MapObstacle* obstacle);
	void assignAttributeSkillActionInNewGameMenu(std::string attributeSkillName, int value);
};

