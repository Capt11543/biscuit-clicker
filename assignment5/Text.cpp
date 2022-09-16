#include "Text.h"
#include "Game.h"

Text::Text()
{
	mpFont = nullptr;
	mpColor = nullptr;
}

Text::~Text()
{
	delete mpFont;
	delete mpColor;
}

void Text::setFont(string fontFile, int fontSize)
{
	mpFont = new Font(fontFile, fontSize);
}

void Text::setColor(int red, int green, int blue, int alpha)
{
	mpColor = new Color(red, green, blue, alpha);
}

void Text::writeText(int x, int y, string text, int alignment)
{
	assert(mpFont && mpColor);
	Game::getInstance()->writeText(x, y, *mpFont, *mpColor, text, alignment);
}
