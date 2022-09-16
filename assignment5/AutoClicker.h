#pragma once

#include "Biscuit.h"
#include "Unit.h"

class AutoClicker : public Unit {
	public:
		AutoClicker(int x, int y, Biscuit* biscuit);
		~AutoClicker();
		void draw(GraphicsSystem* gSystem);
		void update(double deltaTime);
		void updateClickRate();
	private:
		Biscuit* mBiscuit;
		double mClickRate;
		double mClickTimer;
		int mInitialPos;
		int mMoveDist;
		Shop* mShop;
};