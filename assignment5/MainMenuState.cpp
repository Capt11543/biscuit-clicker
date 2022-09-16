#include "MainMenuState.h"
#include "Game.h"

MainMenuState::MainMenuState()
{
	mpButtonManager = Game::getInstance()->getButtonManager();
	mpGameSystem = Game::getInstance()->getSystem();
	mpSpriteManager = Game::getInstance()->getSpriteManager();
	mpText = new Text;

	mWidth = -1;
	mHeight = -1;
}

MainMenuState::~MainMenuState()
{
	mpGameSystem = nullptr;
	mpSpriteManager = nullptr;
	mpButtonManager = nullptr;
	delete mpText;
}

void MainMenuState::init(int width, int height, int timePerframe)
{
	mWidth = width;
	mHeight = height;

	const string ASSET_PATH = "..\\assets\\";
	const string FONT_FILENAME = "COMIC.TTF";
	const int TITLE_FONT_SIZE = 50;
	const int FONT_SIZE = 22;
	const string BUTTON_FILENAME = "button.png";
	const string BUTTON_SMALL = "button_small.png";
	const string BUTTON_GRAY_FILENAME = "graybutton.png";
	const string MENU_BACKGROUND_FILENAME = "red.png";
	const string BISCUIT_FILENAME = "biscuit.png";

	setFont(FONT_FILENAME, ASSET_PATH, TITLE_FONT_SIZE, FONT_SIZE);
	setColor();

	Game::getInstance()->makeGraphicsBuffer(ASSET_PATH + MENU_BACKGROUND_FILENAME, "menuBuffer");
	Game::getInstance()->makeSprites("menuBuffer", 1800, 1800, 1, 1, "menuSprite");

	Game::getInstance()->makeGraphicsBuffer(ASSET_PATH + BUTTON_FILENAME, "buttonBuffer");
	Game::getInstance()->makeSprites("buttonBuffer", 223, 76, 1, 1, "buttonSprite");

	Game::getInstance()->makeGraphicsBuffer(ASSET_PATH + BUTTON_SMALL, "buttonSmallBuffer");
	Game::getInstance()->makeSprites("buttonSmallBuffer", 76, 76, 1, 1, "buttonSmallSprite");

	Game::getInstance()->makeGraphicsBuffer(ASSET_PATH + BUTTON_GRAY_FILENAME, "buttonGrayBuffer");
	Game::getInstance()->makeSprites("buttonGrayBuffer", 223, 76, 1, 1, "buttonGraySprite");

	Game::getInstance()->makeGraphicsBuffer(ASSET_PATH + BISCUIT_FILENAME, "biscuitBuffer");
	Game::getInstance()->makeSprites("biscuitBuffer", 304, 220, 1, 1, "biscuitSprite");

	int tempWidth = Game::getInstance()->getBufferManager()->getGraphicsBuffer("buttonBuffer")->getWidth();
	int tempHeight = Game::getInstance()->getBufferManager()->getGraphicsBuffer("buttonBuffer")->getHeight();

	initButton(tempWidth, tempHeight);

	mpButtonManager->switchMenu(ButtonManager::MenuType::MAIN_MENU);
}

void MainMenuState::initButton(int tempWidth, int tempHeight)
{
	Button* aButton = new Button((mWidth / 2) - (tempWidth / 2), ((mHeight / 2) - (tempHeight / 2)) - tempHeight, tempWidth, tempHeight+10, ButtonType::START);
	aButton->setSprite(Game::getInstance()->getSpriteManager()->getSprite("buttonSprite"));
	mpButtonManager->addButton(aButton, ButtonManager::MAIN_MENU);

	aButton = new Button((mWidth / 2) - (tempWidth / 2), ((mHeight / 2) - (tempHeight / 2)), tempWidth, tempHeight+10, ButtonType::LOAD);
	aButton->setSprite(Game::getInstance()->getSpriteManager()->getSprite("buttonSprite"));
	mpButtonManager->addButton(aButton, ButtonManager::MAIN_MENU);

	aButton = new Button((mWidth / 2) - (tempWidth / 2), ((mHeight / 2) - (tempHeight / 2)) + tempHeight, tempWidth, tempHeight+10, ButtonType::OPTIONS);
	aButton->setSprite(Game::getInstance()->getSpriteManager()->getSprite("buttonSprite"));
	mpButtonManager->addButton(aButton, ButtonManager::MAIN_MENU);

	aButton = new Button((mWidth / 2) - (tempWidth / 2), ((mHeight / 2) - (tempHeight / 2)) + (tempHeight * 2), tempWidth, tempHeight+10, ButtonType::QUIT);
	aButton->setSprite(Game::getInstance()->getSpriteManager()->getSprite("buttonSprite"));
	mpButtonManager->addButton(aButton, ButtonManager::MAIN_MENU);
}

void MainMenuState::setFont(const string fileName, const string path, const int titleFontSize, const int fontSize)
{
	mpText->setFont(path + fileName, titleFontSize);
	mpButtonManager->setFont(path + fileName, fontSize);
}

void MainMenuState::setColor()
{
	mpText->setColor(0, 0, 0, 255);
	mpButtonManager->setColor(0, 0, 0, 255);
}

void MainMenuState::update(double deltaTime)
{
	mpButtonManager->update(deltaTime);
}

void MainMenuState::draw()
{
	mpGameSystem->getGraphicsSystem()->draw(0, 0, *(mpSpriteManager->getSprite("menuSprite")));
	mpGameSystem->getGraphicsSystem()->draw((mWidth/2) - ((mpSpriteManager->getSprite("biscuitSprite")->getWidth()) / 2), (5), *(mpSpriteManager->getSprite("biscuitSprite")));

	mpText->writeText(mWidth / 2, 75, Game::getInstance()->getLanguage()->getTextAt(0));

	mpButtonManager->draw(mpGameSystem->getGraphicsSystem());
}

void MainMenuState::returnedToState()
{
	mpButtonManager->switchMenu(ButtonManager::MenuType::MAIN_MENU);
}

void MainMenuState::leavingState()
{
}
