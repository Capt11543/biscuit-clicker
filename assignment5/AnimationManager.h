#pragma once

#include "Animation.h"
#include <map>
#include <Trackable.h>

class AnimationManager: public Trackable {
	public:
		void addAnimation(Animation* animation, string name);
		AnimationManager();
		~AnimationManager();
		void clear();
		Animation* getAnimation(string name);
	private:
		map<string, Animation*> mAnimationMap;
};