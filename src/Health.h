#pragma once
class Health
{
public:
	Health();
	~Health();

	int currentHealthPoints;
	int maximumHealthPoints;
	std::string getHealthOnCharacterSheet();

private:

};

