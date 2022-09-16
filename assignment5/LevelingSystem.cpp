#include "Game.h"
#include "LevelingSystem.h"

using namespace std;

LevelingSystem::LevelingSystem()
{
	totalClicks = -1;
	fileMaxLevel = -1;
}

LevelingSystem::~LevelingSystem()
{
}

void LevelingSystem::init(std::string fileLoc)
{
	totalClicks = 0;
	string tempString;
	int spaceIndex;
	string tempSubString;
	int semicolonIndex;

	const string ASSET_PATH = "..\\assets\\";
	ifstream levelReading (ASSET_PATH + mFileName);
	getline(levelReading, tempString);
	spaceIndex = tempString.find(" ");
	//cout << spaceIndex << endl; //Comment this out or remove when they're not needed
	fileMaxLevel = tempString[spaceIndex + 1] - 48;
	if (levelReading.is_open()) {
		for (int i = 0; i < MAX_LEVEL; i++) {
			getline(levelReading, tempString);
			for (int j = 0; j < 5; j++) {
				spaceIndex = tempString.find(" ");
				semicolonIndex = tempString.find(";");
				tempSubString = tempString.substr(spaceIndex, spaceIndex + semicolonIndex - 1);
				tempString = tempString.substr(semicolonIndex+1);
				//cout << spaceIndex << "+" << semicolonIndex << endl;
				mLevelInfo[i][j] = stoi(tempSubString);
			}
		}
	}
}

void LevelingSystem::LevelUp()
{
	if (mLevel < MAX_LEVEL) {
		mLevel++;
	}
	Game::getInstance()->getUnitManager()->updateAntsSpeed();
}

std::string LevelingSystem::getFileName()
{
	return mFileName;
}

int LevelingSystem::getLevel()
{
	return mLevel;
}

void LevelingSystem::setLevel(int level)
{
	mLevel = level;
	//cout << "Level:" << mLevel << endl;
}

int LevelingSystem::getLevelCost() {
	return mLevelInfo[mLevel - 1][1];
}

int LevelingSystem::getAntSpeed()
{
	return mLevelInfo[mLevel - 1][2];
}

int LevelingSystem::getTimeBetweenAnts()
{
	return mLevelInfo[mLevel - 1][3];
}

int LevelingSystem::getNumAnts()
{
	return mLevelInfo[mLevel - 1][4];
}

void LevelingSystem::addAnotherClick()
{
	totalClicks++;
}

void LevelingSystem::addSetAmountOfClicks(int value)
{
	totalClicks += value;
}

int LevelingSystem::getTotalClickCount()
{
	return totalClicks;
}
