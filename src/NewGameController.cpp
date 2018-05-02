#include "stdafx.h"
#include "NewGameController.h"


NewGameController::NewGameController()
{
}


NewGameController::~NewGameController()
{
}

Controller* NewGameController::main()
{
	string command;
	getline(cin, command);
	command = trim(command);
	if (command == "finished")
	{
		cout << "Procedure of saving and starting the game" << endl;
		system("pause");
		return new GameplayController;
	}
	else if (command == "abort")
		return new MainMenuController;
	else
	{
		vector <string> tokenizedCommand = splitString(command);
		if (tokenizedCommand[0] == "name")
		{
			userControllerMessage.actionType = NameChanged;
			userControllerMessage.name = command.substr(5);
		}
		else if (tokenizedCommand.size() == 2)
		{
			processTwoArgsNewGameCommand(tokenizedCommand[0], tokenizedCommand[1]);
		}
		return this;
	}
}

void NewGameController::printScreen()
{
	cout << playerSheet << endl;
	cout << "Attribute points left: " << attributePointsLeft << endl <<
		"Skill points left: " << skillPointsLeft << endl <<
		"Instruction: assign skill and attribute points to your statistics, by typing: 'skill_name desired_value' and hitting 'enter'. Example: Might 3" << endl <<
		"Type 'name character_name' to give your character a new name, example: 'name Zdzislaw'" << endl <<
		"Type 'finished' and hit enter, when you are ready to start the game." << endl <<
		"Type 'abort' and hit enter, if you want to return to main menu." << endl << endl << ">";
}

void NewGameController::processTwoArgsNewGameCommand(string firstCommandToken, string secondCommandToken)
{
	try
	{
		int value = stoi(secondCommandToken);
		userControllerMessage.actionType = AttrSkillChanged;
		userControllerMessage.attributeSkillName = firstCommandToken;
		userControllerMessage.value = value;
	}
	catch (const std::exception&) {}
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
