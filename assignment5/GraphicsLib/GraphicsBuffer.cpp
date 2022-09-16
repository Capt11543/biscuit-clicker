#include "GraphicsBuffer.h"

int GraphicsBuffer::getHeight() {
	return al_get_bitmap_height(mBitmap);
}

int GraphicsBuffer::getWidth() {
	return al_get_bitmap_width(mBitmap);
}

GraphicsBuffer::GraphicsBuffer(string filename) {
	mBitmap = al_load_bitmap(filename.c_str());
}

GraphicsBuffer::GraphicsBuffer(int width, int height, Color color) {
	mBitmap = al_create_bitmap(width, height);

	al_set_target_bitmap(mBitmap);
	al_draw_filled_rectangle(0, 0, width, height, color.getColor());
}

GraphicsBuffer::GraphicsBuffer(ALLEGRO_DISPLAY* display) { // we can use this to get the Allegro back buffer in order to save its contents to a file
	mBitmap = al_get_backbuffer(display);
}

GraphicsBuffer::~GraphicsBuffer() {

}