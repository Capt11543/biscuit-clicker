#include "Button.h"
#include "ButtonManager.h"



Button::Button(int x, int y, int width, int height, ButtonType id) : Unit(UnitType::BUTTON, x, y) {
	mpListener = new ButtonClickListener(x, y, width, height, id);
	mId = id;
	mWidth = width;
	mHeight = height;
	mX = x;
	mY = y;
}

Button::~Button() {
	delete mpListener;

}

ButtonType Button::getId()
{
	return mId;
}

int Button::getWidth()
{
	return mWidth;
}

int Button::getHeight()
{
	return mHeight;
}

int Button::getX()
{
	return mX;
}

int Button::getY()
{
	return mY;
}

void Button::setButtonState(bool state)
{
	mpListener->setState(state);
}
