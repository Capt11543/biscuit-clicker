#pragma once

#include "ClickListener.h"
#include "Shop.h"
#include "LevelingSystem.h"

class BiscuitClickListener : public ClickListener {
	public:
		BiscuitClickListener(int x, int y, int width, int height, bool state);
		~BiscuitClickListener();
		bool getState();
		void setState(bool state);
		void onLeftClick(); // moving this here feels wrong
	private:
		Shop* mShop;
		LevelingSystem* mLevels;
		bool mState;
};

