#include "TextReader.h"


TextReader::TextReader()
{
	mHasContents = false;
}

TextReader::~TextReader()
{
}

void TextReader::readFile(std::string loc, std::string name)
{
	assert(!mHasContents);
	mReadFile.open(loc.c_str(), std::ios::in);
	
	assert(mReadFile);

	mFileName = name;

	std::string string = "";
	while (std::getline(mReadFile, string))
	{
		mContents.push_back(string);
	}

	mHasContents = true;
	mReadFile.close();
}

void TextReader::writeToFile(std::string loc, std::string name, std::vector<int> content)
{
	mWriteToFile.open((loc + name).c_str(), std::ios::trunc);

	assert(mWriteToFile);

	for (unsigned int i = 0; i < content.size(); i++)
	{
		mWriteToFile << content[i] << "\n";
	}
	mWriteToFile.close();
}

std::vector<int> TextReader::loadGameSave(std::string loc, std::string name)
{
	mReadFile.open((loc + name).c_str(), std::ios::in);
	std::vector<int> values;

	std::string str;
	while (std::getline(mReadFile, str))
	{
		values.push_back(stoi(str));
	}
	return values;
}

void TextReader::deleteText()
{
	mContents.clear();
	mHasContents = false;
	mFileName = "";
}

bool TextReader::hasContents()
{
	return mHasContents;
}

int TextReader::getSize()
{
	assert(mHasContents);
	return mContents.size();
}

std::string TextReader::getValueAtIndex(unsigned int index)
{
	assert(index < mContents.size());
	return mContents[index];
}

std::string TextReader::getCurrentFileName()
{
	return mFileName;
}
