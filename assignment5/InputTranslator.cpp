#include <EventListener.h>
#include "Game.h"
#include "GameEvents.h"
#include <InputEvents.h>
#include "InputTranslator.h"
#include <System.h>

void InputTranslator::cleanup() {

}

void InputTranslator::init() {
	mEventSystem = EventSystem::getInstance();

	mEventSystem->addListener((EventType)KEY_PRESSED_EVENT, this);
	mEventSystem->addListener((EventType)MOUSE_MOVE_EVENT, this);
	mEventSystem->addListener((EventType)MOUSE_PRESSED_EVENT, this);
}

InputTranslator::InputTranslator() {

}

InputTranslator::~InputTranslator() {

}

void InputTranslator::handleEvent(const Event& theEvent) {
	switch(theEvent.getType()) {
		case KEY_PRESSED_EVENT:
			handleKeyPressedEvent((const KeyPressedEvent&)theEvent);
			break;
		case MOUSE_MOVE_EVENT:
			handleMouseMoveEvent((const MouseMoveEvent&)theEvent);
			break;
		case MOUSE_PRESSED_EVENT:
			handleMousePressedEvent((const MousePressedEvent&)theEvent);
			break;
	}
}

void InputTranslator::handleKeyPressedEvent(const KeyPressedEvent& theEvent) {
	if(theEvent.getKey() == Input::F && theEvent.getPressed()) {
		cout << "Respects paid" << endl;
	} else if(theEvent.getKey() == Input::ESCAPE && theEvent.getPressed()) {
		mEventSystem->fireEvent(QuitGameEvent());
	} else if(theEvent.getKey() == Input::SPACE && theEvent.getPressed()) {
		// mEventSystem->fireEvent(ToggleFreezeAnimationEvent());
	} else if(theEvent.getKey() == Input::ENTER && theEvent.getPressed()) {
		// mEventSystem->fireEvent(DeanifyUnitEvent());
	}
}

void InputTranslator::handleMouseMoveEvent(const MouseMoveEvent& theEvent) {
	mMouseX = theEvent.getX();
	mMouseY = theEvent.getY();

	//cout << "(" << theEvent.getX() << ", " << theEvent.getY() << ")" << endl;
}

void InputTranslator::handleMousePressedEvent(const MousePressedEvent& theEvent) {
	if(theEvent.getButton() == Input::LEFT && theEvent.getPressed()) {
		mEventSystem->fireEvent(AddUnitEvent(theEvent.getX(), theEvent.getY()));
	} else if(theEvent.getButton() == Input::RIGHT && theEvent.getPressed()) {
		// mEventSystem->fireEvent(DeleteUnitEvent(theEvent.getX(), theEvent.getY()));
	} else if(theEvent.getButton() == Input::CENTER) {
		//cout << "Middle click" << endl;
	} else {
		//cout << "Mouse button " << theEvent.getButton() << endl;
	}
}

void InputTranslator::update() {
	
}