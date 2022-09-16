#pragma once

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Color.h"
#include "Font.h"
#include "GraphicsBuffer.h"
#include "Sprite.h"
#include <string>
#include <Trackable.h>

using namespace std;

class GraphicsSystem : public Trackable {
	public:
		void cleanup();
		void draw(int x, int y, Sprite sprite);
		void draw(int x, int y, Sprite sprite, float scale);
		static void draw(GraphicsBuffer* buffer, int x, int y, Sprite sprite);
		static void draw(GraphicsBuffer* buffer, int x, int y, Sprite sprite, float scale);
		void drawRect(int x1, int y1, int x2, int y2, Color color);
		static void drawRect(GraphicsBuffer* buffer, int x1, int y1, int x2, int y2, Color color);
		void flip();
		GraphicsBuffer* getBackBuffer();
		int getHeight();
		int getWidth();
		GraphicsSystem();
		~GraphicsSystem();
		bool init(int width, int height);
		void saveBuffer(string filename);
		static void saveBuffer(GraphicsBuffer* buffer, string filename);
		void writeText(int x, int y, Font font, Color color, string text, int alignment = 1);
		static void writeText(GraphicsBuffer* buffer, int x, int y, Font font, Color color, string text);
	private:
		GraphicsBuffer* mBackBuffer;
		ALLEGRO_DISPLAY* mDisplay;
		int mHeight, mWidth;
};