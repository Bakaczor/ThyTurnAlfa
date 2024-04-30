#pragma once
#include <json/json.h>
#include <vector>
#include "Character.hpp"
#include "PartyPreset.hpp"

#ifndef READER_HPP
#define READER_HPP

class Reader {
	public:
	bool readFile(const std::string& filename);
	std::vector<Character>&& extractCharacters();
	std::vector<PartyPreset> extractParties();

	private:
	Json::Value m_jsonData;
	std::vector<Character> m_characters;
	std::vector<PartyPreset> m_parties;
};

#endif