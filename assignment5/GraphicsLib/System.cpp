#include "System.h"

GraphicsSystem* System::getGraphicsSystem() {
	return mGraphicsSystem;
}

int System::getMouseX() {
	ALLEGRO_MOUSE_STATE state;
	al_get_mouse_state(&state);

	return state.x;
}

int System::getMouseY() {
	ALLEGRO_MOUSE_STATE state;
	al_get_mouse_state(&state);

	return state.y;
}

bool System::init(unsigned int width, unsigned int height) {
	if(!al_init()) {
		cout << "error initting Allegro" << endl;
		return false;
	}
	if(!mGraphicsSystem->init(width, height)) {
		return false;
	}

	mInputSystem.init();

	return true;
}

bool System::isMouseButtonDown(Input::MouseButton button) {
	ALLEGRO_MOUSE_STATE state;
	al_get_mouse_state(&state);

	switch (button) {
		case Input::MouseButton::LEFT:
			return (state.buttons & 1); // todd_howard.jpeg
			break;
		case Input::MouseButton::RIGHT:
			return (state.buttons & 2);
			break;
		case Input::MouseButton::CENTER:
			return (state.buttons & 4);
			break;
	}

	return false;
}

bool System::isKeyDown(Input::Key key) {
	ALLEGRO_KEYBOARD_STATE state;
	al_get_keyboard_state(&state);
	
	if (al_key_down(&state, key)) {
		return true;
	}

	return false;
}

System::System() {
	mGraphicsSystem = new GraphicsSystem();
}

System::~System() {
	mGraphicsSystem->cleanup();
	delete mGraphicsSystem;
}

void System::update() {
	mInputSystem.update();
}