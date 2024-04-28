#pragma once

#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <array>
#include <string>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "imgui.h"

#include "Player.h"
#include "Character.hpp"
#include "Human.hpp"
#include "PartyPreset.hpp"
#include "PartyType.hpp"
#include "Player.hpp"
#include "ProgramState.hpp"
#include "Queue.hpp"
#include "WindowMode.hpp"
#include "Const.hpp"
 
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

class SceneManager {
	friend void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

	public:
	SceneManager();
	int init();
	int run();

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
	std::array<std::unique_ptr<Player>, 2> m_players;
	std::vector<Character> m_availibleCharacters;
	Queue m_queue;

	// === OPTIONS ===
	std::array<const char*, 2> m_availibleFunctions = { "Basic", "NotBasic" };
	int m_curFucIdx = 0;
	int m_treeDepth = 1;

	// === SETUP ===
	std::array<const char*, 2> m_availiblePlayers = { "Human", "Random" };
	int m_curPlyIdx_1 = 0;
	int m_curPlyIdx_2 = 0;
	std::vector<PartyPreset> m_partyPresets;
	int m_curPPrIdx_1 = 0;
	int m_curPPrIdx_2 = 0;
	PartyType m_partyType = PartyType::Custom;
	std::array<int, Const::Sizes::MAX_PARTY_SIZE> m_curChrIds_1 = { -1, -1, -1, -1 };
	std::array<int, Const::Sizes::MAX_PARTY_SIZE> m_curChrIds_2 = { -1, -1, -1, -1 };

	int arrange();
	void setupGame();
	void resetSetup();
	void renderMenu();
	void playerOneSetup();
	void playerTwoSetup();
	void renderSetup();
	void renderOptions();
	void renderGame();
	int terminate();
};
#endif