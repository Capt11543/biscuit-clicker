#pragma once

#include <iostream>
#include <fstream>
#include <istream>
#include <Trackable.h>
#include <vector>
#include <cassert>
#include <string>
#include <map>

#include "TextReader.h"


class LevelingSystem : public Trackable {
public:
	LevelingSystem();
	~LevelingSystem();

	void init(std::string fileLoc);
	void LevelUp();

	std::string getFileName();
	int getLevel();
	void setLevel(int level);

	int getLevelCost();
	int getAntSpeed();
	int getTimeBetweenAnts();
	int getNumAnts();

	void addAnotherClick();
	void addSetAmountOfClicks(int value);

	int getTotalClickCount();
private:
	std::string mFileName = "game.txt";

	//Game modified variables
	int mLevel = 1;

	//File modified variables
	//first address is the level the second address is the stat
	//stat 0 is level, stat 1 is level cost, stat 2 is ant speed, stat 3 is time between ants, stat 4 is number of ants
	static const int MAX_LEVEL = 8;
	int fileMaxLevel;
	int mLevelInfo[MAX_LEVEL][5] = {0};

	//int mMaxXP, mAntSpeed, mTimeBetweenAnts, mNumAnts;
	//std::string mCurrentLevelStats;

	//int mMaxLevel;
	int totalClicks;
};

/*
Probably make class static

Manages:
- XP -> Level

Updates:
UI
- Update Level
- Update XP bar
Ant
- Ant Speed
- Time between Ant appearances
- Number of ants
Upgrades
- Unlock new upgrades
*/