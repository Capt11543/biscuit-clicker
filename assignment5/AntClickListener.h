#pragma once

#include "ClickListener.h"

class AntClickListener : public ClickListener {
	public:
		AntClickListener(int x, int y, int width, int height);
		~AntClickListener();
	private:
		void onLeftClick();
};