#pragma once
#include <iostream>
#include <json/json.h>

#ifndef CHARACTER_H
#define CHARACTER_H

class Character {
public:
	void Deserialize(Json::Value& root);
	std::string getName() {
		return m_name;
	}
private:
	std::string m_name;
	int m_SPD = -1;
	bool m_isAlive = true;
};

#endif