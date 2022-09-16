#include "Ant.h"
#include "AutoClicker.h"
#include "Biscuit.h"
#include "Button.h"
#include "Game.h"
#include "GameEvents.h"
#include <GraphicsLib.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Timer.h>
#include "MainMenuState.h"

Game* Game::mInstance = new Game; // this needs to be initialized first

MainMenuState* Game::msMenuState = new MainMenuState;
GameplayState* Game::msGamePlayState = new GameplayState;
OptionsState* Game::msOptionsState = new OptionsState;
DifficultyState* Game::msDifficultyState = new DifficultyState;

void Game::cleanup() {
	delete mInstance;
}

void Game::doLoop() {
	Timer timer;
	double deltaTime = 0.0f;

	while (mIsRunning) {
		deltaTime = timer.getElapsedTime();
		getInput();
		
		timer.start();
		
		update(deltaTime);
		draw();

		timer.sleepUntilElapsed(mTargetTimePerFrame);
	}
}

void Game::difficultyMenuOn()
{
	mpGameState->leavingState();
	mpPreviousGameState = mpGameState;
	Game::msDifficultyState->init(mWidth, mHeight, mTargetTimePerFrame);
	mpGameState = Game::msDifficultyState;

}

void Game::draw() {
	mpGameState->draw();

	mSystem->getGraphicsSystem()->flip();
}

Game::Game() {
	mSystem = new System;
	mTargetTimePerFrame = mTargetTimePerFrame;
	mIsRunning = true;

	mpLanguage = new Language; //This needs to be initialized before ButtonManager

	mpButtonManager = new ButtonManager;
	mGraphicsBufferManager = new GraphicsBufferManager;
	mpLevelingSystem = new LevelingSystem;
	mShop = new Shop;
	mSpriteManager = new SpriteManager;
	mUnitManager = new UnitManager;
	mSoundSystem = new SoundSystem;

	mpSaveGameVar = new TextReader;

	mWidth = 0;
	mHeight = 0;
	mpPreviousGameState = nullptr;
	mpGameState = nullptr;
	mEventSystem = nullptr;
}

Game::~Game() {
	delete Game::msMenuState;
	delete Game::msGamePlayState;
	delete Game::msOptionsState;
	delete Game::msDifficultyState;

	mpGameState = nullptr;

	delete mAnimationManager;
	delete mpButtonManager;
	delete mGraphicsBufferManager;
	delete mpLevelingSystem;
	delete mShop;
	delete mSpriteManager;
	delete mSystem;
	delete mUnitManager;
	delete mSoundSystem;
	delete mpSaveGameVar;
	delete mpLanguage;
}

void Game::gameOn(int level) {
	mGameOn = true;
	mpLevelingSystem->setLevel(level);
	mpGameState->leavingState();
	Game::msGamePlayState->init(mWidth, mHeight, mTargetTimePerFrame);
	mpPreviousGameState = mpGameState;
	mpGameState = Game::msGamePlayState;
}

// Need to disable pause menu buttons when they are created so the save button doesn't activate during the current click
void Game::pauseOn()
{
	mpGameState->leavingState();
	mpPreviousGameState = mpGameState;
	mpGameState = Game::msOptionsState;
	Game::msOptionsState->init(mWidth, mHeight, mTargetTimePerFrame);
}

void Game::loadPreviousState()
{
	GameState* tempPointer = mpGameState;
	mpGameState->leavingState();
	mpGameState = mpPreviousGameState;
	mpGameState->returnedToState();
	mpPreviousGameState = tempPointer;
}

GraphicsBufferManager* Game::getBufferManager() {
	return mGraphicsBufferManager;
}

ButtonManager* Game::getButtonManager() {
	return mpButtonManager;
}

int Game::getHeight() {
	return mHeight;
}

void Game::getInput() {
	// Use System input functions!
	if(mSystem->isKeyDown(Input::Key::ESCAPE)) {
		mIsRunning = false;
	}

	if (mSystem->isKeyDown(Input::Key::ENTER)) {
		saveGame();
	}
}

void Game::makeAnimation(string spriteName, int numSprites, float animationRate, string name)
{
}

Game* Game::getInstance() {
	return mInstance;
}

LevelingSystem* Game::getLeveling()
{
	return mpLevelingSystem;
}

Language* Game::getLanguage()
{
	return mpLanguage;
}

Shop* Game::getShop() {
	return mShop;
}

System* Game::getSystem() {
	return mSystem;
}

UnitManager* Game::getUnitManager() {
	return mUnitManager;
}

SoundSystem* Game::getSoundSystem() {
	return mSoundSystem;
}

AntSpawner* Game::getSpawner() {
	assert(mGameOn);
	return static_cast<GameplayState*>(mpGameState)->getSpawner();
}

SpriteManager* Game::getSpriteManager() {
	return mSpriteManager;
}

int Game::getWidth() {
	return mWidth;
}

