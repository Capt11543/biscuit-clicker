#include "Ant.h"
#include "AntSpawner.h"
#include "Game.h"

AntSpawner::AntSpawner() {
	mSpawnRate = 6000;
	mSpawnTimer = 0;
	mOriginalSpawnRate = mSpawnRate;
	mLevelingSystem = nullptr;
}

void AntSpawner::init() { // because AntSpawner needs data from Game::mpLevelingSystem that gets initialized in LevelingSystem::init(), not LevelingSystem::LevelingSystem()
	mLevelingSystem = Game::getInstance()->getLeveling();
	mSpawnRate = mLevelingSystem->getTimeBetweenAnts();
	//cout << mSpawnRate << endl;
}

void AntSpawner::update(double deltaTime) {
	mSpawnTimer += deltaTime;

	// updateSpawnRate();

	if (mSpawnTimer >= mSpawnRate) {
		vector<Unit*> ants = Game::getInstance()->getUnitManager()->getUnitsOfType(ANT);
		for(unsigned int i = 0; i < ants.size(); i++) {
			static_cast<Ant*>(ants[i])->startWalking();
		}

		Game::getInstance()->makeAntUnit(0, 300);
		Game::getInstance()->getSoundSystem()->playAudioSample("ant", 0);
		
		mSpawnTimer = 0;
	}

	//cout << mSpawnTimer << endl;
}

void AntSpawner::updateSpawnRate(){ // this doesn't need to happen every frame; it can happen on an event call
	mSpawnRate = mOriginalSpawnRate * pow(1.1, Game::getInstance()->getShop()->getUpgradeLevel(REPELLANT));
	//cout << "new spawn rate " << mSpawnRate << endl;
}
