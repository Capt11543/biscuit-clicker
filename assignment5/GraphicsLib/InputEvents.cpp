#include "InputEvents.h"

Input::Key KeyPressedEvent::getKey() const {
	return mKey;
}

bool KeyPressedEvent::getPressed() const {
	return mPressed;
}

KeyPressedEvent::KeyPressedEvent(Input::Key key, bool pressed) : Event((EventType)KEY_PRESSED_EVENT) {
	mKey = key;
	mPressed = pressed;
}

int MouseMoveEvent::getX() const {
	return mX;
}

int MouseMoveEvent::getY() const {
	return mY;
}

MouseMoveEvent::MouseMoveEvent(int x, int y) : Event((EventType)MOUSE_MOVE_EVENT) {
	mX = x;
	mY = y;
}

Input::MouseButton MousePressedEvent::getButton() const {
	return mButton;
}

bool MousePressedEvent::getPressed() const {
	return mPressed;
}

int MousePressedEvent::getX() const {
	return mX;
}

int MousePressedEvent::getY() const {
	return mY;
}

MousePressedEvent::MousePressedEvent(int x, int y, Input::MouseButton button, bool pressed) : Event((EventType)MOUSE_PRESSED_EVENT) {
	mButton = button;
	mPressed = pressed;
	mX = x;
	mY = y;
}