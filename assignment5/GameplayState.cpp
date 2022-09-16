#include "GameplayState.h"
#include "Game.h"
#include "AutoClicker.h"

void GameplayState::draw() {
	mpGameSystem->getGraphicsSystem()->draw(0, 0, *(mpSpriteManager->getSprite("backgroundSprite")));

	mpGameSystem->getGraphicsSystem()->draw(0, 0, *(mpSpriteManager->getSprite("napkinSprite")));

	mpText->writeText(20, 10, Game::getInstance()->getLanguage()->getTextAt(9) + to_string(Game::getInstance()->getLeveling()->getTotalClickCount()), 0);
	mpText->writeText(20, 60, Game::getInstance()->getLanguage()->getTextAt(10) + to_string(Game::getInstance()->getShop()->getMoney()), 0);

	mpButtonManager->draw(mpGameSystem->getGraphicsSystem());
	mpUnitManager->draw(mpGameSystem->getGraphicsSystem());
	
}

GameplayState::GameplayState()
{
	mpAntSpawner = new AntSpawner();
	mpUnitManager = Game::getInstance()->getUnitManager();
	mpGameSystem = Game::getInstance()->getSystem();
	mpSpriteManager = Game::getInstance()->getSpriteManager();
	mpButtonManager = Game::getInstance()->getButtonManager();
	mpText = new Text;

	mWidth = -1;
	mHeight = -1;
	mBiscuit = nullptr;
}

GameplayState::~GameplayState()
{
	mpGameSystem = nullptr;
	delete mpAntSpawner;
	mpSpriteManager = nullptr;
	mpUnitManager = nullptr;
	mpButtonManager = nullptr;
	delete mpText;
}

AntSpawner* GameplayState::getSpawner() {
	return mpAntSpawner;
}

void GameplayState::init(int width, int height, int timePerframe) {
	mWidth = width;
	mHeight = height;

	const string ASSET_PATH = "..\\assets\\";
	const string FONT_FILENAME = "COMIC.TTF";
	const int SCORE_DISPLAY_FONT_SIZE = 50;
	const int FONT_SIZE = 24;
	const string BACKGROUND_FILENAME = "index.png";
	const string NAPKIN_FILENAME = "napkin.png";
	const string ANT_FILENAME = "ant.png";
	const string CLICKER_FILENAME = "clicker.png";

	mpText->setFont(ASSET_PATH + FONT_FILENAME, SCORE_DISPLAY_FONT_SIZE);
	mpText->setColor(0, 0, 0, 255);

	Game::getInstance()->makeGraphicsBuffer(ASSET_PATH + BACKGROUND_FILENAME, "backgroundBuffer");
	Game::getInstance()->makeGraphicsBuffer(ASSET_PATH + ANT_FILENAME, "antBuffer");
	Game::getInstance()->makeGraphicsBuffer(ASSET_PATH + CLICKER_FILENAME, "clickerBuffer");
	Game::getInstance()->makeGraphicsBuffer(ASSET_PATH + NAPKIN_FILENAME, "napkinBuffer");

	Game::getInstance()->makeSprites("antBuffer", 40, 26, 1, 1, "antSprite");
	Game::getInstance()->makeSprites("backgroundBuffer", 2400, 2400, 1, 1, "backgroundSprite");
	Game::getInstance()->makeSprites("napkinBuffer", 208, 183, 1, 1, "napkinSprite");
	Game::getInstance()->makeSprites("clickerBuffer", 598, 659, 1, 1, "clickerSprite");

	int tempWidth = Game::getInstance()->getBufferManager()->getGraphicsBuffer("biscuitBuffer")->getWidth();
	int tempHeight = Game::getInstance()->getBufferManager()->getGraphicsBuffer("biscuitBuffer")->getHeight();
	initUnits(tempWidth, tempHeight);
	
	mEnableBiscuit = true;

	mpButtonManager->switchMenu(ButtonManager::MenuType::GAME_MENU);

	tempWidth = Game::getInstance()->getBufferManager()->getGraphicsBuffer("buttonBuffer")->getWidth();
	tempHeight = Game::getInstance()->getBufferManager()->getGraphicsBuffer("buttonBuffer")->getHeight();
	initButton(tempWidth, tempHeight);

	mAutoClickerPos = Game::getInstance()->getShop()->getAutoClickerPos();
	mClickerCount = Game::getInstance()->getShop()->getClickers();
}

