#include "stdafx.h"
#include "InventoryController.h"


InventoryController::InventoryController()
{
}


InventoryController::~InventoryController()
{
}

Controller * InventoryController::processUserInput()
{
	string command;
	getline(cin, command);
	vector <string> tokenizedCommand = splitString(command);
	if (tokenizedCommand[0] == "quit")
		returnedController = new GameplayController;
	else if (tokenizedCommand[0] == "drop")
		mainModel->playerDropItem(tokenizedCommand[1]);
	else if (tokenizedCommand[0] == "equip" || tokenizedCommand[0] == "wear")
		mainModel->playerEquipItem(tokenizedCommand[1]);
	else if (tokenizedCommand[0] == "see")
		selectedItemName = tokenizedCommand[1];
	else if (tokenizedCommand[0] == "unequip")
		mainModel->playerUnequipItem(tokenizedCommand[1]);
	else if (tokenizedCommand[0] == "use")
		mainModel->playerUseItem(tokenizedCommand[1]);

	return returnedController;
}

void InventoryController::printScreen()
{
	cout << "\tInventory screen\n" << endl;
	cout << "Equipped items:\n";
	cout << mainModel->getAllEquippedAsString() << endl;
	cout << "Inventory:\n";
	cout << mainModel->getPlayerEquipment() << endl;
	if (selectedItemName.size() > 0)
	{
		cout << "Item description:\n";
		cout << mainModel->playerGetItemDecription(selectedItemName) << endl << endl;
		selectedItemName = "";
	}
	cout << "Type:\n"
		"equip item_name OR wear item_name - try to equip selected item\n"
		"unequip item_name - unequip selected item\n"
		"see item_name - see description of the item\n"
		"drop item_name - drop th item\n"
		"quit - return to game.\n";
	cout << ">";
}
