#pragma once

#include "LevelingSystem.h"

class AntSpawner : public Trackable {
	public:
		AntSpawner();
		void init();
		void update(double deltaTime);
		void updateSpawnRate();
	private:
		LevelingSystem* mLevelingSystem;
		double mOriginalSpawnRate;
		double mSpawnRate;
		double mSpawnTimer;
};