#include "stdafx.h"
#include "Health.h"


Health::Health()
{
}


Health::~Health()
{
}

std::string Health::getHealthOnCharacterSheet()
{
	std::string healthSheet = "HP: " + std::to_string(this->currentHealthPoints);
	healthSheet += "/" + std::to_string(this->maximumHealthPoints);

	return healthSheet;
}
