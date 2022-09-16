#pragma once
#include "GameState.h"
#include "System.h"
#include "Biscuit.h"
#include "AntSpawner.h"
#include "Ant.h"

class UnitManager;
class ButtonManager;
class SpriteManager;
class Text;

class GameplayState : public GameState {
	public:
		virtual void draw();
		GameplayState();
		~GameplayState();
		AntSpawner* getSpawner();
		virtual void init(int width, int height, int timePerframe);
		void initButton(int tempWidth, int tempHeight);
		void initUnits(int tempWidth, int tempHeight);
		void changeBiscuitState(bool state);
		void makeAntUnit(int x, int y);
		void makeAutoClicker(int x, int y);
		void setFont(const string fileName, const string path, const int titleFontSize, const int fontSize);
		void setColor();
		void checkIfShopButtonsOn();
		virtual void update(double deltaTime);
		virtual void returnedToState();
		virtual void leavingState();
	private:
		AntSpawner* mpAntSpawner;
		ButtonManager* mpButtonManager;
		Unit* mBiscuit;
		System* mpGameSystem;
		SpriteManager* mpSpriteManager;
		Text* mpText;
		UnitManager* mpUnitManager;

		int mWidth, mHeight;
		bool mEnableBiscuit = false;

		Vector2D mAutoClickerPos;
		int mClickerCount;
};