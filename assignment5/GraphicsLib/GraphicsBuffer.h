#pragma once

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "Color.h"
#include <string>
#include <Trackable.h>

using namespace std;

class GraphicsBuffer : public Trackable {
	public:
		int getHeight();
		int getWidth();
		GraphicsBuffer(string filename);
		GraphicsBuffer(int width, int height, Color color);
		~GraphicsBuffer();
	private:
		friend class GraphicsSystem;
		ALLEGRO_BITMAP* mBitmap;
		GraphicsBuffer(ALLEGRO_DISPLAY* display);
};