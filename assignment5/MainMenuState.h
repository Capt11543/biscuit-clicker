#pragma once
#include "GameState.h"
#include "System.h"

class ButtonManager;
class SpriteManager;
class Text;
enum ButtonType;

class MainMenuState : public GameState
{
public:
	MainMenuState();
	~MainMenuState();
	virtual void init(int width, int height, int timePerframe);
	void initButton(int tempWidth, int tempHeight);
	void setFont(const string fileName, const string path, const int titleFontSize, const int fontSize);
	void setColor();
	virtual void update(double deltaTime);
	virtual void draw();
	virtual void returnedToState();
	virtual void leavingState();
private:
	ButtonManager* mpButtonManager;
	System* mpGameSystem;
	SpriteManager* mpSpriteManager;
	Text* mpText;

	int mWidth, mHeight;
};