// Map version of this class exists at svn revision 250

#pragma once

// #include <map>
#include "Unit.h"
#include <vector>

class UnitManager : public Trackable {
	public:
		void addUnit(Unit* unit);
		void clear();
		// void deanifyLastUnit(Animation* deanAnimation); // I'm starting to lose it
		void draw(GraphicsSystem* gSystem);
		Unit* getUnit(int index);
		Unit* getFirstOfType(UnitType unitType);
		vector<Unit*> getUnitsOfType(UnitType type);
		void removeUnit(int mouseX, int mouseY);
		void removeDeadUnits();
		void storeIndex(int mouseX, int mouseY, UnitType type);
		UnitManager();
		~UnitManager();
		void update(double deltaTime);
		void updateAntsSpeed();
		void updateClickerRate();
	private:
		vector<Unit*> mUnitList;
		vector<int> mDeleteList;
};