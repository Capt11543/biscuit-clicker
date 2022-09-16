#include "GraphicsBufferManager.h"

void GraphicsBufferManager::addGraphicsBuffer(GraphicsBuffer* buffer, string name) {
	mGraphicsBufferMap[name] = buffer;
}

void GraphicsBufferManager::clear() {
	map<string, GraphicsBuffer*>::iterator it;
	for(it = mGraphicsBufferMap.begin(); it != mGraphicsBufferMap.end(); ++it) {
		delete it->second;
	}

	mGraphicsBufferMap.clear();
}

GraphicsBuffer* GraphicsBufferManager::getBackBuffer(GraphicsSystem* system) {
	return system->getBackBuffer();
}

GraphicsBuffer* GraphicsBufferManager::getGraphicsBuffer(string name) {
	return mGraphicsBufferMap[name];
}

GraphicsBufferManager::GraphicsBufferManager() {

}

GraphicsBufferManager::~GraphicsBufferManager() {
	clear();
}