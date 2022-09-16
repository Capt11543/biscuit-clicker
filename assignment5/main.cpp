#include <iostream>
#include <cassert>
#include <string>

#include <PerformanceTracker.h>
#include <MemoryTracker.h>

#include "Game.h"
#include <GraphicsLib.h>

#include <stdlib.h>
#include <time.h>

#include <EventSystem.h>
#include "LevelingSystem.h"

using namespace std;

int main() {
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	EventSystem::initInstance();

	Game* game = Game::getInstance();
	game->init(SCREEN_WIDTH, SCREEN_HEIGHT);

	game->doLoop();

	// EventSystem::cleanupInstance(); // I am aware that not calling this will cause a memory leak but at this point I don't have time to figure that out
	Game::cleanup();
	EventSystem::cleanupInstance();

	MemoryTracker::getInstance()->reportAllocations(cout);
	std::system("pause");

	return 0;
}