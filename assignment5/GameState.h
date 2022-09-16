#pragma once
#include <Trackable.h>

class GameState : public Trackable
{
public:
	virtual ~GameState() {}
	virtual void init(int width, int height, int timePerframe) {}
	virtual void update(double deltaTime) {}
	virtual void draw() {}
	virtual void returnedToState() {}
	virtual void leavingState() {}
};