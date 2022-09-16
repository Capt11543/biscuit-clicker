#include "Color.h"

Color::Color(int red, int green, int blue, int alpha) {
	mRed = red;
	mGreen = green;
	mBlue = blue;
	mAlpha = alpha;
}

Color::~Color() {

}

ALLEGRO_COLOR Color::getColor() {
	return al_map_rgba(mRed, mGreen, mBlue, mAlpha);
}