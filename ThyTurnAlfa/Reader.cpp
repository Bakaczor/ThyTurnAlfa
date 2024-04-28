#include "Reader.hpp"
#include <iostream>
#include <fstream>

bool Reader::readFile(const std::string& filename)
{
    std::ifstream file(filename);
    if (file) {
        Json::Reader reader;
        if (reader.parse(file, m_jsonData, false)) {
            return true;
        }
    }
    file.close();
    return false;
}

std::vector<Character>&& Reader::extractCharacters()
{
    auto characterArray = m_jsonData["characters"];
    for (auto character : characterArray) {
        Character deserializedCharacter;
        deserializedCharacter.deserialize(character);
        m_characters.push_back(std::move(deserializedCharacter));
    }
    return std::move(m_characters);
}

std::vector<PartyPreset> Reader::extractParties()
{
    auto partyArray = m_jsonData["parties"];
    for (auto party : partyArray) {
        m_parties.emplace_back();
        m_parties.back().partyName = party["partyName"].asString();
        auto characterArray = party["characters"];
        for (auto character : characterArray) {
            std::string characterName = character["name"].asString();
            m_parties.back().characterNames.push_back(characterName);
        }
    }
    return m_parties;
}