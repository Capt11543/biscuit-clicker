#include "AutoClicker.h"
#include "Game.h"

AutoClicker::AutoClicker(int x, int y, Biscuit* biscuit) : Unit(AUTO_CLICKER, x, y) {
	mBiscuit = biscuit;

	mShop = Game::getInstance()->getShop();
	
	mClickRate = 2000 - (50.0 * mShop->getUpgradeLevel(CLICKER));
	mClickTimer = 0;

	mInitialPos = y;
	mMoveDist = 100;
}

AutoClicker::~AutoClicker() {

}

void AutoClicker::draw(GraphicsSystem* gSystem) {
	gSystem->draw(getX(), getY(), *getSprite(), 0.05);
}

void AutoClicker::update(double deltaTime) {
	Unit::update(deltaTime);

	mClickTimer += deltaTime;
	if (mClickTimer >= mClickRate) {
		mBiscuit->getListener()->onLeftClick(); // yeah, manually calling this seems like a really bad idea, but it's the easiest way I could think of to do what I want to do here
		mClickTimer = 0;
	}

	setPosition(getX(), mInitialPos - mMoveDist * (mClickTimer / mClickRate));
}

void AutoClicker::updateClickRate() {
	mClickRate = 2000 - (50.0 * mShop->getUpgradeLevel(CLICKER));
}