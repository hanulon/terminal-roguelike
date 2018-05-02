#include "stdafx.h"
#include "TerminalScreen.h"
#include <iostream>

using namespace std;

TerminalScreen::TerminalScreen() : TerminalScreen(new Hero,new Map) {}

TerminalScreen::TerminalScreen(Hero * playerCharacter, Map * gameMap)
{
	this->userInterface = new MainMenuController();

	this->playerCharacter = playerCharacter;
	this->enemyCharacter = new NonPlayerCharacter("Enemy",true);
	this->enemyCharacter->testInitialization();
	this->friendlyCharacter = new NonPlayerCharacter("Friend", false);
	this->gameMap = gameMap;

	testMapInitialization();
}

TerminalScreen::~TerminalScreen(){}

void TerminalScreen::menusLoop()
{
	while (this->userInterface != nullptr)
	{
		userInterface->updateAll(gameMap->printMap(), playerCharacter->getCharacterSheet(), playerCharacter->getGeneralInfo(),
			playerCharacter->getAttributePointsLeft(), playerCharacter->getSkillPointsLeft());
		userInterface->refresh();
		changeViewAndController(userInterface->main());
		controllerAction();
	}
}

void TerminalScreen::testMapInitialization()
{
	gameMap->testingMapInitialization();
	playerCharacter->setMapPosition(Point(10, 4));
	enemyCharacter->setMapPosition(Point(15, 7));
	friendlyCharacter->setMapPosition(Point(4, 15));

	gameMap->addCreatureToMap(playerCharacter, playerCharacter->getMapPosition());
	gameMap->addCreatureToMap(enemyCharacter, enemyCharacter->getMapPosition());
	gameMap->addCreatureToMap(friendlyCharacter, friendlyCharacter->getMapPosition());
}

void TerminalScreen::changeViewAndController(Controller* newInterface)
{
	if (newInterface == nullptr || typeid(*userInterface) != typeid(*newInterface))
	{
		delete this->userInterface;
		this->userInterface = newInterface;
	}
}

void TerminalScreen::controllerAction()
{
	switch (userControllerMessage.actionType)
	{
	case TurnEnded:
		if (!(userControllerMessage.step == Point()))
		{
			playerMakesMove(userControllerMessage.step);
			userControllerMessage.step = Point();
		}
		npcsTakeActions();
		break;
	case NameChanged:
		playerCharacter->setName(userControllerMessage.name);
		break;
	case AttrSkillChanged:
		assignAttributeSkillActionInNewGameMenu(userControllerMessage.attributeSkillName, userControllerMessage.value);
		break;
	default:
		break;
	}
	userControllerMessage.actionType = NoAction;
}

void TerminalScreen::npcsTakeActions()
{
	userInterface->updateAll(gameMap->printMap(), playerCharacter->getCharacterSheet(), playerCharacter->getGeneralInfo(),
		playerCharacter->getAttributePointsLeft(), playerCharacter->getSkillPointsLeft());
	userInterface->refresh();
	npcMakesMove(enemyCharacter);
	userInterface->updateAll(gameMap->printMap(), playerCharacter->getCharacterSheet(), playerCharacter->getGeneralInfo(),
		playerCharacter->getAttributePointsLeft(), playerCharacter->getSkillPointsLeft());
	userInterface->refresh();
	npcMakesMove(friendlyCharacter);
}

void TerminalScreen::playerMakesMove(Point step)
{
	Point newPlayerPosition = playerCharacter->getMapPosition() + step;
	if (this->gameMap->isTheTileOccupied(newPlayerPosition))
	{
		playerCrashesNPC(playerCharacter, step, enemyCharacter);
		playerCrashesNPC(playerCharacter, step, friendlyCharacter);
	}
	else
	{
		gameMap->removeCreatureFromMapTile(playerCharacter->getMapPosition());
		playerCharacter->setMapPosition(newPlayerPosition);
		gameMap->addCreatureToMap(playerCharacter, playerCharacter->getMapPosition());
	}
}

bool TerminalScreen::playerCrashesNPC(Hero * playerCharacter, Point playerStep, NonPlayerCharacter * npc)
{

	Point enemyPosition = npc->getMapPosition();
	Point newPlayerPosition = playerCharacter->getMapPosition() + playerStep;
	if (newPlayerPosition == enemyPosition)
	{
		if(npc->isEnemy)
			cout << "Player attacked enemy!" << endl;
		else
			cout << "Player contacted friendly NPC!" << endl;
		system("pause");
		return true;
	}
	else
		return false;
}

void TerminalScreen::npcMakesMove(NonPlayerCharacter * npc)
{
	Point npcStartingPosition = npc->getMapPosition();
	npc->moveInCircle();
	Point npcNewPosition = npc->getMapPosition();
	if (this->gameMap->isTheTileOccupied(npcNewPosition))
	{
		npcCrashesPlayer(playerCharacter, npc);
		npc->setMapPosition(npcStartingPosition);
	}
	else
	{
		gameMap->removeCreatureFromMapTile(npcStartingPosition);
		gameMap->addCreatureToMap(npc, npcNewPosition);
	}
}

void TerminalScreen::npcCrashesPlayer(Hero * playerCharacter, NonPlayerCharacter * npc)
{
	if (playerCharacter->getMapPosition() == npc->getMapPosition())
	{
		if (npc->isEnemy)
			cout << "Enemy attacked player!" << endl;
		else
			cout << "Friendly NPC contacted player!" << endl;
		system("pause");
	}
}

void TerminalScreen::assignAttributeSkillActionInNewGameMenu(string attributeSkillName, int value)
{
	if (value >= 0)
		playerCharacter->setAttributeOrSkillHeroCreator(attributeSkillName, value);
}
