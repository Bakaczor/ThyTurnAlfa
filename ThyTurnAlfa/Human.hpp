#pragma once

#ifndef HUMAN_H
#define HUMAN_H

#include "Player.hpp"
#include "SceneManager.hpp"

class SceneManager;

class Human : public Player {
	public:
	Human(std::vector<Character>& availibleCharacters, std::array<int, 4>& curChrIds, SceneManager* context);
	virtual std::optional<Message> move(Character& who, std::array<std::unique_ptr<Player>, 2>& players) final;

	private:
	SceneManager* m_context;
};

#endif