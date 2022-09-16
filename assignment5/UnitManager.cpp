// Map version of this class exists at svn revision 250

#include "Ant.h"
#include "AutoClicker.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "UnitManager.h"

void UnitManager::addUnit(Unit* unit) {
	mUnitList.push_back(unit);
}

void UnitManager::clear() {
	for(unsigned int i = 0; i < mUnitList.size(); i++) {
		delete mUnitList[i];
	}

	mUnitList.clear();
}

/*
void UnitManager::deanifyLastUnit(Animation* deanAnimation) {
	mUnitList[mUnitList.size() - 1]->setAnimation(*deanAnimation);
}
*/

void UnitManager::draw(GraphicsSystem* gSystem) {
	for(unsigned int i = 0; i < mUnitList.size(); i++) {
		mUnitList[i]->draw(gSystem);
	}
}

Unit* UnitManager::getUnit(int index) {
	return mUnitList[index];
}

Unit* UnitManager::getFirstOfType(UnitType unitType)
{
	for (unsigned int i = 0; i < mUnitList.size(); i++)
	{
		if (mUnitList[i]->getType() == UnitType::BISCUIT)
		{
			return mUnitList[i];
		}
	}
	return nullptr;
}

vector<Unit*> UnitManager::getUnitsOfType(UnitType type) {
	vector<Unit*> result;
	
	for(unsigned int i = 0; i < mUnitList.size(); i++) {
		if(mUnitList[i]->getType() == type) {
			result.push_back(mUnitList[i]);
		}
	}

	return result;
}

void UnitManager::removeUnit(int mouseX, int mouseY) {
	for (unsigned int i = 0; i < mUnitList.size(); i++) {
		Unit* theUnit = mUnitList[i];
		bool inHorizontalBounds = mouseX >= theUnit->getX() && mouseX <= theUnit->getX() + theUnit->getSprite()->getWidth();
		bool inVerticalBounds = mouseY >= theUnit->getY() && mouseY <= theUnit->getY() + theUnit->getSprite()->getHeight();

		if (inHorizontalBounds && inVerticalBounds) {
			delete theUnit;
			mUnitList.erase(mUnitList.begin() + i);
			break;
		}
	}
}

void UnitManager::removeDeadUnits()
{
	if (mDeleteList.size() > 0)
	{
		for (unsigned int i = 0; i < mDeleteList.size(); i++)
		{
			delete mUnitList[mDeleteList[i]];
			mUnitList.erase(mUnitList.begin() + mDeleteList[i]);
		}
	}

	mDeleteList.clear();
}

void UnitManager::storeIndex(int mouseX, int mouseY, UnitType type) {
	for(unsigned int i = 0; i < mUnitList.size(); i++) {
		Unit* theUnit = mUnitList[i];
		bool inHorizontalBounds = mouseX >= theUnit->getX() && mouseX <= theUnit->getX() + theUnit->getSprite()->getWidth();
		bool inVerticalBounds = mouseY >= theUnit->getY() && mouseY <= theUnit->getY() + theUnit->getSprite()->getHeight();

		if(inHorizontalBounds && inVerticalBounds && type == theUnit->getType()) {
			mDeleteList.push_back(i);
		}
	}
}

/*
void UnitManager::toggleAnimationAll() {
	for(unsigned int i = 0; i < mUnitList.size(); i++) {
		mUnitList[i]->toggleAnimation();
	}
}
*/

UnitManager::UnitManager() {

}

UnitManager::~UnitManager() {
	clear();
}

void UnitManager::update(double deltaTime) {
	for(unsigned int i = 0; i < mUnitList.size(); i++) {
		mUnitList[i]->update(deltaTime);
	}
}

void UnitManager::updateAntsSpeed() {
	vector<Unit*> ants = getUnitsOfType(ANT);
	for(unsigned int i = 0; i < ants.size(); i++) {
		static_cast<Ant*>(ants[i])->updateMoveSpeed();
	}
}

void UnitManager::updateClickerRate() {
	for(unsigned int i = 0; i < mUnitList.size(); i++) {
		if(mUnitList[i]->getType() == AUTO_CLICKER) {
			static_cast<AutoClicker*>(mUnitList[i])->updateClickRate();
		}
	}
}