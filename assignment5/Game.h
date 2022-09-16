#pragma once

#include "AntSpawner.h"
#include "AnimationManager.h"
#include "ButtonManager.h"
#include "GameEventListener.h"
#include "GraphicsBufferManager.h"
#include <GraphicsLib.h>
#include "InputTranslator.h"
#include "LevelingSystem.h"
#include "Shop.h"
#include "SpriteManager.h"
#include "Text.h"
#include <Trackable.h>
#include "Unit.h"
#include "UnitManager.h"
#include <vector>
#include "SoundSystem.h"
#include "MainMenuState.h"
#include "GameplayState.h"
#include "OptionsState.h"
#include "GameState.h"
#include "TextReader.h"
#include "Language.h"
#include "DifficultyState.h"

class Game: public Trackable {
	public:
		static MainMenuState* msMenuState;
		static GameplayState* msGamePlayState;
		static OptionsState* msOptionsState;
		static DifficultyState* msDifficultyState;
		static void cleanup();
		void doLoop();
		void difficultyMenuOn();
		void gameOn(int level = 1);
		void pauseOn();
		void loadPreviousState();
		int getHeight();
		static Game* getInstance();
		LevelingSystem* getLeveling();
		Language* getLanguage();
		Shop* getShop();
		AntSpawner* getSpawner();
		SoundSystem* getSoundSystem();
		System* getSystem();
		UnitManager* getUnitManager();
		int getWidth();
		void init(unsigned int width, unsigned int height, double targetTimePerFrame = 16.7);
		void makeAntUnit(int x, int y);
		void makeAutoClicker(int x, int y);
		// void makeSmurfUnit(int x, int y);
		void quit();
		void writeText(int x, int y, Font font, Color color, string text, int alignment = 1);

		void saveGame();
		void loadGame();
	private:
		friend MainMenuState;
		friend GameplayState;
		friend OptionsState;
		friend DifficultyState;
		friend ButtonManager;
		void draw();
		Game();
		~Game();
		void getInput();
		void makeAnimation(string spriteName, int numSprites, float animationRate, string name);
		void makeGraphicsBuffer(string filename, string name);
		void makeSprites(string bufferName, int width, int height, int rows, int columns, string name);
		// void makeUnit(UnitType type, int x, int y, string animationName);
		GraphicsBufferManager* getBufferManager();
		ButtonManager* getButtonManager();
		SpriteManager* getSpriteManager();
		ButtonManager* mpButtonManager;
		EventSystem* mEventSystem;
		GameEventListener mGameEventListener;
		bool mGameOn = false;
		GraphicsBufferManager* mGraphicsBufferManager;
		int mHeight, mWidth;
		static Game* mInstance;
		AnimationManager* mAnimationManager;
		InputTranslator mInputTranslator;
		LevelingSystem* mpLevelingSystem;
		bool mIsRunning = false;
		Shop* mShop;
		SpriteManager* mSpriteManager;
		System* mSystem;
		double mTargetTimePerFrame = 0;
		UnitManager* mUnitManager;
		void update(double deltaTime);
		SoundSystem* mSoundSystem;
		GameState* mpGameState;
		GameState* mpPreviousGameState;
		TextReader* mpSaveGameVar;
		Language* mpLanguage;
};