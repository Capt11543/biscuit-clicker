#include "ButtonManager.h"
#include "EventSystem.h"
#include "Game.h"
#include "GameEvents.h"

ButtonManager::ButtonManager()
{
	mpText = new Text;
	mpReader = new TextReader;
	mpActiveButtons = &mpMainMenu;

	mpLanguageHolder = nullptr;
}

ButtonManager::~ButtonManager()
{
	clear();
}

void ButtonManager::addButton(Button* button, MenuType menuType, bool isEnabled)
{
	if (!mIsInited)
	{
		init();
	}
	button->setButtonState(isEnabled);
	switch (menuType)
	{
		case MAIN_MENU:
			mpMainMenu.push_back(button);
			break;
		case GAME_MENU:
			mpGameMenu.push_back(button);
			break;
		case PAUSE_MENU:
			mpPauseMenu.push_back(button);
			break;
		case DIFFICULTY_MENU:
			mpDifficultyMenu.push_back(button);
			break;
	}
}

void ButtonManager::update(double deltaTime)
{
	if (mMainMenuOn)
	{
		for (unsigned int i = 0; i < mpMainMenu.size(); i++) {
			mpMainMenu[i]->update(deltaTime);
		}
	}
	else if (mGameMenuOn)
	{
		for (unsigned int i = 0; i < mpGameMenu.size(); i++) {
			mpGameMenu[i]->update(deltaTime);
		}
	}
	else if (mPauseMenuOn)
	{
		for (unsigned int i = 0; i < mpPauseMenu.size(); i++) {
			mpPauseMenu[i]->update(deltaTime);
		}
	}
	else if (mDifficultyMenuOn)
	{
		for (unsigned int i = 0; i < mpDifficultyMenu.size(); i++) {
			mpDifficultyMenu[i]->update(deltaTime);
		}
	}
}

void ButtonManager::draw(GraphicsSystem* gSystem)
{
	assert(mpText);
	string text = " ";

	for (unsigned int i = 0; i < mpActiveButtons->size(); i++) {
		(*mpActiveButtons)[i]->draw(gSystem);
			
		switch ((*mpActiveButtons)[i]->getId())
		{
			case START:
				text = mpLanguageHolder->getTextAt(1);
				break;
			case QUIT:
				text = mpLanguageHolder->getTextAt(4);
				break;
			case OPTIONS:
				text = mpLanguageHolder->getTextAt(3);
				break;
			case PAUSE:
				text = "||";
				break;
			case VOLUME_UP:
				text = "+";
				break;
			case VOLUME_DOWN:
				text = "-";
				break;
			case SAVE:
				text = mpLanguageHolder->getTextAt(7);
				break;
			case LOAD:
				text = mpLanguageHolder->getTextAt(2);
				break;
			case LANGUAGE:
				text = mpLanguageHolder->getTextAt(6);
				break;
			case BACK:
				text = mpLanguageHolder->getTextAt(8);
				break;
			case SHOP_INGREDIENT:
				text = mpLanguageHolder->getTextAt(13);
				break;
			case SHOP_CLICKER:
				text = mpLanguageHolder->getTextAt(14);
				break;
			case SHOP_REPELLANT:
				text = mpLanguageHolder->getTextAt(15);
				break;
			case SHOP_NUM_CLICKERS:
				text = mpLanguageHolder->getTextAt(16);
				break;
			case DIFFICULTY_MIN:
				text = mpLanguageHolder->getTextAt(18);
				break;
			case DIFFICULTY_NEUTRAl:
				text = mpLanguageHolder->getTextAt(19);
				break;
			case DIFFICULTY_MAX:
				text = mpLanguageHolder->getTextAt(20);
				break;
			case GENERIC:
				text = mpLanguageHolder->getTextAt(11);
				break;
		}
		mpText->writeText((*mpActiveButtons)[i]->getX() + ((*mpActiveButtons)[i]->getWidth() / 2), (*mpActiveButtons)[i]->getY() + ((*mpActiveButtons)[i]->getHeight() / 4), text);
	}
}

