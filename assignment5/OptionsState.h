#pragma once
#include "GameState.h"
#include "System.h"
#include "ButtonManager.h"
#include "SpriteManager.h"
#include "Text.h"

class OptionsState : public GameState
{
public:
	OptionsState();
	~OptionsState();
	virtual void init(int width, int height, int timePerframe);
	void initButton(int tempWidth, int tempHeight);
	virtual void update(double deltaTime);
	virtual void draw();
	void setFont(const string fileName, const string path, const int fontSize);
	void setColor();
	void saveSuccessfulTextOn();
	virtual void returnedToState();
	virtual void leavingState();
private:
	ButtonManager* mpButtonManager;
	System* mpGameSystem;
	SpriteManager* mpSpriteManager;
	Text* mpText;

	int mWidth, mHeight, mSavedCount;
	bool mIsInited;
	bool mSavedGame;
	bool mEnableButtons;
};