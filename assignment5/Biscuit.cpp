#include "Biscuit.h"
#include "Game.h"

Biscuit::Biscuit(int x, int y, bool state) : Unit(UnitType::BISCUIT, x, y) { // w = 304 h = 220
	mListener = new BiscuitClickListener(x, y, 304, 220, state);
}

Biscuit::~Biscuit() {
	delete mListener;
}

bool Biscuit::contaminated() {
	vector<Unit*> ants = Game::getInstance()->getUnitManager()->getUnitsOfType(ANT);

	for(unsigned int i = 0; i < ants.size(); i++) {
		bool inHorizontalBounds = ants[i]->getX() >= getX() && ants[i]->getX() <= getX() + getSprite()->getWidth();
		bool inVerticalBounds = ants[i]->getY() >= getY() && ants[i]->getY() <= getY() + getSprite()->getHeight();

		if(inHorizontalBounds && inVerticalBounds) {
			return true;
		}
	}

	return false;
}

bool Biscuit::getState() {
	return mListener->getState();
}

void Biscuit::setState(bool state) {
	mListener->setState(state);
}

BiscuitClickListener* Biscuit::getListener() {
	return mListener;
}

void Biscuit::update(double deltaTime) {
	setState(!contaminated());
}