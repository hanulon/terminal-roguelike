#include "stdafx.h"
#include "TerminalScreen.h"
#include <iostream>

using namespace std;

TerminalScreen::TerminalScreen() : TerminalScreen(new Hero,new Map) {}

TerminalScreen::TerminalScreen(Hero * playerCharacter, Map * gameMap)
{
	this->userInterface = new MainMenuController();
	this->linkFromController = userInterface->getLink();

	this->playerCharacter = playerCharacter;
	this->gameMap = gameMap;

	this->enemyCharacter = new NonPlayerCharacter("Enemy",true);
	this->enemyCharacter->testInitialization();
	this->friendlyCharacter = new NonPlayerCharacter("Friend", false);
	this->npcVector.push_back(this->enemyCharacter);
	this->npcVector.push_back(this->friendlyCharacter);

	testMapInitialization();
}

TerminalScreen::~TerminalScreen(){}

void TerminalScreen::menusLoop()
{
	while (this->userInterface != nullptr)
	{
		updateUserController();
		userInterface->refresh();
		changeViewAndController(userInterface->processUserInput());
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
	for(int i=0; i<npcVector.size(); i++)
		gameMap->addCreatureToMap(npcVector[i], npcVector[i]->getMapPosition());
}

void TerminalScreen::updateUserController()
{
	GameplayController::updateMapAndOtherInfo(gameMap->printMap(), playerCharacter->getGeneralInfo());
	NewGameController::updatePlayerSheet(playerCharacter->getCharacterSheet());
	NewGameController::updateCreationPointsLeft(playerCharacter->getAttributePointsLeft(), playerCharacter->getSkillPointsLeft());
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
	switch (linkFromController->signalAction())
	{
	case ControllerToModelConnector::TurnEnded:
		endTurn();
		break;
	case ControllerToModelConnector::NameChanged:
		playerCharacter->setName(linkFromController->getNewHeroName());
		break;
	case ControllerToModelConnector::AttrSkillChanged:
		assignAttributeSkillActionInNewGameMenu(linkFromController->getAttributeSkillName(),
			linkFromController->getAttributeSkillValue());
		break;
	default:
		break;
	}
	linkFromController->clearActionSignal();
}

void TerminalScreen::endTurn()
{
	Point playerStep = linkFromController->getPlayerStep();
	if (!(playerStep == Point()))
		playerMakesMove(playerStep);
	npcsTakeActions();
}

void TerminalScreen::npcsTakeActions()
{
	for (int i = 0; i < npcVector.size(); i++)
	{
		GameplayController::updateMap(gameMap->printMap());
		userInterface->refresh();
		npcMakesMove(npcVector[i]);
	}
}

void TerminalScreen::playerMakesMove(Point step)
{
	Point newPlayerPosition = playerCharacter->getMapPosition() + step;
	if (this->gameMap->isTheTileOccupied(newPlayerPosition))
	{
		Creature* crashedNpc = gameMap->getCreatureFrom(newPlayerPosition);
		if (crashedNpc != nullptr)
		{
			NonPlayerCharacter* npc = dynamic_cast<NonPlayerCharacter*>(crashedNpc);
			playerCrashesNpc(playerCharacter, npc);
		}
	}
	else
	{
		gameMap->moveCreatureToDesiredPosition(playerCharacter, newPlayerPosition);
		playerCharacter->setMapPosition(newPlayerPosition);
	}
}

void TerminalScreen::playerCrashesNpc(Hero * playerCharacter, NonPlayerCharacter * npc)
{
	if (npc->isEnemy)
		cout << "Player attacked enemy!" << endl;
	else
		cout << "Player contacted friendly NPC!" << endl;
	system("pause");
}

void TerminalScreen::npcMakesMove(NonPlayerCharacter * npc)
{
	Point npcNewPosition = npc->tryToMove();
	if (this->gameMap->isTheTileOccupied(npcNewPosition))
	{
		Creature* crashedCreature = gameMap->getCreatureFrom(npcNewPosition);
		NonPlayerCharacter* anotherNpc = dynamic_cast<NonPlayerCharacter*>(crashedCreature);
		if (anotherNpc != nullptr)
		{
			npcCrashesNpc(npc, anotherNpc);
		}
		else
		{
			Hero* hero = dynamic_cast<Hero*>(crashedCreature);
			if (hero != nullptr)
				npcCrashesPlayer(hero, npc);
		}
	}
	else
	{
		gameMap->moveCreatureToDesiredPosition(npc, npcNewPosition);
		npc->makeTriedMove();
	}
}

void TerminalScreen::npcCrashesPlayer(Hero * playerCharacter, NonPlayerCharacter * npc)
{
	if (npc->isEnemy)
		cout << "Enemy attacked player!" << endl;
	else
		cout << "Friendly NPC contacted player!" << endl;
	system("pause");
}

void TerminalScreen::npcCrashesNpc(NonPlayerCharacter * npc, NonPlayerCharacter * otherNpc)
{
	cout << "One npc crashed another npc!" << endl;
	system("pause");
}

void TerminalScreen::assignAttributeSkillActionInNewGameMenu(string attributeSkillName, int value)
{
	if (value >= 0)
		playerCharacter->setAttributeOrSkillHeroCreator(attributeSkillName, value);
}