void ButtonManager::clear()
{
	clearMenu(mpMainMenu);
	clearMenu(mpGameMenu);
	clearMenu(mpPauseMenu);
	clearMenu(mpDifficultyMenu);

	delete mpText;
	delete mpReader;
	mpActiveButtons = nullptr;
	mpLanguageHolder = nullptr;
}

void ButtonManager::switchMenu(MenuType menuType)
{
	switch (menuType)
	{
		case MAIN_MENU:
			mpActiveButtons = &mpMainMenu;
			mMainMenuOn = true;
			mPauseMenuOn = false;
			mGameMenuOn = false;
			mDifficultyMenuOn = false;
			setMenuButtonsState(mMainMenuOn, mpMainMenu);
			setMenuButtonsState(mGameMenuOn, mpGameMenu);
			setMenuButtonsState(mPauseMenuOn, mpPauseMenu);
			setMenuButtonsState(mDifficultyMenuOn, mpDifficultyMenu);
			break;
		case GAME_MENU:
			mpActiveButtons = &mpGameMenu;
			mGameMenuOn = true;
			mMainMenuOn = false;
			mPauseMenuOn = false;
			mDifficultyMenuOn = false;
			setMenuButtonsState(mMainMenuOn, mpMainMenu);
			setMenuButtonsState(mGameMenuOn, mpGameMenu);
			setMenuButtonsState(mPauseMenuOn, mpPauseMenu);
			setMenuButtonsState(mDifficultyMenuOn, mpDifficultyMenu);
			break;
		case PAUSE_MENU:
			mpActiveButtons = &mpPauseMenu;
			mPauseMenuOn = true;
			mMainMenuOn = false;
			mGameMenuOn = false;
			mDifficultyMenuOn = false;
			setMenuButtonsState(mMainMenuOn, mpMainMenu);
			setMenuButtonsState(mGameMenuOn, mpGameMenu);
			setMenuButtonsState(mPauseMenuOn, mpPauseMenu);
			setMenuButtonsState(mDifficultyMenuOn, mpDifficultyMenu);
			break;
		case DIFFICULTY_MENU:
			mpActiveButtons = &mpDifficultyMenu;
			mDifficultyMenuOn = true;
			mPauseMenuOn = false;
			mMainMenuOn = false;
			mGameMenuOn = false;
			setMenuButtonsState(mMainMenuOn, mpMainMenu);
			setMenuButtonsState(mGameMenuOn, mpGameMenu);
			setMenuButtonsState(mPauseMenuOn, mpPauseMenu);
			setMenuButtonsState(mDifficultyMenuOn, mpDifficultyMenu);
			break;
	}
	justSwitched = true;
}

void ButtonManager::setMenuButtonsState(bool state, vector<Button*> &buttons)
{
	for (unsigned int i = 0; i < buttons.size(); i++)
	{
		buttons[i]->setButtonState(state);
	}
}

void ButtonManager::fireEvent(ButtonType buttonType)
{
	switch (buttonType)
	{
		case START:
			EventSystem::getInstance()->fireEvent(StartGameEvent());
			break;
		case QUIT:
			EventSystem::getInstance()->fireEvent(QuitGameEvent());
			break;
		case OPTIONS:
			EventSystem::getInstance()->fireEvent(OptionsMenuEvent());
			break;
		case PAUSE:
			EventSystem::getInstance()->fireEvent(OptionsMenuEvent());
			break;
		case VOLUME_UP:
			EventSystem::getInstance()->fireEvent(RaiseVolumeEvent());
			break;
		case VOLUME_DOWN:
			EventSystem::getInstance()->fireEvent(LowerVolumeEvent());
			break;
		case SAVE:
			EventSystem::getInstance()->fireEvent(SaveGameEvent());
			break;
		case LOAD:
			EventSystem::getInstance()->fireEvent(LoadGameEvent());
			break;
		case LANGUAGE:
			EventSystem::getInstance()->fireEvent(ChangeLanguageEvent());
			break;
		case BACK:
			EventSystem::getInstance()->fireEvent(ReturnToPreviousState());
			break;
		case SHOP_INGREDIENT:
			EventSystem::getInstance()->fireEvent(ShopEvent(INGREDIENT));
			break;
		case SHOP_CLICKER:
			EventSystem::getInstance()->fireEvent(ShopEvent(CLICKER));
			break;
		case SHOP_REPELLANT:
			EventSystem::getInstance()->fireEvent(ShopEvent(REPELLANT));
			break;
		case SHOP_NUM_CLICKERS:
			EventSystem::getInstance()->fireEvent(ShopEvent(NUM_CLICKERS));
			break;
		case DIFFICULTY_MIN:
			EventSystem::getInstance()->fireEvent(StartGameAtDifficultyEvent(1));
			break;
		case DIFFICULTY_NEUTRAl:
			EventSystem::getInstance()->fireEvent(StartGameAtDifficultyEvent(5));
			break;
		case DIFFICULTY_MAX:
			EventSystem::getInstance()->fireEvent(StartGameAtDifficultyEvent(8));
			break;
		case GENERIC:
			break;
	}
}

