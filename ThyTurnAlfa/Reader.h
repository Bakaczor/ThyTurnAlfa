#pragma once
#include <iostream>
#include <fstream>
#include <json/json.h>
#include <vector>
#include "Character.h"

class Reader
{
public:
	bool readFile(const std::string& filename);
	std::vector<Character> extractCharacters();
	std::vector<std::vector<std::string>> extractParties();
private:
	Json::Value m_jsonData;
	std::vector<Character> m_characters;
	std::vector<std::vector<std::string>> m_parties;
};