void GameplayState::initButton(int tempWidth, int tempHeight) {
	Button* aButton = new Button(mWidth-Game::getInstance()->getBufferManager()->getGraphicsBuffer("buttonSmallBuffer")->getWidth(), 0, Game::getInstance()->getBufferManager()->getGraphicsBuffer("buttonSmallBuffer")->getWidth(), Game::getInstance()->getBufferManager()->getGraphicsBuffer("buttonSmallBuffer")->getHeight() + 10, ButtonType::PAUSE);
	aButton->setSprite(Game::getInstance()->getSpriteManager()->getSprite("buttonSmallSprite"));
	mpButtonManager->addButton(aButton, ButtonManager::GAME_MENU);

	aButton = new Button(mWidth - (Game::getInstance()->getBufferManager()->getGraphicsBuffer("buttonSmallBuffer")->getWidth() * 2), 0, Game::getInstance()->getBufferManager()->getGraphicsBuffer("buttonSmallBuffer")->getWidth(), Game::getInstance()->getBufferManager()->getGraphicsBuffer("buttonSmallBuffer")->getHeight() +10, ButtonType::QUIT);
	aButton->setSprite(Game::getInstance()->getSpriteManager()->getSprite("buttonSmallSprite"));
	mpButtonManager->addButton(aButton, ButtonManager::GAME_MENU);

	aButton = new Button(0, Game::getInstance()->getHeight() - 75, Game::getInstance()->getBufferManager()->getGraphicsBuffer("buttonBuffer")->getWidth(), Game::getInstance()->getBufferManager()->getGraphicsBuffer("buttonBuffer")->getHeight() + 10, ButtonType::SHOP_INGREDIENT);
	aButton->setSprite(Game::getInstance()->getSpriteManager()->getSprite("buttonSprite"));
	mpButtonManager->addButton(aButton, ButtonManager::GAME_MENU);

	aButton = new Button(0, (Game::getInstance()->getHeight() - 75) - Game::getInstance()->getBufferManager()->getGraphicsBuffer("buttonBuffer")->getHeight(), Game::getInstance()->getBufferManager()->getGraphicsBuffer("buttonBuffer")->getWidth(), Game::getInstance()->getBufferManager()->getGraphicsBuffer("buttonBuffer")->getHeight() + 10, ButtonType::SHOP_CLICKER);
	aButton->setSprite(Game::getInstance()->getSpriteManager()->getSprite("buttonSprite"));
	mpButtonManager->addButton(aButton, ButtonManager::GAME_MENU);

	aButton = new Button(Game::getInstance()->getBufferManager()->getGraphicsBuffer("buttonBuffer")->getWidth() * 2.5, Game::getInstance()->getHeight() - 75, Game::getInstance()->getBufferManager()->getGraphicsBuffer("buttonBuffer")->getWidth(), Game::getInstance()->getBufferManager()->getGraphicsBuffer("buttonBuffer")->getHeight() + 10, ButtonType::SHOP_NUM_CLICKERS);
	aButton->setSprite(Game::getInstance()->getSpriteManager()->getSprite("buttonSprite"));
	mpButtonManager->addButton(aButton, ButtonManager::GAME_MENU);
	
	aButton = new Button(Game::getInstance()->getBufferManager()->getGraphicsBuffer("buttonBuffer")->getWidth() * 2.5, (Game::getInstance()->getHeight() - 75) - Game::getInstance()->getBufferManager()->getGraphicsBuffer("buttonBuffer")->getHeight(), Game::getInstance()->getBufferManager()->getGraphicsBuffer("buttonBuffer")->getWidth(), Game::getInstance()->getBufferManager()->getGraphicsBuffer("buttonBuffer")->getHeight() + 10, ButtonType::SHOP_REPELLANT);
	aButton->setSprite(Game::getInstance()->getSpriteManager()->getSprite("buttonSprite"));
	mpButtonManager->addButton(aButton, ButtonManager::GAME_MENU);
}

void GameplayState::initUnits(int tempWidth, int tempHeight) {
	mBiscuit = new Biscuit(((mWidth / 2) - tempWidth / 2), (mHeight / 2) - (tempHeight / 2), false);
	mBiscuit->setSprite(mpSpriteManager->getSprite("biscuitSprite"));
	mpUnitManager->addUnit(mBiscuit);
}

void GameplayState::changeBiscuitState(bool state)
{
	static_cast<Biscuit*>(mBiscuit)->setState(state);
}

void GameplayState::makeAntUnit(int x, int y) {
	Unit* anAnt = new Ant(x, y, (Biscuit*)mBiscuit);
	anAnt->setSprite(mpSpriteManager->getSprite("antSprite"));
	mpUnitManager->addUnit(anAnt);
}

void GameplayState::makeAutoClicker(int x, int y) {
	Unit* anAutoClicker = new AutoClicker(x, y, (Biscuit*)mBiscuit);
	anAutoClicker->setSprite(mpSpriteManager->getSprite("clickerSprite"));
	mpUnitManager->addUnit(anAutoClicker);
}

void GameplayState::setFont(const string fileName, const string path, const int titleFontSize, const int fontSize) {

}

void GameplayState::setColor() {

}

void GameplayState::checkIfShopButtonsOn()
{
	mpButtonManager->checkIfShopButtonsEnabled();
}

void GameplayState::update(double deltaTime) {
	mpAntSpawner->update(deltaTime);
	
	mpUnitManager->update(deltaTime);
	mpButtonManager->update(deltaTime);

	mpUnitManager->removeDeadUnits();
	if (mEnableBiscuit)
	{
		changeBiscuitState(true);
		mEnableBiscuit = false;
	}
	if (mClickerCount > 0)
	{
		makeAutoClicker(mAutoClickerPos.getX(), mAutoClickerPos.getY());
		mClickerCount--;
	}
	checkIfShopButtonsOn();
}

void GameplayState::returnedToState()
{
	mpButtonManager->switchMenu(ButtonManager::MenuType::GAME_MENU);
	mEnableBiscuit = true;
}

void GameplayState::leavingState()
{
	changeBiscuitState(false);
}
