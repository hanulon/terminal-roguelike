#pragma once
class ViewManager
{
public:
	ViewManager();
	~ViewManager();

	void refresh();

	int activeScreen;
	std::string gameMapState;
	std::string playerSheet;
	std::string playerShortInfo;
	void setNewGamePointsLeft(int attributes, int skills);
	void clearScreen();

private:
	void mainMenu();
	void gameplay();
	void newGame();
	void graveyard();
	void about();

	int attributePointsLeft;
	int skillPointsLeft;
};

