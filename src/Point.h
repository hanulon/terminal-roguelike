#pragma once
class Point
{
public:
	Point();
	Point(int x, int y);
	~Point();

	int x;
	int y;
	bool operator== (Point other);
	Point operator+ (Point other);
	void operator+= (Point other);
};