void Game::init(unsigned int width, unsigned int height, double targetTimePerFrame) {
	mWidth = width;
	mHeight = height;
	mSystem->init(this->mWidth, this->mHeight);
	
	mTargetTimePerFrame = targetTimePerFrame;

	mEventSystem = EventSystem::getInstance();
	mEventSystem->init();

	mInputTranslator.init();

	Game::msMenuState->init(mWidth, mHeight, targetTimePerFrame);
	
	mpGameState = Game::msMenuState;

	mEventSystem->addListener((EventType)DELETE_UNIT_EVENT, &mGameEventListener);
	mEventSystem->addListener((EventType)QUIT_GAME_EVENT, &mGameEventListener);
	mEventSystem->addListener((EventType)START_GAME_EVENT, &mGameEventListener);
	mEventSystem->addListener((EventType)OPTIONS_MENU_EVENT, &mGameEventListener);
	mEventSystem->addListener((EventType)RETURN_TO_PREVIOUS_STATE_EVENT, &mGameEventListener);
	mEventSystem->addListener((EventType)RAISE_VOLUME_EVENT, &mGameEventListener);
	mEventSystem->addListener((EventType)LOWER_VOLUME_EVENT, &mGameEventListener);
	mEventSystem->addListener((EventType)CHANGE_LANGUAGE_EVENT, &mGameEventListener);
	mEventSystem->addListener((EventType)LOAD_GAME_EVENT, &mGameEventListener);
	mEventSystem->addListener((EventType)SAVE_GAME_EVENT, &mGameEventListener);
	mEventSystem->addListener((EventType)SHOP_EVENT, &mGameEventListener);
	mEventSystem->addListener((EventType)START_GAME_AT_DIFFICULTY, &mGameEventListener);

	const string ASSET_PATH = "..\\assets\\";
	const string SMURF_SPRITES_FILENAME = "smurf_sprites.png";
	const string DEAN_SPRITES_FILENAME = "dean_sprites.png";
	const string LEVELING_FILENAME = "game.txt";

	mpLevelingSystem->init(ASSET_PATH + LEVELING_FILENAME);

	makeGraphicsBuffer(ASSET_PATH + DEAN_SPRITES_FILENAME, "deanBuffer");
	makeGraphicsBuffer(ASSET_PATH + SMURF_SPRITES_FILENAME, "smurfBuffer");

	makeSprites("deanBuffer", 60, 60, 4, 4, "deanSprites");
	makeSprites("smurfBuffer", 60, 60, 4, 4, "smurfSprites");

	makeAnimation("deanSprites", 16, mTargetTimePerFrame / 2, "deanAnimation");
	makeAnimation("smurfSprites", 16, mTargetTimePerFrame / 2, "smurfAnimation");
}

void Game::loadGame() {
	vector<int> content;
	content = mpSaveGameVar->loadGameSave("..\\assets\\", "savedGame.txt");
	mpLevelingSystem->addSetAmountOfClicks(content[0]);
	mShop->addMoney(content[1]);
	mpLevelingSystem->setLevel(content[2]);
	mShop->setIngredientLevel(content[3]);
	mShop->setClickers(content[4]);
	mShop->setClickerLevel(content[5]);
	mShop->setRepellantLevel(content[6]);
	EventSystem::getInstance()->fireEvent(StartGameAtDifficultyEvent(content[2]));
}

void Game::makeAntUnit(int x, int y) {
	assert(mGameOn);
	static_cast<GameplayState*>(mpGameState)->makeAntUnit(x, y);
}

void Game::makeAutoClicker(int x, int y) {
	assert(mGameOn);
	static_cast<GameplayState*>(mpGameState)->makeAutoClicker(x, y);
}

void Game::makeGraphicsBuffer(string filename, string name) { // Should these have been structs all along?  Who knows?  Too late now!
	GraphicsBuffer* newBuffer = new GraphicsBuffer(filename);
	mGraphicsBufferManager->addGraphicsBuffer(newBuffer, name);
}

void Game::makeSprites(string bufferName, int width, int height, int rows, int columns, string name) { // There's a better way to do this and I might do it later
	bool firstSprite = true;

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			Sprite* newSprite = new Sprite(mGraphicsBufferManager->getGraphicsBuffer(bufferName), width * j, height * i, width, height);
			
			if(firstSprite) {
				mSpriteManager->addSprite(newSprite, name);
				firstSprite = false;
			} else {
				mSpriteManager->addSprite(newSprite);
			}
		}
	}
}

void Game::quit() {
	mIsRunning = false;
}

void Game::writeText(int x, int y, Font font, Color color, string text, int alignment)
{
	mSystem->getGraphicsSystem()->writeText(x, y, font, color, text, alignment);
}

void Game::saveGame()
{
	vector<int> content;
	content.push_back(mpLevelingSystem->getTotalClickCount());
	content.push_back(mShop->getMoney());
	content.push_back(mpLevelingSystem->getLevel());
	content.push_back(mShop->getIngredientLevel());
	content.push_back(mShop->getClickers());
	content.push_back(mShop->getClickerLevel());
	content.push_back(mShop->getRepellantLevel());
	mpSaveGameVar->writeToFile("..\\assets\\", "savedGame.txt", content);
	static_cast<OptionsState*>(mpGameState)->saveSuccessfulTextOn();
}

void Game::update(double deltaTime) {
	mSystem->update();

	mInputTranslator.update();
	mpGameState->update(deltaTime);
}