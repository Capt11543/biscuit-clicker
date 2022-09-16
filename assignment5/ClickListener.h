#pragma once

#include <EventListener.h>

class ClickListener : public EventListener {
	public:
		ClickListener(int x, int y, int width, int height);
		int getBoundsHeight();
		int getBoundsWidth();
		int getBoundsX();
		int getBoundsY();
		void handleEvent(const Event& theEvent);
		void setBounds(int x, int y, int width, int height);
	protected:
		virtual void onLeftClick();
		virtual void onRightClick();
	private:
		int mBoundsHeight, mBoundsWidth, mBoundsX, mBoundsY;
};