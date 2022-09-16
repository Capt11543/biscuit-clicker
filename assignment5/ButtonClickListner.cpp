#include "ButtonClickListener.h"
#include "EventSystem.h"
#include "GameEvents.h"
#include "Game.h"
#include "ButtonManager.h"



ButtonClickListener::ButtonClickListener(int x, int y, int width, int height, ButtonType id) : ClickListener(x, y, width, height) {
	mShop = Game::getInstance()->getShop();
	mpLevels = Game::getInstance()->getLeveling();
	mId = id;
}

ButtonClickListener::~ButtonClickListener()
{
	mShop = nullptr;
	mpLevels = nullptr;
}

void ButtonClickListener::setState(bool state)
{
	isActive = state;
}

void ButtonClickListener::onLeftClick() {
	//cout << "Gamer" << endl;
	if (isActive)
	{
		ButtonManager::fireEvent(mId);
		Game::getInstance()->getSoundSystem()->playAudioSample("click", 0);
	}
	
}