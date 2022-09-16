#pragma once

#include "BiscuitClickListener.h"
#include "Unit.h"

class Biscuit : public Unit {
	public:
		Biscuit(int x, int y, bool state);
		~Biscuit();
		bool getState();
		void setState(bool state);
		BiscuitClickListener* getListener(); // I feel like I will pay for this later
	private:
		bool contaminated();
		BiscuitClickListener* mListener;
		void update(double deltaTime);
};