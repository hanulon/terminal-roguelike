#include "stdafx.h"
#include "TerminalScreen.h"
#include <iostream>
#include <conio.h>
#include "MainMenuController.h"
#include "AboutController.h"
#include "GameplayController.h"
#include "NewGameController.h"

using namespace std;

TerminalScreen::TerminalScreen() : TerminalScreen(new Hero,new Map) {}

TerminalScreen::TerminalScreen(Hero * playerCharacter, Map * gameMap)
{
	this->userInput = new MainMenuController();
	this->gameView = new ViewManager();
	gameView->openMainMenu();

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
	while (this->userInput != nullptr)
	{
		updateView();
		gameView->refresh();
		changeViewAndController(userInput->main());
		if (_STEP_MADE == EndTurn)
		{
			_STEP_MADE = ContinueTurn;
			if (!(_STEP == Point()))
			{
				playerMakesMove(_STEP);
				_STEP = Point();
			}
			npcsTakeActions();
		}
		else if (_ADDED_NAME == true)
		{
			_ADDED_NAME = false;
			playerCharacter->setName(_NAME);
		}
		else if (_ATTR_SKILL_CHANGED == true)
		{
			_ATTR_SKILL_CHANGED = false;
			assignAttributeSkillActionInNewGameMenu(_ATTR_SKILL, _VALUE);
		}
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

void TerminalScreen::changeViewAndController(int choice)
{
	delete this->userInput;
	switch (choice)
	{
	case 0:
		this->userInput = new MainMenuController;
		gameView->openMainMenu();
		break;
	case 1:
		this->userInput = new GameplayController;
		gameView->openGameplay();
		break;
	case 2:
		this->userInput = new NewGameController;
		gameView->openNewGame();
		break;
	case 3:
		this->userInput = new AboutController;
		gameView->openGraveyard();
		break;
	case 4:
		this->userInput = new AboutController;
		gameView->openAbout();
		break;
	case -1:
		this->userInput = nullptr;
		break;
	default:
		break;
	}
}

void TerminalScreen::updateView()
{
	gameView->updateMap(gameMap->printMap());
	gameView->updatePlayerShortInfo(playerCharacter->getGeneralInfo());
	gameView->updateNewGamePointsLeft(playerCharacter->getAttributePointsLeft(), playerCharacter->getSkillPointsLeft());
	gameView->updatePlayerSheet(playerCharacter->getCharacterSheet());
}

void TerminalScreen::npcsTakeActions()
{
	updateView();
	gameView->refresh();
	npcMakesMove(enemyCharacter);
	updateView();
	gameView->refresh();
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
