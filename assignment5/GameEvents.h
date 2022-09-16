#pragma once

#include <Event.h>
#include <InputEvents.h>
#include "Shop.h"
#include "Unit.h"

enum GameEventType { 
	ADD_UNIT_EVENT = NUM_INPUT_EVENT_TYPES + 1, // I feel like this is a really bad way to do this, but I don't know how else to do it
	DEANIFY_UNIT_EVENT,
	DELETE_UNIT_EVENT,
	QUIT_GAME_EVENT,
	START_GAME_EVENT,
	TOGGLE_FREEZE_ANIMATION_EVENT,
	OPTIONS_MENU_EVENT,
	RETURN_TO_PREVIOUS_STATE_EVENT,
	RAISE_VOLUME_EVENT,
	LOWER_VOLUME_EVENT,
	CHANGE_LANGUAGE_EVENT,
	LOAD_GAME_EVENT,
	SAVE_GAME_EVENT,
	DIFFICULTY_MENU_ON_EVENT,
	START_GAME_AT_DIFFICULTY,
	SHOP_EVENT
};

class AddUnitEvent : public Event {
	public:
		AddUnitEvent(int x, int y);
		~AddUnitEvent();
		int getX() const;
		int getY() const;
	private:
		int mX, mY;
};

class DeanifyUnitEvent : public Event { // I may not have needed to make this but I thought it would be cool!
	public:
		DeanifyUnitEvent();
		~DeanifyUnitEvent();
};

class DeleteUnitEvent : public Event {
	public:
		DeleteUnitEvent(int x, int y, UnitType type);
		~DeleteUnitEvent();
		UnitType getUnitType() const;
		int getX() const;
		int getY() const;
	private:
		UnitType mUnitType;
		int mX, mY;
};

class QuitGameEvent : public Event {
	public:
		QuitGameEvent();
		~QuitGameEvent();
};

class StartGameEvent : public Event {
public:
	StartGameEvent();
	~StartGameEvent();
};

class ToggleFreezeAnimationEvent : public Event {
	public:
		ToggleFreezeAnimationEvent();
		~ToggleFreezeAnimationEvent();
};

class OptionsMenuEvent : public Event {
public:
	OptionsMenuEvent();
	~OptionsMenuEvent();
};

class ReturnToPreviousState : public Event {
public:
	ReturnToPreviousState();
	~ReturnToPreviousState();
};

class RaiseVolumeEvent : public Event {
public:
	RaiseVolumeEvent();
	~RaiseVolumeEvent();
};

class LowerVolumeEvent : public Event {
public:
	LowerVolumeEvent();
	~LowerVolumeEvent();
};

class ChangeLanguageEvent : public Event {
public:
	ChangeLanguageEvent();
	~ChangeLanguageEvent();
};

class LoadGameEvent : public Event {
public:
	LoadGameEvent();
	~LoadGameEvent();
};

class SaveGameEvent : public Event {
public:
	SaveGameEvent();
	~SaveGameEvent();
};

class ShopEvent : public Event {
public:
	ShopEvent(UpgradeType upgrade);
	~ShopEvent();
	UpgradeType getUpgrade() const;
private:
	UpgradeType mUpgrade;
};

class StartGameAtDifficultyEvent : public Event {
public:
	StartGameAtDifficultyEvent(int level);
	~StartGameAtDifficultyEvent();
	int getLevel() const;
private:
	int mLevel;
};

class DifficultyMenuOnEvent : public Event {
public:
	DifficultyMenuOnEvent();
	~DifficultyMenuOnEvent();
private:
};