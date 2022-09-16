#include "ClickListener.h"
#include <EventSystem.h>
#include <InputEvents.h>

ClickListener::ClickListener(int x, int y, int width, int height) {
	mBoundsX = x;
	mBoundsY = y;
	mBoundsWidth = width;
	mBoundsHeight = height;

	EventSystem::getInstance()->addListener((EventType)MOUSE_PRESSED_EVENT, this);
}

int ClickListener::getBoundsHeight() {
	return mBoundsHeight;
}

int ClickListener::getBoundsWidth() {
	return mBoundsWidth;
}

int ClickListener::getBoundsX() {
	return mBoundsX;
}

int ClickListener::getBoundsY() {
	return mBoundsY;
}

void ClickListener::handleEvent(const Event& theEvent) {
	const MousePressedEvent translatedEvent = (const MousePressedEvent&)theEvent;

	bool inHorizontalBounds = translatedEvent.getX() >= mBoundsX && translatedEvent.getX() <= mBoundsX + mBoundsWidth;
	bool inVerticalBounds = translatedEvent.getY() >= mBoundsY && translatedEvent.getY() <= mBoundsY + mBoundsHeight;

	if(inHorizontalBounds && inVerticalBounds) {
		if(translatedEvent.getButton() == Input::MouseButton::LEFT && translatedEvent.getPressed()) {
			onLeftClick();
		} else if(translatedEvent.getButton() == Input::MouseButton::RIGHT && translatedEvent.getPressed()) {
			onRightClick();
		}
	}
}

void ClickListener::onLeftClick() {

}

void ClickListener::onRightClick() {

}

void ClickListener::setBounds(int x, int y, int width, int height) {
	mBoundsX = x;
	mBoundsY = y;
	mBoundsWidth = width;
	mBoundsHeight = height;
}