#pragma once

#include <map>
#include "Sprite.h"
#include <Trackable.h>
#include <vector>

class SpriteManager : public Trackable {
	public:
		// void addSprite(Sprite* sprite, string name);
		void addSprite(Sprite* sprite);
		void addSprite(Sprite* sprite, string name);
		void clear();
		int getIndex(string name);
		Sprite* getSprite(int index);
		Sprite* getSprite(string name);
		SpriteManager();
		~SpriteManager();
	private:
		vector<Sprite*> mSpriteList;
		map<string, int> mSpriteIndexMap;
};