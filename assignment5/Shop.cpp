#include <EventSystem.h>
#include "Game.h"
#include <iostream>
#include <math.h>
#include "Shop.h"

using namespace std;

void Shop::addMoney(int amount) {
	mMoney += amount;
}

int Shop::getMoney() {
	return mMoney;
}

int Shop::getIngredientLevel()
{
	return ingredientLevel;
}

int Shop::getClickers()
{
	return clickers;
}

int Shop::getClickerLevel()
{
	return clickerLevel;
}

int Shop::getRepellantLevel()
{
	return repellantLevel;
}

void Shop::setIngredientLevel(int ingredLevel)
{
	ingredientLevel = ingredLevel;
}

void Shop::setClickers(int click)
{
	clickers = click;
}

void Shop::setClickerLevel(int clickLevel)
{
	clickerLevel = clickLevel;
}

void Shop::setRepellantLevel(int repellLevel)
{
	repellantLevel = repellLevel;
}

vector<bool> Shop::canPlayerBuyUpgrades()
{
	vector<bool> upgrades;
	upgrades.push_back((mMoney > Game::getInstance()->getLeveling()->getLevelCost())); // Ingredients
	upgrades.push_back((mMoney > 10 * clickerLevel * clickers + 10)); //Num Clickers
	upgrades.push_back((mMoney > 10 * clickers * clickerLevel + 10)); //Clicker
	upgrades.push_back((mMoney > 10 * (int)pow(2, repellantLevel) + 10)); //Repellent
	return upgrades;
}

Vector2D Shop::getAutoClickerPos()
{
	return Vector2D(mX,mY);
}

Shop::Shop() {
	mMoney = 0;
	ingredientLevel = 0;
	clickers = 0;
	clickerLevel = 0;
	repellantLevel = 0;
}

bool Shop::purchaseUpgrade(UpgradeType type) {
	int upgradeCost;
	switch(type) {
		case INGREDIENT:
			upgradeCost = Game::getInstance()->getLeveling()->getLevelCost();
			if(mMoney > upgradeCost) {
				mMoney -= upgradeCost;
				ingredientLevel++;
				Game::getInstance()->getLeveling()->LevelUp();
				return true;
			}
			cout << "insufficient funds" << endl;
			return false;
		case NUM_CLICKERS:
			upgradeCost = 10 * clickerLevel * clickers + 10;
			if(mMoney > upgradeCost) {
				mMoney -= upgradeCost;
				clickers++;
				Game::getInstance()->makeAutoClicker(400, 500);
				return true;
			}
			return false;
		case CLICKER:
			upgradeCost = 10 * clickers * clickerLevel + 10;
			if(mMoney > upgradeCost) {
				mMoney -= upgradeCost;
				clickerLevel++;
				Game::getInstance()->getUnitManager()->updateClickerRate();
				return true;
			}
			return false;
		case REPELLANT:
			upgradeCost = 10 * (int)pow(2, repellantLevel) + 10;
			if(mMoney > upgradeCost) {
				mMoney -= upgradeCost;
				repellantLevel++;
				Game::getInstance()->getSpawner()->updateSpawnRate();
				return true;
			}
			return false;
		default:
			cout << "invalid upgrade purchase" << endl;
	}
	return false;
}

int Shop::getUpgradeLevel(UpgradeType type) {
	switch(type) {
		case INGREDIENT:
			return ingredientLevel;
		case NUM_CLICKERS:
			return clickers;
		case CLICKER:
			return clickerLevel;
		case REPELLANT:
			return repellantLevel;
		default:
			cout << "invalid upgrade level check" << endl;
	}
	return 0;
}
