#pragma once
#include "GameState.h"
#include "System.h"
#include "ButtonManager.h"
#include "SpriteManager.h"

class DifficultyState : public GameState {
public:
	virtual void draw();
	DifficultyState();
	~DifficultyState();
	virtual void init(int width, int height, int timePerframe);
	virtual void update(double deltaTime);
	virtual void returnedToState();
	virtual void leavingState();
private:
	ButtonManager* mpButtonManager;
	System* mpGameSystem;
	Text* mpText;
	SpriteManager* mpSpriteManager;

	int mWidth, mHeight;
	bool mEnableButtons;
};