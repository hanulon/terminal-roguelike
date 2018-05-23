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

	this->immovableObstacle = new MapObstacle("Column");
	this->computerTerminalObstacle = new MapObstacle("Terminal-Computer");
	this->computerTerminalObstacle->addNewItem(Item("Disk1"));
	this->computerTerminalObstacle->addNewItem(Item("Disk2"));
	this->computerTerminalObstacle->addNewItem(Item("Disk3"));
	this->droppedItem = new Item("Loot");

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
	immovableObstacle->setMapPosition(Point(10, 10));
	computerTerminalObstacle->setMapPosition(Point(20, 10));
	this->gameMap->addItemTo(Point(10, 12), *droppedItem);

	gameMap->addObstacleToMap(playerCharacter, playerCharacter->getMapPosition());
	for(int i=0; i<npcVector.size(); i++)
		gameMap->addObstacleToMap(npcVector[i], npcVector[i]->getMapPosition());
	gameMap->addObstacleToMap(immovableObstacle, immovableObstacle->getMapPosition());
	gameMap->addObstacleToMap(computerTerminalObstacle, computerTerminalObstacle->getMapPosition());
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
	case ControllerToModelConnector::TakeItemFromFloor:
		playerTakeItemFromFloor();
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

void TerminalScreen::playerTakeItemFromFloor()
{
	try
	{
		Item takenItem = gameMap->getAndRemoveTopItemFrom(playerCharacter->getMapPosition());
		playerCharacter->addNewItem(takenItem);
	}
	catch (const std::exception&)
	{
	}
}

void TerminalScreen::endTurn()
{
	Point playerStep = linkFromController->getPlayerStep();
	if (!(playerStep == Point()))
	{
		playerMakesMove(playerStep);
	}
	npcsTakeActions();
	userInterface->updateMessageForUser(gameMap->getItemsNamesFrom(playerCharacter->getMapPosition()));
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
		MapObstacle* crashedObstacle = gameMap->getObstacleFrom(newPlayerPosition);
		if (crashedObstacle != nullptr)
		{
			playerCrashesSomething(crashedObstacle);
		}
	}
	else
	{
		gameMap->moveCreatureToDesiredPosition(playerCharacter, newPlayerPosition);
		playerCharacter->setMapPosition(newPlayerPosition);
	}
}

void TerminalScreen::playerCrashesSomething(MapObstacle * obstacle)
{
	NonPlayerCharacter* npc = dynamic_cast<NonPlayerCharacter*>(obstacle);
	if (npc != nullptr)
		playerCrashesNpc(playerCharacter, npc);
	else
		playerCrashesObstacle(playerCharacter, obstacle);
}

void TerminalScreen::playerCrashesNpc(Hero * playerCharacter, NonPlayerCharacter * npc)
{
	if (npc->isEnemy)
		cout << "Player attacked enemy!" << endl;
	else
		cout << "Player contacted friendly NPC!" << endl;
	system("pause");
}

bool isComputerUsable = true;

