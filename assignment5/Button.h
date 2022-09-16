#pragma once

#include "ButtonClickListener.h"
#include "Unit.h"
#include <string>

enum ButtonType;

class Button : public Unit {
public:
	Button(int x, int y, int width, int height, ButtonType id);
	~Button();

	ButtonType getId();
	int getWidth();
	int getHeight();
	int getX();
	int getY();

	void setButtonState(bool state);
private:
	ButtonClickListener* mpListener;
	ButtonType mId;
	int mWidth, mHeight;
	int mX, mY;
};