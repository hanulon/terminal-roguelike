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
	this->currentInput = &TerminalScreen::inputMainMenu;
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
	while (this->currentInput != NULL)
	{
		updateView();
		gameView->refresh();
		changeViewAndController(userInput->main());
		if (_STEP_MADE == true)
		{
			_STEP_MADE = false;
			Point step = _STEP;
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
		//this->currentInput = &TerminalScreen::inputNewGame;
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
		this->currentInput = NULL;
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

void TerminalScreen::inputMainMenu()
{
	char menuChoice = 0;
	cin >> menuChoice;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	if (menuChoice == '1')
	{
		this->currentInput = &TerminalScreen::inputContinue;
		gameView->openGameplay();
	}
	else if (menuChoice == '2')
	{
		this->currentInput = &TerminalScreen::inputNewGame;
		gameView->openNewGame();
	}
	else if (menuChoice == '3')
	{
		this->currentInput = &TerminalScreen::inputGraveyard;
		gameView->openGraveyard();
	}
	else if (menuChoice == '4')
	{
		this->currentInput = &TerminalScreen::inputAbout;
		gameView->openAbout();
	}
	else if (menuChoice == '5')
	{
		this->currentInput = NULL;
	}
}

void TerminalScreen::inputContinue()
{
	TerminalScreen::TurnStatus turnStatus = processGameCommands();
	if (turnStatus == EndTurn)
	{
		npcsTakeActions();
	}
}

TerminalScreen::TurnStatus TerminalScreen::processGameCommands()
{
	this->currentInput = &TerminalScreen::inputContinue;
	gameView->openGameplay();
	int key = _getch();
	switch (key)
	{
	case Key_Escape:
		this->currentInput = &TerminalScreen::inputMainMenu;
		gameView->openMainMenu();
		return ContinueTurn;
	case Key_Space:
		return EndTurn;
	case Key_F_and_NumpadArrows:
	case Key_Arrows_and_Other:
		playerMoves(TerminalScreen::ArrowKey(_getch()));
		return EndTurn;
	default:
		cout << key << endl;
		system("pause");
		break;
	}
	return ContinueTurn;
}

void TerminalScreen::playerMoves(TerminalScreen::ArrowKey arrowKey)
{
	Point step = playerMakesStep(arrowKey);
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

Point TerminalScreen::playerMakesStep(TerminalScreen::ArrowKey arrowKey)
{
	Point step;
	switch (arrowKey)
	{
	case Arrow_Down:
		step.y++;
		break;
	case Arrow_Right:
		step.x++;
		break;
	case Arrow_Left:
		step.x--;
		break;
	case Arrow_Up:
		step.y--;
		break;
	default:
		break;
	}
	return step;
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

void TerminalScreen::inputNewGame()
{
	string command;
	getline(cin, command);
	command = trim(command);
	if (command == "finished")
		finishActionInNewGameMenu();
	else if (command == "abort")
		abortActionInNewGameMenu();
	else
	{
		processNewGameMenuCommandsWithArguments(command);
		this->currentInput = &TerminalScreen::inputNewGame;
		gameView->openNewGame();
	}
}

void TerminalScreen::processNewGameMenuCommandsWithArguments(std::string command)
{
	vector <string> tokenizedCommand = splitString(command);
	if (tokenizedCommand[0] == "name")
		playerCharacter->setName(command.substr(5));
	else if (tokenizedCommand.size() == 2)
	{
		processTwoArgsNewGameCommand(tokenizedCommand[0], tokenizedCommand[1]);
	}
}

void TerminalScreen::processTwoArgsNewGameCommand(std::string firstCommandToken, std::string secondCommandToken)
{
	try
	{
		int value = stoi(secondCommandToken);
		assignAttributeSkillActionInNewGameMenu(firstCommandToken, value);
	}
	catch (const std::exception&){}
}

void TerminalScreen::finishActionInNewGameMenu()
{
	cout << "Procedure of saving and starting the game" << endl;
	system("pause");
	this->currentInput = &TerminalScreen::inputContinue;
	gameView->openGameplay();
}

void TerminalScreen::abortActionInNewGameMenu()
{
	this->currentInput = &TerminalScreen::inputMainMenu;
	gameView->openMainMenu();
}

void TerminalScreen::assignAttributeSkillActionInNewGameMenu(string attributeSkillName, int value)
{
	if (value >= 0)
		playerCharacter->setAttributeOrSkillHeroCreator(attributeSkillName, value);
}

void TerminalScreen::inputAbout()
{
	pressAnyKeyGoBackToMenu();
}

void TerminalScreen::inputGraveyard()
{
	pressAnyKeyGoBackToMenu();
}

void TerminalScreen::pressAnyKeyGoBackToMenu()
{
	cout << "Press any key to return to the menu...";
	_getch(); //WINSPEC
	this->currentInput = &TerminalScreen::inputMainMenu;
	gameView->openMainMenu();
}

vector<string> TerminalScreen::splitString(string splitted)
{
	size_t  start = 0, end = 0;
	string theDelimiter = " ";
	vector <string> theStringVector;

	while (end != string::npos)
	{
		end = splitted.find(theDelimiter, start);

		// If at end, use length=maxLength.  Else use length=end-start.
		theStringVector.push_back(splitted.substr(start,
			(end == string::npos) ? string::npos : end - start));

		// If at end, use start=maxSize.  Else use start=end+delimiter.
		start = ((end > (string::npos - theDelimiter.size()))
			? string::npos : end + theDelimiter.size());
	}
	return theStringVector;
}

std::string TerminalScreen::trim(std::string str)
{
	int startPosition = 0;
	int endPosition = str.length() - 1;
	while (str[startPosition] == ' ')
		startPosition++;
	while (str[endPosition] == ' ')
		endPosition--;
	return str.substr(startPosition, endPosition - startPosition + 1);
}
