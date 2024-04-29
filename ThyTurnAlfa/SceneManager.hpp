#pragma once

#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <array>
#include <chrono>
#include <iostream>
#include <memory>
#include <ranges>
#include <sstream>
#include <string>
#include <thread>
#include <vector>
#include <array>
#include <iostream>
#include <memory>
#include <ranges>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "imgui_internal.h"

#include "Character.hpp"
#include "Const.hpp"
#include "Human.hpp"
#include "PartyPreset.hpp"
#include "PartyType.hpp"
#include "Player.hpp"
#include "ProgramState.hpp"
#include "Queue.hpp"
#include "Random.hpp"
#include "Reader.hpp"
#include "WindowMode.hpp"
 
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

class SceneManager {
	friend void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

	public:
	SceneManager();
	int init();
	int run();
	std::pair<std::string, unsigned int> chooseMove(const unsigned int& id);

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

	// === OPTIONS ===
	std::array<const char*, Const::Sizes::PLAYER_NUMBER> m_availibleFunctions = { "Basic", "NotBasic" };
	int m_curFucIdx = 0;
	int m_treeDepth = 1;

	// === SETUP ===
	std::array<const char*, Const::Sizes::PLAYER_NUMBER> m_availiblePlayers = { "Human", "Random" };
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
	void renderSetup();
	void renderOptions();
	void renderMove(const Message& message, const unsigned int& id);
	int terminate();

	// === IMGUI HELPERS ===
	float renderBegin() const;
	void renderQueue() const;
	void renderPlayerSetup(float x,
						   int* curPlyIdx,
						   int* curPPrIdx,
						   const std::string& num,
						   std::array<int, Const::Sizes::MAX_PARTY_SIZE>& curChrIds);
};
#endif