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
#include "Point.h"

#define WINDOWS
//#define LINUX

const std::string GAME_VERSION = "0.0.3";

enum AttributeName
{
	None,
	Might,
	Dexterity,
	Smarts
};

enum TurnStatus
{
	EndTurn,
	ContinueTurn
};

extern Point _STEP;
extern TurnStatus _STEP_MADE;
extern bool _ADDED_NAME;
extern std::string _NAME;
extern bool _ATTR_SKILL_CHANGED;
extern std::string _ATTR_SKILL;
extern int _VALUE;
extern std::string gameMapState;
extern std::string playerSheet;
extern std::string playerShortInfo;
extern int attributePointsLeft;
extern int skillPointsLeft;