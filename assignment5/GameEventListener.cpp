#include "GameEventListener.h"
#include "Game.h"

GameEventListener::GameEventListener() {

}

GameEventListener::~GameEventListener() {

}

void GameEventListener::handleEvent(const Event& theEvent) {
	switch(theEvent.getType()) {
		case ADD_UNIT_EVENT:
			handleAddUnitEvent((const AddUnitEvent&)theEvent);
			break;
		case DEANIFY_UNIT_EVENT:
			handleDeanifyUnitEvent((const DeanifyUnitEvent&)theEvent);
			break;
		case DELETE_UNIT_EVENT:
			handleDeleteUnitEvent((const DeleteUnitEvent&)theEvent);
			break;
		case QUIT_GAME_EVENT:
			handleQuitGameEvent((const QuitGameEvent&)theEvent);
			break;
		case START_GAME_EVENT:
			Game::getInstance()->difficultyMenuOn();
			break;
		case OPTIONS_MENU_EVENT:
			Game::getInstance()->pauseOn();
			break;
		case RETURN_TO_PREVIOUS_STATE_EVENT:
			Game::getInstance()->loadPreviousState();
			break;
		case RAISE_VOLUME_EVENT:
			Game::getInstance()->getSoundSystem()->raiseVolume(1);
			break;
		case LOWER_VOLUME_EVENT:
			Game::getInstance()->getSoundSystem()->lowerVolume(1);
			break;
		case CHANGE_LANGUAGE_EVENT:
			Game::getInstance()->getLanguage()->changeCurrentLanguage();
			break;
		case LOAD_GAME_EVENT:
			Game::getInstance()->loadGame();
			cout << "load" << endl;
			break;
		case SAVE_GAME_EVENT:
			Game::getInstance()->saveGame();
			cout << "save" << endl;
			break;
		case SHOP_EVENT:
			handleShopEvent((const ShopEvent&)theEvent);
			break;
		case DIFFICULTY_MENU_ON_EVENT:
			Game::getInstance()->getLanguage()->changeCurrentLanguage();
			break;
		case START_GAME_AT_DIFFICULTY:
			handleStartGameAtDifficultyEvent((const StartGameAtDifficultyEvent&)theEvent);
		case TOGGLE_FREEZE_ANIMATION_EVENT:
			handleToggleFreezeAnimationEvent((const ToggleFreezeAnimationEvent&)theEvent);
			break;
	}
}

void GameEventListener::handleAddUnitEvent(const AddUnitEvent& theEvent) {
	// Game::getInstance()->makeSmurfUnit(theEvent.getX(), theEvent.getY());
}

void GameEventListener::handleDeanifyUnitEvent(const DeanifyUnitEvent& theEvent) {
	// Game::getInstance()->getUnitManager()->deanifyLastUnit(Game::getInstance()->getAnimationManager()->getAnimation("deanAnimation"));
	cout << "Why did a deanifyUnitEvent get fired?" << endl;
}

void GameEventListener::handleDeleteUnitEvent(const DeleteUnitEvent& theEvent) {
	Game::getInstance()->getUnitManager()->storeIndex(theEvent.getX(), theEvent.getY(), theEvent.getUnitType()); //removeUnit(theEvent.getX(), theEvent.getY());
}

void GameEventListener::handleQuitGameEvent(const QuitGameEvent& theEvent) {
	// cout << "The game should quit now" << endl;
	Game::getInstance()->quit();
}

void GameEventListener::handleShopEvent(const ShopEvent& theEvent)
{
	Game::getInstance()->getShop()->purchaseUpgrade(theEvent.getUpgrade());
}

void GameEventListener::handleStartGameAtDifficultyEvent(const StartGameAtDifficultyEvent& theEvent)
{
	Game::getInstance()->gameOn(theEvent.getLevel());
}

void GameEventListener::handleToggleFreezeAnimationEvent(const ToggleFreezeAnimationEvent& theEvent) {
	// Game::getInstance()->getUnitManager()->toggleAnimationAll();
}