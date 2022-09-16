#pragma once

#include <iostream>
#include <fstream>
#include <Trackable.h>
#include <vector>
#include <cassert>
#include <string>

enum LangType {
	ENGLISH = 0,
	ITALIAN,
	KLINGON
};

class Language : public Trackable {
public:
	Language();
	~Language();

	std::string getTextAt(int index);
	void changeCurrentLanguage();

	const int NUM_LANG = 3;
private:
	std::ifstream mReadFile;

	std::vector<std::string> mEnglish;
	std::vector<std::string> mItalian;
	std::vector<std::string> mKlingon;

	const std::string ASSET_PATH = "..\\assets\\";
	const std::string FILE_NAME = "languages.txt";

	LangType mCurrentLang = LangType::ENGLISH;
};