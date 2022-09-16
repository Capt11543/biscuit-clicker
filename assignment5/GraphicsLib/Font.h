#pragma once

#include <allegro5/allegro_ttf.h>
#include <string>
#include <Trackable.h>

using namespace std;

class Font : public Trackable {
	public:
		Font(string fontFile, int fontSize);
		~Font();
		int getSize();
	private:
		friend class GraphicsSystem;
		ALLEGRO_FONT* mFont;
		ALLEGRO_FONT* getFont();
		int mSize;
};