void TerminalScreen::playerCrashesObstacle(Hero * playerCharacter, MapObstacle * obstacle)
{
	//cout << "Player crashed immovable obstacle: " << obstacle->getName() << "\n";
	if (obstacle->getNameFirstLetter() == 'T')
	{
		bool endOfInteraction = false;
		bool hackedOnce = false;
		bool isOnceHeadsmashed = false;
		if (isComputerUsable)
		{
			while (!endOfInteraction)
			{
				string normalOutput = "You come closer to the object and see that this is some sort of a computer terminal."
					"Thankfully, it seems that you can power it up."
					"After a while, a dialog box appears on the screen, asking you to provide your login and password.\n";
				normalOutput += "1. [Hacking == 3] Hack the system.\n"
					"2.[if hacked once] Read emails.\n"
					"3.[If items_vector.size() > 0] Get all data disks from the terminal.\n"
					"4.[If player items count > 0] Put a disk in it, and reboot.\n"
					"5. Smash the keyboard - what could possibly go wrong ? \n"
					"6.[if once chosen 5] Destroy the terminal - if I can't use it, no one will!\n"
					"7. Leave the terminal.\n";
				cout << normalOutput;
				int keyCode = _getch();
				switch (keyCode)
				{
				case '1':
					if (playerCharacter->getSkillByName("Hacking") >= 3)
					{
						hackedOnce = true;
						cout << "You have full access to the termianal." << endl;
					}
					break;
				case '2':
					if (hackedOnce)
					{
						cout << "To dsdasjdask From Zdzislaw\n"
							"You idiots! I'll kill you, I'll kill you all! You do not make a fool out of Zdzislaw, the Hero of the Galaxy!"
							"You're all gonna regret this! I've installed a nuclear bomb in your facility, when I click the button you're all gonna be very sorry.\n\n"
							"Cheers,\n"
							"Zdzislaw\n\n"
							"P.S.: Just joking, happy April's Fools! :) Still waiting for my pay though.\n"
							"P.S.2 : The part about the bomb was not a joke.\n"
							"P.S.3 : Or was it ? !\n";
					}
					break;
				case '3':
					if (obstacle->getListOfPossessedItems().length()>0)
					{
						cout << "You've taken some disks from the computer." << endl;
						vector <Item> itemsFromComputer = obstacle->getAllItemsAndRemove();
						for (int i = 0; i < itemsFromComputer.size(); i++)
						{
							playerCharacter->addNewItem(itemsFromComputer[i]);
						}
					}
					break;
				case '4':
					if (playerCharacter->getListOfPossessedItems().length()>0)
					{
						cout << "You're giving everything you have to computer" << endl;
						vector <Item> itemsFromPlayer = playerCharacter->getAllItemsAndRemove();
						for (int i = 0; i < itemsFromPlayer.size(); i++)
						{
							obstacle->addNewItem(itemsFromPlayer[i]);
						}
					}
					break;
				case '5':
					cout << "You've hit a keyboard with your forehead, but you don't think that it helped." << endl;
					isOnceHeadsmashed = true;
					break;
				case '6':
					if (isOnceHeadsmashed)
					{
						cout << "Fatal smash" << endl;
						isComputerUsable = false;
						endOfInteraction = true;
					}
					break;
				case '7':
					endOfInteraction = true;
					break;
				default:
					break;
				}
			}
		}
		else
		{
			cout << "The computer is broken, and thus absolutely unusable";
			system("pause");
		}
	}
	else
	{
		string normalOutput = "You try to headbutt the obstacle, but you get nothing more than a bruise on your forehead.";
		cout << normalOutput;
		system("pause");
	}
}

void TerminalScreen::npcMakesMove(NonPlayerCharacter * npc)
{
	Point npcNewPosition = npc->tryToMove();
	if (this->gameMap->isTheTileOccupied(npcNewPosition))
	{
		MapObstacle* crashedObstacle = gameMap->getObstacleFrom(npcNewPosition);
		if (crashedObstacle != nullptr)
		{
			NonPlayerCharacter* anotherNpc = dynamic_cast<NonPlayerCharacter*>(crashedObstacle);
			if (anotherNpc != nullptr)
				npcCrashesNpc(npc, anotherNpc);
			else
			{
				Hero* hero = dynamic_cast<Hero*>(crashedObstacle);
				if (hero != nullptr)
					npcCrashesPlayer(hero, npc);
				else npcCrashesObstacle(npc, crashedObstacle);
			}
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

void TerminalScreen::npcCrashesObstacle(NonPlayerCharacter * npc, MapObstacle * obstacle)
{
	cout << "Npc crashed immovable obstacle: " << obstacle->getName() << "\n";
	system("pause");
}

void TerminalScreen::assignAttributeSkillActionInNewGameMenu(string attributeSkillName, int value)
{
	if (value >= 0)
		playerCharacter->setAttributeOrSkillHeroCreator(attributeSkillName, value);
}
