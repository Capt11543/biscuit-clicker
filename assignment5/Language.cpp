#include "Language.h"

Language::Language()
{
	mReadFile.open((ASSET_PATH + FILE_NAME).c_str(), std::ios::in);

	assert(mReadFile);

	std::string str = "";
	std::string substring;
	while (std::getline(mReadFile, str))
	{
		int commaIndex = str.find(",");
		substring = str.substr(0, commaIndex);
		mEnglish.push_back(substring);
		str = str.substr(commaIndex+1);

		assert(str.size() > 0);
		commaIndex = str.find(",");
		substring = str.substr(0, commaIndex);
		mItalian.push_back(substring);
		str = str.substr(commaIndex+1);
		assert(str.size() > 0);

		commaIndex = str.find(",");
		substring = str.substr(0, commaIndex);
		mKlingon.push_back(substring);
		str = str.substr(commaIndex + 1);
		assert(str.size() <= 0);
	}

	mReadFile.close();
}

Language::~Language()
{
}

std::string Language::getTextAt(int index)
{
	switch (mCurrentLang)
	{
		case LangType::ENGLISH:
			return mEnglish[index];
		case LangType::ITALIAN:
			return mItalian[index];
		case LangType::KLINGON:
			return mKlingon[index];
	}
}

void Language::changeCurrentLanguage()
{
	int current = (int)mCurrentLang + 1;
	current = current % NUM_LANG;
	//current = (current++) % NUM_LANG;
	std::cout << current << (current) % NUM_LANG << std::endl;
	assert(current < NUM_LANG);
	mCurrentLang = (LangType)current;
}
