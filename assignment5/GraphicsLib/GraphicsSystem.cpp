#include "GraphicsSystem.h"

void GraphicsSystem::cleanup() {
	// Free all memory
	delete mBackBuffer;
	al_destroy_display(mDisplay);
}

void GraphicsSystem::draw(int x, int y, Sprite sprite) {
	// Target Allegro backBuffer, draw given Sprite at given position
	al_set_target_bitmap(mBackBuffer->mBitmap);
	al_draw_bitmap_region(sprite.getGraphicsBuffer()->mBitmap, sprite.getX(), sprite.getY(), sprite.getWidth(), sprite.getHeight(), x, y, 0);
}

void GraphicsSystem::draw(int x, int y, Sprite sprite, float scale) {
	// Create temporary bitmap, draw given Sprite to it
	ALLEGRO_BITMAP* temp = al_create_bitmap(sprite.getWidth(), sprite.getHeight());
	al_set_target_bitmap(temp);
	al_draw_bitmap_region(sprite.getGraphicsBuffer()->mBitmap, sprite.getX(), sprite.getY(), sprite.getWidth(), sprite.getHeight(), 0, 0, 0);

	// Target Allegro backBuffer, draw given Sprite at given position with given scale
	al_set_target_bitmap(mBackBuffer->mBitmap);
	al_draw_scaled_bitmap(temp, 0, 0, sprite.getWidth(), sprite.getHeight(), x, y, sprite.getWidth() * scale, sprite.getHeight() * scale, 0);

	al_destroy_bitmap(temp); // Free memory
}

void GraphicsSystem::draw(GraphicsBuffer* buffer, int x, int y, Sprite sprite) {
	// Target given GraphicsBuffer, draw given Sprite at given position
	al_set_target_bitmap(buffer->mBitmap);
	al_draw_bitmap_region(sprite.getGraphicsBuffer()->mBitmap, sprite.getX(), sprite.getY(), sprite.getWidth(), sprite.getHeight(), x, y, 0);
}

void GraphicsSystem::draw(GraphicsBuffer* buffer, int x, int y, Sprite sprite, float scale) {
	// Create temporary bitmap, draw given Sprite to it
	ALLEGRO_BITMAP* temp = al_create_bitmap(sprite.getWidth(), sprite.getHeight());
	al_set_target_bitmap(temp);
	al_draw_bitmap_region(sprite.getGraphicsBuffer()->mBitmap, sprite.getX(), sprite.getY(), sprite.getWidth(), sprite.getHeight(), 0, 0, 0);

	// Target given GraphicsBuffer, draw given Sprite at given position with given scale
	al_set_target_bitmap(buffer->mBitmap);
	al_draw_scaled_bitmap(temp, 0, 0, sprite.getWidth(), sprite.getHeight(), x, y, sprite.getWidth() * scale, sprite.getHeight() * scale, 0);

	al_destroy_bitmap(temp); // Free memory
}

void GraphicsSystem::drawRect(int x1, int y1, int x2, int y2, Color color) {
	al_set_target_bitmap(mBackBuffer->mBitmap);
	al_draw_filled_rectangle(x1, y1, x2, y2, color.getColor());
}

void GraphicsSystem::drawRect(GraphicsBuffer* buffer, int x1, int y1, int x2, int y2, Color color) {
	al_set_target_bitmap(buffer->mBitmap);
	al_draw_filled_rectangle(x1, y1, x2, y2, color.getColor());
}

void GraphicsSystem::flip() {
	al_flip_display(); // Draw contents of backBuffer to the screen
}

GraphicsBuffer* GraphicsSystem::getBackBuffer() {
	return mBackBuffer;
}

int GraphicsSystem::getHeight() {
	return mHeight;
}

int GraphicsSystem::getWidth() {
	return mWidth;
}

GraphicsSystem::GraphicsSystem() {
	mWidth = -1;
	mHeight = -1;
	mDisplay = nullptr;
	mBackBuffer = nullptr;
}

GraphicsSystem::~GraphicsSystem() {
	
}

bool GraphicsSystem::init(int width, int height) {
	// Initialize Allegro graphics modules
	
	if(!al_init_image_addon()) {
		cout << "error - Image Add-on not initted\n";
		return false;
	}
	if(!al_init_font_addon()) {
		cout << "error - Font Add-on not initted\n";
		return false;
	}
	if(!al_init_ttf_addon()) {
		cout << "error - TTF Add-on not initted\n";
		return false;
	}
	if(!al_init_primitives_addon()) {
		cout << "error - primitives Add-on not initted\n";
		return false;
	}

	this->mWidth = width;
	this->mHeight = height;

	this->mDisplay = al_create_display(width, height);
	this->mBackBuffer = new GraphicsBuffer(mDisplay);

	return true;
}

void GraphicsSystem::saveBuffer(string filename) {
	// Save backBuffer to given filename
	al_save_bitmap(filename.c_str(), mBackBuffer->mBitmap);
}

void GraphicsSystem::saveBuffer(GraphicsBuffer* buffer, string filename) {
	// Save given buffer to given filename
	al_save_bitmap(filename.c_str(), buffer->mBitmap);
}

void GraphicsSystem::writeText(int x, int y, Font font, Color color, string text, int alignment)
{
	// Draw given string with given properties on backBuffer
	al_set_target_bitmap(mBackBuffer->mBitmap);
	al_draw_text(font.getFont(), color.getColor(), x, y, alignment, text.c_str());
}

void GraphicsSystem::writeText(GraphicsBuffer* buffer, int x, int y, Font font, Color color, string text) {
	// Draw given string with given properties on given buffer
	al_set_target_bitmap(buffer->mBitmap);
	al_draw_text(font.getFont(), color.getColor(), x, y, 1, text.c_str());
}