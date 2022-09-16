#pragma once

#include "AntClickListener.h"
#include "Unit.h"

class Biscuit;

class Ant : public Unit {
	public:
		Ant(int x, int y, Biscuit* biscuit);
		~Ant();
		void startWalking();
		void update(double deltaTime);
		void updateMoveSpeed();
	private:
		bool collidingWithBiscuit();
		Biscuit* mBiscuit;
		AntClickListener* mListener;
		const float mInitialMoveSpeed = 160.0f;
		float mMoveSpeed = 160.0f;
		bool mKeepWalking;
		bool mWalking;
};