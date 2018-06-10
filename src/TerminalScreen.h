#pragma once

#include "Hero.h"
#include "NonPlayerCharacter.h"
#include "Map.h"
#include "MainModelForController.h"
#include "Controller.h"
#include "Item.h"

class TerminalScreen : public MainModelForController
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
	Item* weapon;
	Item* armor;
	Map* gameMap;
	Controller* userInterface;
	vector <NonPlayerCharacter*> npcVector;
	void testMapInitialization();
	void initializeFriendlyInteraction();
	void initializeInteraction();

	void changeViewAndController(Controller* newInterface);
	void playerTakeItemFromFloor();
	void endTurn();
	void playerMakesMove(Point step);
	void npcsTakeActions();
	void npcMakesMove(NonPlayerCharacter* npc);
	void npcCrashesPlayer(Hero* playerCharacter, NonPlayerCharacter* npc);
	void npcCrashesNpc(NonPlayerCharacter* npc, NonPlayerCharacter* otherNpc);
	void npcCrashesObstacle(NonPlayerCharacter* npc, MapObstacle* obstacle);

	void changeNewCharacterName(std::string name);
	void changeNewHeroAttributeSkill(std::string attributeSkillName, int value);
	void makePlayerStep(Point step);

	std::string getDisplayedMap();
	std::string getPlayerCharacterSheet();
	std::string getPlayerGeneralInfo();
	int getPlayerAttributePointsLeft();
	int getPlayerSkillPointsLeft();
	void playerDropItem(std::string itemName);
	void playerEquipItem(std::string itemName);
	std::string playerGetItemDecription(std::string itemName);
	void playerUnequipItem(std::string itemName);
	void playerUseItem(std::string itemName);
	std::string getPlayerEquipment();
	std::string getAllEquippedAsString();

	void interactionDecision(int subIter);
	std::string getInteractionMessage();
	bool hasInteractionAnySubinteractions();
};

