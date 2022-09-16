#pragma once
#include "Font.h"
#include "Color.h"

class Text : public Trackable {
public:
	Text();
	~Text();

	void setFont(string fontFile, int fontSize);
	void setColor(int red, int green, int blue, int alpha);

	void writeText(int x, int y, string text, int alignment = 1);
private:
	Font* mpFont;
	Color* mpColor;
};