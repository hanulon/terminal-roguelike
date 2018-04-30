#include "stdafx.h"
#include "Point.h"


Point::Point() : Point(0,0) {}

Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}


Point::~Point()
{
}

bool Point::operator==(Point other)
{
	if (this->x == other.x && this->y == other.y)
		return true;
	return false;
}

Point Point::operator+(Point other)
{
	Point result;
	result.x = this->x + other.x;
	result.y = this->y + other.y;
	return result;
}

void Point::operator+=(Point other)
{
	this->x += other.x;
	this->y += other.y;
}
