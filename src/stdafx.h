// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <string>
#include <vector>

#define WINDOWS
//#define LINUX

enum AttributeName
{
	None,
	Might,
	Dexterity,
	Smarts
};

struct Point
{
	int x;
	int y;
};

bool arePointsEqual(Point a, Point b);
