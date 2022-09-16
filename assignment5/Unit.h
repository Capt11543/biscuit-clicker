#pragma once

#include "Sprite.h"
#include <Trackable.h>

enum UnitType {
	NONE = -1,
	BISCUIT,
	ANT,
	BUTTON,
	AUTO_CLICKER
};

class Unit: public Trackable {
	public:
		virtual void draw(GraphicsSystem* gSystem);
		// Animation* getAnimation();
		Sprite* getSprite();
		UnitType getType();
		int getX();
		int getY();
		// void setAnimation(Animation animation);
		void setPosition(int x, int y);
		void setSprite(Sprite* sprite);
		// void toggleAnimation();
		Unit(UnitType type, int x, int y);
		virtual ~Unit()
		{

		}
		virtual void update(double deltaTime);
	private:
		// Animation mAnimation;
		Sprite* mSprite;
		UnitType mType;
		int mX, mY;
};