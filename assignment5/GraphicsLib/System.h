#pragma once

#include <allegro5/allegro.h>
#include "GraphicsSystem.h"
#include "InputSystem.h"
#include <iostream>
#include<Trackable.h>

class System: public Trackable {
	public:
		GraphicsSystem* getGraphicsSystem();
		int getMouseX();
		int getMouseY();
		bool init(unsigned int width, unsigned int height);
		bool isMouseButtonDown(Input::MouseButton button);
		bool isKeyDown(Input::Key key);
		System();
		~System();
		void update();
	private:
		GraphicsSystem* mGraphicsSystem;
		InputSystem mInputSystem;
};