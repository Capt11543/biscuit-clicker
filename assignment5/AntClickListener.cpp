#include "AntClickListener.h"
#include <EventSystem.h>
#include "GameEvents.h"
#include <iostream>

using namespace std;

AntClickListener::AntClickListener(int x, int y, int width, int height) : ClickListener(x, y, width, height) {

}

AntClickListener::~AntClickListener()
{
}

void AntClickListener::onLeftClick() {
	//cout << "Ant click!" << endl;
	EventSystem::getInstance()->fireEvent(DeleteUnitEvent(getBoundsX(), getBoundsY(), UnitType::ANT));
}