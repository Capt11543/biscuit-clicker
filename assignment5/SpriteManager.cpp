#include "SpriteManager.h"

void SpriteManager::addSprite(Sprite* sprite) {
	mSpriteList.push_back(sprite);
}

void SpriteManager::addSprite(Sprite* sprite, string name) {
	mSpriteList.push_back(sprite);
	mSpriteIndexMap[name] = mSpriteList.size() - 1;
}

void SpriteManager::clear() {
	for(unsigned int i = 0; i < mSpriteList.size(); i++) {
		delete mSpriteList[i];
	}

	mSpriteList.clear();
}

int SpriteManager::getIndex(string name) {
	return mSpriteIndexMap[name];
}

Sprite* SpriteManager::getSprite(int index) {
	return mSpriteList[index];
}

Sprite* SpriteManager::getSprite(string name) {
	return mSpriteList[mSpriteIndexMap[name]];
}

SpriteManager::SpriteManager() {
	
}

SpriteManager::~SpriteManager() {
	clear();
}