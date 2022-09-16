#pragma once

#include "ClickListener.h"
#include "Shop.h"
#include "LevelingSystem.h"

enum ButtonType;

class ButtonClickListener : public ClickListener {
public:
	ButtonClickListener(int x, int y, int width, int height, ButtonType id);
	~ButtonClickListener();

	void setState(bool state);
private:
	void onLeftClick();
	bool isActive = true;

	ButtonType mId;

	Shop* mShop;
	LevelingSystem* mpLevels;
};

