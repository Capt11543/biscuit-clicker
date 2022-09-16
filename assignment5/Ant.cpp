#include "Ant.h"
#include "Biscuit.h"
#include "Game.h"
#include "GraphicsSystem.h"

Ant::Ant(int x, int y, Biscuit* biscuit) : Unit(UnitType::ANT, x, y) {
	mBiscuit = biscuit;
	mListener = new AntClickListener(x, y, 40, 26);
	mKeepWalking = false;
	mWalking = true;
}

Ant::~Ant() {
	delete mListener;
}

bool Ant::collidingWithBiscuit() {
	bool inHorizontalBounds = getX() >= mBiscuit->getX() && getX() <= mBiscuit->getX() + mBiscuit->getSprite()->getWidth();
	bool inVerticalBounds = getY() >= mBiscuit->getY() && getY() <= mBiscuit->getY() + mBiscuit->getSprite()->getHeight();

	if(inHorizontalBounds && inVerticalBounds) {
		return true;
	} else {
		return false;
	}
}

void Ant::startWalking() {
	mWalking = true;
	mKeepWalking = true;
}

void Ant::update(double deltaTime) {
	if(mWalking) {
		// Move the ant to the side
		setPosition(getX() + mMoveSpeed * (deltaTime / 1000), getY());
		mListener->setBounds(getX(), getY(), 40, 26);

		// Delete the ant if it gets too far offscreen
		if(getX() > Game::getInstance()->getWidth() + 200) {
			EventSystem::getInstance()->fireEvent(DeleteUnitEvent(getX(), getY(), ANT));
		}

		if(collidingWithBiscuit() && !mKeepWalking) {
			mWalking = false;
		}
	}
}

void Ant::updateMoveSpeed() {
	mMoveSpeed = mInitialMoveSpeed * Game::getInstance()->getLeveling()->getAntSpeed();
}