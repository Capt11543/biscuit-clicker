#pragma once

#include <EventListener.h>
#include "GameEvents.h"

class GameEventListener : public EventListener {
	public:
		GameEventListener();
		~GameEventListener();
		void handleEvent(const Event& theEvent);
	private:
		void handleAddUnitEvent(const AddUnitEvent& theEvent);
		void handleDeanifyUnitEvent(const DeanifyUnitEvent& theEvent);
		void handleDeleteUnitEvent(const DeleteUnitEvent& theEvent);
		void handleQuitGameEvent(const QuitGameEvent& theEvent);
		void handleShopEvent(const ShopEvent& theEvent);
		void handleStartGameAtDifficultyEvent(const StartGameAtDifficultyEvent& theEvent);
		void handleToggleFreezeAnimationEvent(const ToggleFreezeAnimationEvent& theEvent);
};