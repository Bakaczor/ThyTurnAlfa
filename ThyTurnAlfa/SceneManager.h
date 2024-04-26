#pragma once

#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <array>
#include <iostream>
#include <map>
#include <ranges>
#include <ranges>
#include <sstream>
#include <string>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "ProgramState.hpp"
#include "Queue.hpp"
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
	unsigned m_roundsCount = 0;
	ProgramState m_currentState = ProgramState::Menu;
	std::vector<Player> m_players;
	Queue m_queue;
	//Character& m_currentCharacter;

	// === OPTIONS ===
	std::array<const char*, 2> m_functions = { "Basic", "NotBasic" };
	int m_currFuncIndex = 0;
	int m_treeDepth = 1;

	// === SETUP ===
	std::vector<Character> m_availibleCharacters;
	std::vector<std::vector<std::string>> m_partyPresets;

	int arrange();
	void renderMenu();
	void renderSetup();
	void renderOptions();
	void renderGame();
	int terminate();
};
#endif