#include "stdafx.h"
#include "NewGameController.h"


NewGameController::NewGameController()
{
}


NewGameController::~NewGameController()
{
}

int NewGameController::main()
{
	string command;
	getline(cin, command);
	command = trim(command);
	if (command == "finished")
	{
		cout << "Procedure of saving and starting the game" << endl;
		system("pause");
		return 1;
	}
	else if (command == "abort")
		return 0;
	else
	{
		vector <string> tokenizedCommand = splitString(command);
		if (tokenizedCommand[0] == "name")
		{
			_ADDED_NAME = true;
			_NAME = command.substr(5);
		}
		else if (tokenizedCommand.size() == 2)
		{
			processTwoArgsNewGameCommand(tokenizedCommand[0], tokenizedCommand[1]);
		}
		return 2;
	}
}

void NewGameController::processTwoArgsNewGameCommand(string firstCommandToken, string secondCommandToken)
{
	try
	{
		int value = stoi(secondCommandToken);
		_ATTR_SKILL_CHANGED = true;
		_ATTR_SKILL = firstCommandToken;
		_VALUE = value;
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
