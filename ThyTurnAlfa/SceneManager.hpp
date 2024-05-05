#pragma once

#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <array>
#include <memory>
#include <string>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "imgui.h"

#include "Character.hpp"
#include "Choice.hpp"
#include "Const.hpp"
#include "PartyPreset.hpp"
#include "PartyType.hpp"
#include "Player.hpp"
#include "ProgramState.hpp"
#include "Queue.hpp"
#include "WindowMode.hpp"
 
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

class SceneManager {
	friend void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

	public:
	int init();
	int run();
	std::tuple<std::string, unsigned int, bool> chooseMove(Character& who);

	private:
	// === WINDOW ===
	GLFWwindow* m_window = nullptr;
	GLFWmonitor* m_monitor = nullptr;
	WindowMode m_mode = WindowMode::Windowed;
	ImFont* m_petitFleur = nullptr;
	ImFont* m_theCenturion = nullptr;
	ImFont* m_blackChancery = nullptr;
	int m_fontSize = 0;
	std::string m_title;
	int m_fullscreenWidth = 0;
	int m_fullscreenHeight = 0;
	int m_width = 0;
	int m_height = 0;

	// === GAME ===
	bool m_gameStart = true;
	ProgramState m_currentState = ProgramState::Menu;
	std::array<std::unique_ptr<Player>, Const::Sizes::PLAYER_NUMBER> m_players;
	std::vector<Character> m_availibleCharacters;
	Queue m_queue;

	void applyEffects();

	// === OPTIONS ===
	std::array<const char*, Const::Sizes::PLAYER_NUMBER> m_availibleFunctions = { "Basic", "NotBasic" };
	int m_curFucIdx = 0;
	int m_treeDepth = 5;

	// === SETUP ===
	std::array<const char*, Const::Sizes::NUM_OF_PLAYER_TYPES> m_availiblePlayers = { "Human", "Random", "AI" };
	int m_curPlyIdx_1 = 0;
	int m_curPlyIdx_2 = 0;
	std::vector<PartyPreset> m_partyPresets;
	int m_curPPrIdx_1 = 0;
	int m_curPPrIdx_2 = 0;
	PartyType m_curPtTp_1 = PartyType::Custom;
	PartyType m_curPtTp_2 = PartyType::Custom;
	std::array<int, Const::Sizes::MAX_PARTY_SIZE> m_curChrIds_1 = { -1, -1, -1, -1 };
	std::array<int, Const::Sizes::MAX_PARTY_SIZE> m_curChrIds_2 = { -1, -1, -1, -1 };

	int arrange();
	void setupGame();
	void resetSetup();
	void renderMenu();
	void renderSetup();
	void renderOptions();
	void renderMove(const Character& who, const Message& message, const unsigned int& id);
	std::optional<Choice> renderBackground(const std::string& who, const unsigned int& id, bool lock);
	int playerWon() const;
	void renderWinner(unsigned int& who);
	int terminate();

	// === IMGUI HELPERS ===
	void newFrame();
	void renderNewFrame();
	float renderBegin() const;
	void renderQueue() const;
	void renderPlayerSetup(float x,
						   int* curPlyIdx,
						   int* curPPrIdx,
						   PartyType& curPtTp,
						   const std::string& num,
						   std::array<int, Const::Sizes::MAX_PARTY_SIZE>& curChrIds);
};
#endif