#pragma once

#include "allegro5/allegro.h"
#include <EventSystem.h>

namespace Input {
	enum MouseButton {
		LEFT = 1,
		RIGHT,
		CENTER
	};

	enum Key {
		F = ALLEGRO_KEY_F,
		S = ALLEGRO_KEY_S,
		ENTER = ALLEGRO_KEY_ENTER,
		ESCAPE = ALLEGRO_KEY_ESCAPE,
		SPACE = ALLEGRO_KEY_SPACE,
		C = ALLEGRO_KEY_C,
		R = ALLEGRO_KEY_R,
		B = ALLEGRO_KEY_B,
		I = ALLEGRO_KEY_I
	};
}

class InputSystem {
	public:
		void cleanup();
		bool init();
		InputSystem();
		~InputSystem();
		void update();
	private:
		EventSystem* mEventSystem;
		bool mInitted = false;
		ALLEGRO_EVENT_QUEUE* mQueue;
};