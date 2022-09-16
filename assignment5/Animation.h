#pragma once

#include "Sprite.h"
#include <Trackable.h>
#include <vector>

class Animation: public Trackable {
	public:
		void addSprite(Sprite* sprite);
		Animation();
		Animation(float animationRate);
		~Animation();
		void draw(GraphicsBuffer* buffer, int x, int y);
		Sprite* getCurrentSprite();
		void slowDown(int amount);
		void speedUp(int amount);
		void toggleAnimation();
		void update(double deltaTime);
	private:
		vector<Sprite*> mSpriteList;
		unsigned int mCurrentSprite;
		double mAnimationRate;
		double mAnimationTimer;
		bool mMoving = true;
};