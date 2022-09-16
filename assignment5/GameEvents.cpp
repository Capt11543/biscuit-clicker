#include "GameEvents.h"

AddUnitEvent::AddUnitEvent(int x, int y) : Event((EventType)ADD_UNIT_EVENT) {
	mX = x;
	mY = y;
}

AddUnitEvent::~AddUnitEvent() {

}

int AddUnitEvent::getX() const {
	return mX;
}

int AddUnitEvent::getY() const {
	return mY;
}

DeanifyUnitEvent::DeanifyUnitEvent() : Event((EventType)DEANIFY_UNIT_EVENT) {

}

DeanifyUnitEvent::~DeanifyUnitEvent() {

}

DeleteUnitEvent::DeleteUnitEvent(int x, int y, UnitType type) : Event((EventType)DELETE_UNIT_EVENT) {
	mUnitType = type;
	mX = x;
	mY = y;
}

DeleteUnitEvent::~DeleteUnitEvent() {

}

UnitType DeleteUnitEvent::getUnitType() const {
	return mUnitType;
}

int DeleteUnitEvent::getX() const {
	return mX;
}

int DeleteUnitEvent::getY() const {
	return mY;
}

QuitGameEvent::QuitGameEvent() : Event((EventType)QUIT_GAME_EVENT) {
	
}

QuitGameEvent::~QuitGameEvent() {

}

StartGameEvent::StartGameEvent() : Event((EventType)START_GAME_EVENT) {
	
}

StartGameEvent::~StartGameEvent() {
	
}

ToggleFreezeAnimationEvent::ToggleFreezeAnimationEvent() : Event((EventType)TOGGLE_FREEZE_ANIMATION_EVENT) {

}

ToggleFreezeAnimationEvent::~ToggleFreezeAnimationEvent() {

}

OptionsMenuEvent::OptionsMenuEvent() : Event((EventType)OPTIONS_MENU_EVENT)
{
}

OptionsMenuEvent::~OptionsMenuEvent()
{
}

ReturnToPreviousState::ReturnToPreviousState() : Event((EventType)RETURN_TO_PREVIOUS_STATE_EVENT)
{
}

ReturnToPreviousState::~ReturnToPreviousState()
{
}

RaiseVolumeEvent::RaiseVolumeEvent() : Event((EventType)RAISE_VOLUME_EVENT)
{
}

RaiseVolumeEvent::~RaiseVolumeEvent()
{
}

LowerVolumeEvent::LowerVolumeEvent() : Event((EventType)LOWER_VOLUME_EVENT)
{
}

LowerVolumeEvent::~LowerVolumeEvent()
{
}

ChangeLanguageEvent::ChangeLanguageEvent() : Event((EventType)CHANGE_LANGUAGE_EVENT)
{
}

ChangeLanguageEvent::~ChangeLanguageEvent()
{
}

LoadGameEvent::LoadGameEvent() : Event((EventType)LOAD_GAME_EVENT)
{
}

LoadGameEvent::~LoadGameEvent()
{
}

SaveGameEvent::SaveGameEvent() : Event((EventType)SAVE_GAME_EVENT)
{
}

SaveGameEvent::~SaveGameEvent()
{
}

ShopEvent::ShopEvent(UpgradeType upgrade) : Event((EventType)SHOP_EVENT)
{
	mUpgrade = upgrade;
}

ShopEvent::~ShopEvent()
{
}

UpgradeType ShopEvent::getUpgrade() const
{
	return mUpgrade;
}

StartGameAtDifficultyEvent::StartGameAtDifficultyEvent(int level) : Event((EventType)START_GAME_AT_DIFFICULTY)
{
	mLevel = level;
}

StartGameAtDifficultyEvent::~StartGameAtDifficultyEvent()
{
}

int StartGameAtDifficultyEvent::getLevel() const
{
	return mLevel;
}

DifficultyMenuOnEvent::DifficultyMenuOnEvent() : Event((EventType)DIFFICULTY_MENU_ON_EVENT)
{
}

DifficultyMenuOnEvent::~DifficultyMenuOnEvent()
{
}
