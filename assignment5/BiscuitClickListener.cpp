#include "BiscuitClickListener.h"
#include "EventSystem.h"
#include "Game.h"
#include <math.h>

BiscuitClickListener::BiscuitClickListener(int x, int y, int width, int height, bool state) : ClickListener(x, y, width, height) {
	mShop = Game::getInstance()->getShop();
	mLevels = Game::getInstance()->getLeveling();
	mState = state;
}

BiscuitClickListener::~BiscuitClickListener()
{
	mShop = nullptr;
}

bool BiscuitClickListener::getState()
{
	return mState;
}

void BiscuitClickListener::setState(bool state)
{
	mState = state;
}

void BiscuitClickListener::onLeftClick() {
	if(mState) {
		int biscuitValue = 10 * pow(1.1, mShop->getUpgradeLevel(INGREDIENT));
		mShop->addMoney(biscuitValue);
		mLevels->addAnotherClick();
		//cout << "You have " << mShop->getMoney() << " money" << endl;
		Game::getInstance()->getSoundSystem()->playAudioSample("kaching", 0);
	}
}