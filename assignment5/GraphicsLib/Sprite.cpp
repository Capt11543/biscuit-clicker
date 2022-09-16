#include "Sprite.h"

GraphicsBuffer* Sprite::getGraphicsBuffer() {
	return mGraphicsBuffer;
}

int Sprite::getHeight() {
	return mHeight;
}

int Sprite::getWidth() {
	return mWidth;
}

int Sprite::getX() {
	return mX;
}

int Sprite::getY() {
	return mY;
}

Sprite::Sprite(GraphicsBuffer* buffer, int x, int y, int width, int height) {
	this->mGraphicsBuffer = buffer;
	this->mX = x;
	this->mY = y;
	this->mWidth = width;
	this->mHeight = height;
}

Sprite::~Sprite() {
	
}