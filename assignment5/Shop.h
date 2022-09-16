// I created these, but I anticipate Neo will be using these the most--you can decide which container they go in ~H

#pragma once

#include <Trackable.h>
#include <Vector2D.h>
#include <vector>

enum UpgradeType {
	INGREDIENT,
	NUM_CLICKERS,
	CLICKER,
	REPELLANT
};

class Shop : public Trackable {
	public:
		void addMoney(int amonut);
		int getMoney();
		int getIngredientLevel();
		int getClickers();
		int getClickerLevel();
		int getRepellantLevel();
		void setIngredientLevel(int ingredLevel);
		void setClickers(int click);
		void setClickerLevel(int clickLevel);
		void setRepellantLevel(int repellLevel);
		std::vector<bool> canPlayerBuyUpgrades();

		Vector2D getAutoClickerPos();

		Shop();

		bool purchaseUpgrade(UpgradeType type);
		int getUpgradeLevel(UpgradeType type);
	private:
		int mMoney;
		int ingredientLevel;
		int clickers;
		int clickerLevel;
		int repellantLevel;

		int mX = 400, mY = 500;
};