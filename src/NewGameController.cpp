#include "stdafx.h"
#include "NewGameController.h"

string NewGameController::playerSheet;
int NewGameController::attributePointsLeft;
int NewGameController::skillPointsLeft;

NewGameController::NewGameController()
{
}


NewGameController::~NewGameController()
{
}

Controller* NewGameController::processUserInput()
{
	string command;
	getline(cin, command);
	interpretCommand(trim(command));
	return returnedController;
}

void NewGameController::updatePlayerSheet(string sheet)
{
	playerSheet = sheet;
}

void NewGameController::updateCreationPointsLeft(int attributePoints, int skillPoints)
{
	attributePointsLeft = attributePoints;
	skillPointsLeft = skillPoints;
}

void NewGameController::interpretCommand(string command)
{
	if (command == "finished")
		return finishCmd();
	else if (command == "abort")
		returnedController = new MainMenuController;
	else
		interpretCommandWithArguments(command);
}

void NewGameController::finishCmd()
{
	cout << "Procedure of saving and starting the game" << endl;
	system("pause");
	returnedController = new GameplayController;
}

void NewGameController::interpretCommandWithArguments(string command)
{
	vector <string> tokenizedCommand = splitString(command);
	if (tokenizedCommand[0] == "name")
		linkWithModel.changeNewCharacterName(trim(command.substr(5)));
	else if (tokenizedCommand.size() == 2)
		interpretTwoArgumentedCommand(tokenizedCommand[0], tokenizedCommand[1]);
	returnedController = this;
}

void NewGameController::interpretTwoArgumentedCommand(string firstCommandToken, string secondCommandToken)
{
	try
	{
		int value = stoi(secondCommandToken);
		linkWithModel.changeNewHeroAttributeSkill(firstCommandToken, value);
	}
	catch (const std::exception&) {}
}

void NewGameController::printScreen()
{
	cout << playerSheet << endl;
	cout << "Attribute points left: " << attributePointsLeft << endl <<
		"Skill points left: " << skillPointsLeft << endl;
	printInstruction();
	printMessageForUser();
	cout << ">";
}

void NewGameController::printInstruction()
{
	cout << "Instruction: assign skill and attribute points to your statistics, by typing: 'skill_name desired_value' and hitting 'enter'. Example: Might 3" << endl <<
		"Type 'name character_name' to give your character a new name, example: 'name Zdzislaw'" << endl <<
		"Type 'finished' and hit enter, when you are ready to start the game." << endl <<
		"Type 'abort' and hit enter, if you want to return to main menu." << endl << endl;
}

vector<string> NewGameController::splitString(string splitted)
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
