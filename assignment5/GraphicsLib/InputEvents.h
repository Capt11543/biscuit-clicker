#pragma once

#include <Event.h>
#include "System.h"

enum InputEventType { // may have to move this and all input event classes to one file called "InputEvents.h"
	KEY_PRESSED_EVENT = NUM_BASE_EVENT_TYPES + 1,
	MOUSE_MOVE_EVENT,
	MOUSE_PRESSED_EVENT,
	NUM_INPUT_EVENT_TYPES
};

class KeyPressedEvent : public Event {
	public:
		Input::Key getKey() const;
		bool getPressed() const;
		KeyPressedEvent(Input::Key key, bool pressed);
	private:
		Input::Key mKey;
		bool mPressed;
};

class MouseMoveEvent : public Event {
	public:
		int getX() const;
		int getY() const;
		MouseMoveEvent(int x, int y);
	private:
		int mX, mY;
};

class MousePressedEvent : public Event {
	public:
		Input::MouseButton getButton() const;
		bool getPressed() const;
		int getX() const;
		int getY() const;
		MousePressedEvent(int x, int y, Input::MouseButton button, bool pressed);
	private:
		Input::MouseButton mButton;
		bool mPressed;
		int mX, mY;
};