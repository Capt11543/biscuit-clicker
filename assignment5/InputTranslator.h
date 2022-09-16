#pragma once

#include <EventListener.h>
#include <InputEvents.h>
#include <InputSystem.h>

class InputTranslator : public EventListener { // should I make this a singleton?
	public:
		void cleanup();
		void init();
		void handleEvent(const Event& theEvent);
		InputTranslator();
		~InputTranslator();
		void update();
	private:
		void handleKeyPressedEvent(const KeyPressedEvent& theEvent);
		void handleMouseMoveEvent(const MouseMoveEvent& theEvent);
		void handleMousePressedEvent(const MousePressedEvent& theEvent);
		EventSystem* mEventSystem;
		int mMouseX = 0, mMouseY = 0;
};