#include "Game.h"
#include "Unit.h"

void Unit::draw(GraphicsSystem* gSystem) {
	gSystem->draw(mX, mY, *mSprite);
}

Sprite* Unit::getSprite() {
	return mSprite;
}

UnitType Unit::getType() {
	return mType;
}

int Unit::getX() {
	return mX;
}

int Unit::getY() {
	return mY;
}

void Unit::setPosition(int x, int y) {
	mX = x;
	mY = y;
}

void Unit::setSprite(Sprite* sprite) {
	mSprite = sprite;
}

Unit::Unit(UnitType type, int x, int y) {
	mType = type;
	mX = x;
	mY = y;
}

void Unit::update(double deltaTime) {

}