#pragma once
class ViewManager
{
public:
	ViewManager();
	~ViewManager();

	void refresh();
	void openMainMenu();
	void openGameplay();
	void openNewGame();
	void openGraveyard();
	void openAbout();

	void updateNewGamePointsLeft(int attributes, int skills);
	void updatePlayerSheet(std::string sheet);
	void updatePlayerShortInfo(std::string shortInfo);
	void updateMap(std::string map);

private:
	void (ViewManager::*activeScreen)() = NULL;
	void mainMenu();
	void gameplay();
	void newGame();
	void graveyard();
	void about();
	void clearScreen();

	std::string gameMapState;
	std::string playerSheet;
	std::string playerShortInfo;
	int attributePointsLeft;
	int skillPointsLeft;
};

