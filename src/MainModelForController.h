#pragma once

class MainModelForController
{
public:
	MainModelForController();
	~MainModelForController();

	virtual void changeNewCharacterName(std::string name) = 0;
	virtual void changeNewHeroAttributeSkill(std::string attributeSkillName, int value) = 0;
	virtual void makePlayerStep(Point step) = 0;
	virtual void endTurn() = 0;
	virtual void playerTakeItemFromFloor() = 0;
	virtual void playerDropItem(std::string itemName) = 0;
	virtual void playerEquipItem(std::string itemName) = 0;
	virtual std::string playerGetItemDecription(std::string itemName) = 0;
	virtual void playerUnequipItem(std::string itemName) = 0;
	virtual std::string getPlayerEquipment() = 0;

	virtual std::string getDisplayedMap() = 0;
	virtual std::string getPlayerCharacterSheet() = 0;
	virtual std::string getPlayerGeneralInfo() = 0;
	virtual int getPlayerAttributePointsLeft() = 0;
	virtual int getPlayerSkillPointsLeft() = 0;
	virtual void interactionDecision(int subIter) = 0;
	virtual std::string getInteractionMessage() = 0;
	virtual bool hasInteractionAnySubinteractions() = 0;
	virtual std::string getAllEquippedAsString() = 0;

};

