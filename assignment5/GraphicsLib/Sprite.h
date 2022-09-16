#pragma once

#include "GraphicsBuffer.h"
#include <Trackable.h>

class Sprite : public Trackable {
	public:
		GraphicsBuffer* getGraphicsBuffer();
		int getHeight();
		int getWidth();
		int getX();
		int getY();
		Sprite(GraphicsBuffer* buffer, int x, int y, int width, int height);
		~Sprite();
	private:
		GraphicsBuffer* mGraphicsBuffer;
		int mHeight, mWidth;
		int mX, mY;
};