#pragma once

#include <iostream>
#include <fstream>
#include <Trackable.h>
#include <vector>
#include <cassert>
#include <string>


class TextReader : public Trackable {
public:
	TextReader();
	~TextReader();

	//Read and store values from file into vector
	void readFile(std::string loc, std::string name);

	void writeToFile(std::string loc, std::string name, std::vector<int> content);
	std::vector<int> loadGameSave(std::string loc, std::string name);

	//Reset to read new file
	void deleteText();

	//Get function for read value
	std::string getValueAtIndex(unsigned int index);

	//Get functions for private var and var components
	bool hasContents();
	int getSize();
	std::string getCurrentFileName();

private:
	std::ifstream mReadFile;
	std::ofstream mWriteToFile;
	std::string mFileName;
	std::vector<std::string> mContents;
	bool mHasContents;
};