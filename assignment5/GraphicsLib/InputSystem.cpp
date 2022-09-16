#include "InputSystem.h"
#include "InputEvents.h"
#include "System.h"

void InputSystem::cleanup() {
	// al unregister event source
	al_unregister_event_source(mQueue, al_get_keyboard_event_source());
	al_unregister_event_source(mQueue, al_get_mouse_event_source());
	
	al_destroy_event_queue(mQueue);
	mInitted = false;

	al_uninstall_keyboard();
	al_uninstall_mouse();
}

bool InputSystem::init() {
	// Install keyboard and mouse modules
	if (!al_install_keyboard()) {
		cout << "error installing Allegro keyboard" << endl;
	}
	if (!al_install_mouse()) {
		cout << "error installing Allegro mouse" << endl;
	}

	mEventSystem = EventSystem::getInstance();

	// Create event queue
	mQueue = al_create_event_queue();
	if (mQueue == NULL) {
		return false;
	}

	// Listen for allegro keyboard and mouse events
	al_register_event_source(mQueue, al_get_keyboard_event_source());
	al_register_event_source(mQueue, al_get_mouse_event_source());

	mInitted = true;
	return true;
}

InputSystem::InputSystem() {

}

InputSystem::~InputSystem() {
	if (mInitted) {
		cleanup();
	}
}

void InputSystem::update() {
	// go through allegro event queue, fire our own events using new event system

	// if not innited, return
	if (!mInitted) {
		return;
	}

	ALLEGRO_EVENT nextEvent;
	while (al_get_next_event(mQueue, &nextEvent)) {
		switch (nextEvent.type) {
			case ALLEGRO_EVENT_KEY_DOWN:
				mEventSystem->fireEvent(KeyPressedEvent((Input::Key)nextEvent.keyboard.keycode, true));
				break;
			case ALLEGRO_EVENT_KEY_UP:
				mEventSystem->fireEvent(KeyPressedEvent((Input::Key)nextEvent.keyboard.keycode, false));
				break;
			case ALLEGRO_EVENT_MOUSE_AXES:
				mEventSystem->fireEvent(MouseMoveEvent(nextEvent.mouse.x, nextEvent.mouse.y));
				break;
			case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
				mEventSystem->fireEvent(MousePressedEvent(nextEvent.mouse.x, nextEvent.mouse.y, (Input::MouseButton)nextEvent.mouse.button, true));
				break;
			case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
				mEventSystem->fireEvent(MousePressedEvent(nextEvent.mouse.x, nextEvent.mouse.y, (Input::MouseButton)nextEvent.mouse.button, false));
				break;
		}
	}
}