#pragma once
#include "Button.h"
#include "Text.h"
#include "TextReader.h"
#include <vector>
#include "Language.h"

enum ButtonType {
	START = 0,
	QUIT,
	OPTIONS,
	VOLUME_UP,
	VOLUME_DOWN,
	SAVE,
	LOAD,
	LANGUAGE,
	BACK,
	PAUSE,
	SHOP_INGREDIENT,
	SHOP_CLICKER,
	SHOP_REPELLANT,
	SHOP_NUM_CLICKERS,
	DIFFICULTY_MIN,
	DIFFICULTY_NEUTRAl,
	DIFFICULTY_MAX,
	GENERIC
};


//Needs to be deleted in game.cpp, but there is an error I can't fix
class ButtonManager : public Trackable 
{
public:
	enum MenuType {
		MAIN_MENU = 0,
		GAME_MENU,
		PAUSE_MENU,
		DIFFICULTY_MENU
	};

	ButtonManager();
	~ButtonManager();

	void addButton(Button* button, MenuType menuType, bool isEnabled = true);

	void update(double deltaTime);
	void draw(GraphicsSystem* gSystem);
	void clear();

	void switchMenu(MenuType menuType);
	
	static void fireEvent(ButtonType buttonType);
	
	void readFile(string loc, string file);

	void checkIfShopButtonsEnabled();

	bool isMainMenuOn();
	bool isGameMenuOn();
	bool isPauseMenuOn();

	void setFont(string fontFile, int fontSize);
	void setColor(int red, int green, int blue, int alpha);

private:
	vector<Button*>* mpActiveButtons = nullptr;
	vector<Button*> mpMainMenu;
	vector<Button*> mpGameMenu;
	vector<Button*> mpPauseMenu;
	vector<Button*> mpDifficultyMenu;

	Text* mpText;
	TextReader* mpReader;
	Language* mpLanguageHolder;

	bool mMainMenuOn = true;
	bool mGameMenuOn = false;
	bool mPauseMenuOn = false;
	bool mDifficultyMenuOn = false;
	bool justSwitched = false;
	bool mIsInited = false;

	void init();
	void clearMenu(vector<Button*> buttonVector);
	void setMenuButtonsState(bool state, vector<Button*>& buttons);
};