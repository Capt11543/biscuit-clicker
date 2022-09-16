#include "AnimationManager.h"

void AnimationManager::addAnimation(Animation* animation, string name) {
	mAnimationMap[name] = animation;
}

void AnimationManager::clear() {
	map<string, Animation*>::iterator it;
	for(it = mAnimationMap.begin(); it != mAnimationMap.end(); ++it) {
		delete it->second;
	}

	mAnimationMap.clear();
}

Animation* AnimationManager::getAnimation(string name) {
	return mAnimationMap[name];
}

AnimationManager::AnimationManager() {

}

AnimationManager::~AnimationManager() {
	clear();
}