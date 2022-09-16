#include "DifficultyState.h"
#include "Game.h"
#include "Button.h"

void DifficultyState::draw()
{
	mpGameSystem->getGraphicsSystem()->draw(0, 0, *(mpSpriteManager->getSprite("menuSprite")));

	mpText->writeText(mWidth / 2, 50, Game::getInstance()->getLanguage()->getTextAt(17));

	mpButtonManager->draw(mpGameSystem->getGraphicsSystem());
}

DifficultyState::DifficultyState()
{
	mpGameSystem = Game::getInstance()->getSystem();
	mpSpriteManager = Game::getInstance()->getSpriteManager();
	mpButtonManager = Game::getInstance()->getButtonManager();
	mpText = new Text;
}

DifficultyState::~DifficultyState()
{
	mpGameSystem = nullptr;
	mpSpriteManager = nullptr;
	mpButtonManager = nullptr;
	delete mpText;
}

void DifficultyState::init(int width, int height, int timePerframe)
{
	mWidth = width;
	mHeight = height;

	const string ASSET_PATH = "..\\assets\\";
	const string FONT_FILENAME = "COMIC.TTF";
	const int SCORE_DISPLAY_FONT_SIZE = 50;

	mpText->setFont(ASSET_PATH + FONT_FILENAME, SCORE_DISPLAY_FONT_SIZE);
	mpText->setColor(0, 0, 0, 255);

	int tempWidth = Game::getInstance()->getBufferManager()->getGraphicsBuffer("buttonBuffer")->getWidth();
	int tempHeight = Game::getInstance()->getBufferManager()->getGraphicsBuffer("buttonBuffer")->getHeight();

	Button* aButton = new Button(0 + 10, ((mHeight / 2) - (tempHeight / 2)) + tempHeight, tempWidth, tempHeight + 10, ButtonType::DIFFICULTY_MIN);
	aButton->setSprite(Game::getInstance()->getSpriteManager()->getSprite("buttonSprite"));
	mpButtonManager->addButton(aButton, ButtonManager::DIFFICULTY_MENU);

	aButton = new Button((mWidth / 2) - (tempWidth / 2) + 10, ((mHeight / 2) - (tempHeight / 2)) + tempHeight, tempWidth, tempHeight + 10, ButtonType::DIFFICULTY_NEUTRAl);
	aButton->setSprite(Game::getInstance()->getSpriteManager()->getSprite("buttonSprite"));
	mpButtonManager->addButton(aButton, ButtonManager::DIFFICULTY_MENU);

	aButton = new Button(Game::getInstance()->getBufferManager()->getGraphicsBuffer("buttonBuffer")->getWidth() * 2.5 + 10, ((mHeight / 2) - (tempHeight / 2)) + tempHeight, tempWidth, tempHeight + 10, ButtonType::DIFFICULTY_MAX);
	aButton->setSprite(Game::getInstance()->getSpriteManager()->getSprite("buttonSprite"));
	mpButtonManager->addButton(aButton, ButtonManager::DIFFICULTY_MENU);

	mEnableButtons = true;
}

void DifficultyState::update(double deltaTime)
{
	mpButtonManager->update(deltaTime);
	if (mEnableButtons)
	{
		mEnableButtons = false;
		mpButtonManager->switchMenu(ButtonManager::MenuType::DIFFICULTY_MENU);
	}
}

void DifficultyState::returnedToState()
{
}

void DifficultyState::leavingState()
{
}
