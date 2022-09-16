#include "Animation.h"
#include <GraphicsSystem.h>

void Animation::addSprite(Sprite* sprite) {
	mSpriteList.push_back(sprite);
}

Animation::Animation() {
	this->mAnimationRate = 16.7;
}

Animation::Animation(float animationRate) {
	mAnimationRate = animationRate;
	mAnimationTimer = 0.0f;
}

Animation::~Animation() {
	
}

void Animation::draw(GraphicsBuffer* buffer, int x, int y) {
	GraphicsSystem::draw(buffer, x, y, *mSpriteList[mCurrentSprite]);
}

Sprite* Animation::getCurrentSprite() {
	return mSpriteList[mCurrentSprite];
}

void Animation::slowDown(int amount) {
	mAnimationRate += amount;
}

void Animation::speedUp(int amount) {
	mAnimationRate -= amount;

	if(mAnimationRate < 1) {
		mAnimationRate = 1;
	}
}

void Animation::toggleAnimation() {
	mMoving = !mMoving;
}

void Animation::update(double deltaTime) {
	if (mMoving) {
		mAnimationTimer += deltaTime;

		if (mAnimationTimer >= mAnimationRate) {
			mCurrentSprite++; // I know this doesn't do what it's supposed to do, but I don't know how to make it do what it's supposed to do
			if (mCurrentSprite >= mSpriteList.size()) {
				mCurrentSprite = 0;
			}

			mAnimationTimer = 0;
		}
	}
}