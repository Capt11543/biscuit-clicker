#include "OptionsState.h"
#include "Game.h"

OptionsState::OptionsState()
{
	mpButtonManager = Game::getInstance()->getButtonManager();
	mpGameSystem = Game::getInstance()->getSystem();
	mpSpriteManager = Game::getInstance()->getSpriteManager();
	mpText = new Text;
	mIsInited = false;
	mSavedGame = false;
	mEnableButtons = false;

	mWidth = -1;
	mHeight = -1;
	mSavedCount = 0;
}

OptionsState::~OptionsState()
{
	mpGameSystem = nullptr;
	mpSpriteManager = nullptr;
	mpButtonManager = nullptr;
	delete mpText;
}

void OptionsState::init(int width, int height, int timePerframe)
{
	if (mIsInited)
	{
		returnedToState();
	}
	else {
		mWidth = width;
		mHeight = height;

		const string ASSET_PATH = "..\\assets\\";
		const string FONT_FILENAME = "COMIC.TTF";
		const string BUTTON_FILENAME = "button.png";
		const int FONT_SIZE = 24;
		const string BUTTON_SMALL = "button_small.png";
		const string MENU_BACKGROUND_FILENAME = "red.png";

		setFont(FONT_FILENAME, ASSET_PATH, FONT_SIZE);
		setColor();

		int tempWidth = Game::getInstance()->getBufferManager()->getGraphicsBuffer("buttonBuffer")->getWidth();
		int tempHeight = Game::getInstance()->getBufferManager()->getGraphicsBuffer("buttonBuffer")->getHeight();

		initButton(tempWidth, tempHeight);

		mIsInited = true;
		mEnableButtons = true;
	}
}

void OptionsState::initButton(int tempWidth, int tempHeight)
{
	Button* aButton = new Button((mWidth / 2) - (tempWidth / 2) - 10, ((mHeight / 2) - (tempHeight / 2)) - tempHeight, Game::getInstance()->getBufferManager()->getGraphicsBuffer("buttonSmallBuffer")->getWidth(), Game::getInstance()->getBufferManager()->getGraphicsBuffer("buttonSmallBuffer")->getHeight() + 10, ButtonType::VOLUME_UP);
	aButton->setSprite(Game::getInstance()->getSpriteManager()->getSprite("buttonSmallSprite"));
	mpButtonManager->addButton(aButton, ButtonManager::PAUSE_MENU, false);

	aButton = new Button((mWidth / 2) + (tempWidth / 6) + 10, ((mHeight / 2) - (tempHeight / 2)) - tempHeight, Game::getInstance()->getBufferManager()->getGraphicsBuffer("buttonSmallBuffer")->getWidth(), Game::getInstance()->getBufferManager()->getGraphicsBuffer("buttonSmallBuffer")->getHeight() + 10, ButtonType::VOLUME_DOWN);
	aButton->setSprite(Game::getInstance()->getSpriteManager()->getSprite("buttonSmallSprite"));
	mpButtonManager->addButton(aButton, ButtonManager::PAUSE_MENU, false);

	aButton = new Button((mWidth / 2) - (tempWidth / 2), ((mHeight / 2) - (tempHeight / 2)), tempWidth, tempHeight + 10, ButtonType::LANGUAGE);
	aButton->setSprite(Game::getInstance()->getSpriteManager()->getSprite("buttonSprite"));
	mpButtonManager->addButton(aButton, ButtonManager::PAUSE_MENU, false);

	aButton = new Button((mWidth / 2) - (tempWidth / 2), ((mHeight / 2) - (tempHeight / 2)) + tempHeight, tempWidth, tempHeight + 10, ButtonType::SAVE);
	aButton->setSprite(Game::getInstance()->getSpriteManager()->getSprite("buttonSprite"));
	mpButtonManager->addButton(aButton, ButtonManager::PAUSE_MENU, false);

	aButton = new Button((mWidth / 2) - (tempWidth / 2), ((mHeight / 2) - (tempHeight / 2)) + (tempHeight * 2), tempWidth, tempHeight + 10, ButtonType::BACK);
	aButton->setSprite(Game::getInstance()->getSpriteManager()->getSprite("buttonSprite"));
	mpButtonManager->addButton(aButton, ButtonManager::PAUSE_MENU, false);
}

void OptionsState::update(double deltaTime)
{
	mpButtonManager->update(deltaTime);

	if (mEnableButtons)
	{
		mEnableButtons = false;
		mpButtonManager->switchMenu(ButtonManager::MenuType::PAUSE_MENU);
	}
}

void OptionsState::draw()
{
	mpGameSystem->getGraphicsSystem()->draw(0, 0, *(mpSpriteManager->getSprite("menuSprite")));


	int tempHeight = Game::getInstance()->getBufferManager()->getGraphicsBuffer("buttonSmallBuffer")->getHeight();
	mpText->writeText(mWidth / 2, ((mHeight / 2) - (tempHeight * 1.2)), Game::getInstance()->getLanguage()->getTextAt(5));
	if (mSavedGame && mSavedCount <= 60)
	{
		mpText->writeText(mWidth / 2, mHeight - 100, Game::getInstance()->getLanguage()->getTextAt(12));
		mSavedCount++;
	}
	else if (mSavedCount > 60)
	{
		mSavedCount = 0;
		mSavedGame = false;
	}

	mpButtonManager->draw(mpGameSystem->getGraphicsSystem());
}

void OptionsState::setFont(const string fileName, const string path, const int fontSize)
{
	mpText->setFont(path + fileName, fontSize);
}

void OptionsState::setColor()
{
	mpText->setColor(0, 0, 0, 255);
}

void OptionsState::saveSuccessfulTextOn()
{
	mSavedGame = true;
}

void OptionsState::returnedToState()
{
	mEnableButtons = true;
}

void OptionsState::leavingState()
{
	mSavedGame = false;
	mSavedCount = 0;
}