void ButtonManager::readFile(string loc, string file)
{
	mpReader->readFile(loc, file);
}

void ButtonManager::checkIfShopButtonsEnabled()
{
	vector<bool> upgrades = Game::getInstance()->getShop()->canPlayerBuyUpgrades();
	for (unsigned int i = 0; i < mpGameMenu.size(); i++)
	{
		if (mpGameMenu[i]->getId() == SHOP_INGREDIENT)
		{
			if (!upgrades[0])
			{
				mpGameMenu[i]->setButtonState(upgrades[0]);
				mpGameMenu[i]->setSprite(Game::getInstance()->getSpriteManager()->getSprite("buttonGraySprite"));
				
			}
			else {
				mpGameMenu[i]->setButtonState(upgrades[0]);
				mpGameMenu[i]->setSprite(Game::getInstance()->getSpriteManager()->getSprite("buttonSprite"));
			}
		}
		else if (mpGameMenu[i]->getId() == SHOP_NUM_CLICKERS) {
			if (!upgrades[1])
			{
				mpGameMenu[i]->setButtonState(upgrades[1]);
				mpGameMenu[i]->setSprite(Game::getInstance()->getSpriteManager()->getSprite("buttonGraySprite"));

			}
			else {
				mpGameMenu[i]->setButtonState(upgrades[1]);
				mpGameMenu[i]->setSprite(Game::getInstance()->getSpriteManager()->getSprite("buttonSprite"));
			}
		}
		else if (mpGameMenu[i]->getId() == SHOP_CLICKER) {
			if (!upgrades[2])
			{
				mpGameMenu[i]->setButtonState(upgrades[2]);
				mpGameMenu[i]->setSprite(Game::getInstance()->getSpriteManager()->getSprite("buttonGraySprite"));

			}
			else {
				mpGameMenu[i]->setButtonState(upgrades[2]);
				mpGameMenu[i]->setSprite(Game::getInstance()->getSpriteManager()->getSprite("buttonSprite"));
			}
		}
		else if (mpGameMenu[i]->getId() == SHOP_REPELLANT) {
			if (!upgrades[3])
			{
				mpGameMenu[i]->setButtonState(upgrades[3]);
				mpGameMenu[i]->setSprite(Game::getInstance()->getSpriteManager()->getSprite("buttonGraySprite"));

			}
			else {
				mpGameMenu[i]->setButtonState(upgrades[3]);
				mpGameMenu[i]->setSprite(Game::getInstance()->getSpriteManager()->getSprite("buttonSprite"));
			}
		}
	}
}

bool ButtonManager::isMainMenuOn()
{
	return mMainMenuOn;
}

bool ButtonManager::isGameMenuOn()
{
	return mGameMenuOn;
}

bool ButtonManager::isPauseMenuOn()
{
	return mPauseMenuOn;
}

void ButtonManager::setFont(string fontFile, int fontSize)
{
	mpText->setFont(fontFile, fontSize);
}

void ButtonManager::setColor(int red, int green, int blue, int alpha)
{
	mpText->setColor(red, green, blue, alpha);
}

void ButtonManager::init()
{
	mpLanguageHolder = Game::getInstance()->getLanguage();
	mIsInited = false;
}

void ButtonManager::clearMenu(vector<Button*> buttonVector)
{
	for (unsigned int i = 0; i < buttonVector.size(); i++) {
		delete buttonVector[i];
	}

	buttonVector.clear();
}