#include "stdafx.h"
#include "MapObstacle.h"


MapObstacle::MapObstacle(std::string name)
{
	this->name = name;
}


MapObstacle::~MapObstacle()
{
}

void MapObstacle::setName(std::string name)
{
	this->name = name;
}

std::string MapObstacle::getName()
{
	return this->name;
}

char MapObstacle::getNameFirstLetter()
{
	return this->name[0];
}

void MapObstacle::setMapPosition(Point position)
{
	this->mapPosition = position;
}

Point MapObstacle::getMapPosition()
{
	return this->mapPosition;
}