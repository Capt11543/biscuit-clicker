#pragma once

#include <allegro5/allegro_color.h>
#include <Trackable.h>

class Color : public Trackable {
	public:
		Color(int red, int green, int blue, int alpha);
		~Color();
	private:
		friend class GraphicsBuffer;
		friend class GraphicsSystem;
		int mAlpha, mBlue, mGreen, mRed;
		ALLEGRO_COLOR getColor();
};