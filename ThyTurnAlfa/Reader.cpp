#include "Reader.h"

bool Reader::readFile(const std::string& filename)
{
    std::ifstream file(filename);
    if (file) {
        Json::Reader reader;
        if (reader.parse(file, m_jsonData, false)) {
            return true;
        }
    }
    return false;
}

std::vector<Character> Reader::extractCharacters()
{
    auto characterArray = m_jsonData["characters"];
    for (auto character : characterArray) {
        Character deserializedCharacter;
        deserializedCharacter.Deserialize(character);
        m_characters.push_back(deserializedCharacter);
    }
    return m_characters;
}

std::vector<std::vector<Character>> Reader::extractParties()
{
    auto partyArray = m_jsonData["parties"];
    for (auto party : partyArray) {
        m_parties.emplace_back();
        auto characterArray = party["characters"];
        for (auto character : characterArray) {
            std::string characterName = character["name"].asString();
            auto deserializedCharacter =
                std::find_if(m_characters.begin(), m_characters.end(),
                    [characterName](auto& c) { return c.getName() == characterName; });
            if (deserializedCharacter != m_characters.end()) {
                m_parties.back().push_back(*deserializedCharacter);
            }
        }
    }
    return m_parties;
}