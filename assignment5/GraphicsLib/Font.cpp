#include "Font.h"

Font::Font(string fontFile, int fontSize) {
	this->mSize = fontSize;
	mFont = al_load_font(fontFile.c_str(), mSize, 0);
}

Font::~Font() {

}

ALLEGRO_FONT* Font::getFont() {
	return mFont;
}

int Font::getSize() {
	return mSize;
}