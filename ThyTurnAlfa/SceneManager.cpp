#include "SceneManager.hpp"

#include <iostream>
#include <ranges>
#include <sstream>

#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "Reader.hpp"
#include "Random.hpp"
#include "Human.hpp"
#include "AI.hpp"

int SceneManager::init() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);

    m_monitor = glfwGetPrimaryMonitor();
    glfwGetMonitorWorkarea(m_monitor, nullptr, nullptr, &m_fullscreenWidth, &m_fullscreenHeight);
    m_width = m_fullscreenWidth;
    m_height = m_fullscreenHeight;

    m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);
    if (m_window == nullptr) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return 1;
    }
    glfwMakeContextCurrent(m_window);
    glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);
    glfwSetKeyCallback(m_window, key_callback);
    glfwSetWindowUserPointer(m_window, this);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return 1;
    }

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    m_fontSize = m_width / 10;
    m_petitFleur = io.Fonts->AddFontFromFileTTF("fonts/PetitFleur.ttf", m_fontSize);
    m_theCenturion = io.Fonts->AddFontFromFileTTF("fonts/TheCenturion.ttf", m_fontSize);
    m_blackChancery = io.Fonts->AddFontFromFileTTF("fonts/BlackChancery.ttf", m_fontSize);
    ImGui_ImplGlfw_InitForOpenGL(m_window, true);
    ImGui_ImplOpenGL3_Init();

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    return arrange();
}

int SceneManager::arrange() {
    // === CONFIG ===
    Reader reader;
    if (!reader.readFile("appsettings.json")) {
        return 1;
    }
    m_availibleCharacters = reader.extractCharacters();
    m_partyPresets = reader.extractParties();

    return 0;
}

void SceneManager::setupGame() {
    // TODO : setup algorithm options
    // PS : this function could use loops if I didn't have separate members for indices


    // for custom it is already set in GUI
    if (m_partyType == PartyType::Preset) {
        auto view = m_availibleCharacters | std::views::transform([](const Character& c) {
            return c.getName();
        });
        // player 1
        PartyPreset& preset1 = m_partyPresets.at(m_curPPrIdx_1);
        int i1 = 0;
        for (const std::string& name : preset1.characterNames) {
            auto it = std::find(view.begin(), view.end(), name);
            if (it != view.end()) {
                m_curChrIds_1[i1] = static_cast<int>(std::distance(view.begin(), it));
            }
            i1++;
        }
        // player 2
        PartyPreset& preset2 = m_partyPresets.at(m_curPPrIdx_2);
        int i2 = 0;
        for (const std::string& name : preset1.characterNames) {
            auto it = std::find(view.begin(), view.end(), name);
            if (it != view.end()) {
                m_curChrIds_2[i2] = static_cast<int>(std::distance(view.begin(), it));
            }
            i2++;
        }
    }
    // player 1
    if (m_availiblePlayers.at(m_curPlyIdx_1) == "Human") {
        m_players[0] = std::make_unique<Human>(m_availibleCharacters, m_curChrIds_1, this);
    } else if (m_availiblePlayers.at(m_curPlyIdx_1) == "Random") {
        m_players[0] = std::make_unique<Random>(m_availibleCharacters, m_curChrIds_1);
    } else {
        m_players[0] = std::make_unique<AI>(m_availibleCharacters, m_curChrIds_1, m_treeDepth, &m_queue);
    }
    // player 2
    if (m_availiblePlayers.at(m_curPlyIdx_2) == "Human") {
        m_players[1] = std::make_unique<Human>(m_availibleCharacters, m_curChrIds_2, this);
    } else if (m_availiblePlayers.at(m_curPlyIdx_2) == "Random") {
        m_players[1] = std::make_unique<Random>(m_availibleCharacters, m_curChrIds_2);
    } else {
        m_players[1] = std::make_unique<AI>(m_availibleCharacters, m_curChrIds_1, m_treeDepth, &m_queue);
    }
}

void SceneManager::resetSetup() {
    Player::count = 0;
    m_curPlyIdx_1 = 0;
    m_curPlyIdx_2 = 0;
    m_curPPrIdx_1 = 0;
    m_curPPrIdx_2 = 0;
    m_curChrIds_1 = { -1, -1, -1, -1 };
    m_curChrIds_2 = { -1, -1, -1, -1 };
    m_partyType = PartyType::Custom;

    // reset characters
    for (auto& character : m_availibleCharacters) {
        character.reset();
    }
}

int SceneManager::run() {
    while (!glfwWindowShouldClose(m_window)) {
        switch (m_currentState) {
            case ProgramState::Menu: {
                m_gameStart = true;
                newFrame();
                renderMenu();
                renderNewFrame();
                break; 
            }
            case ProgramState::Options: {
                newFrame();
                renderOptions();
                renderNewFrame();
                break;
            }
            case ProgramState::Setup: {
                newFrame();
                renderSetup();
                renderNewFrame();
                break;
            }
            case ProgramState::Game: {
                if (m_gameStart) {
                    m_gameStart = false;
                    newFrame();
                    setupGame();
                    renderNewFrame();
                    m_queue = Queue(m_players);
                    for (const auto& player : m_players) {
                        for (auto& character : player->party) {
                            character.loadDmgEstimationTable(m_players);
                        }
                    }
                }
                unsigned int winner = playerWon();
                if (-1 != winner) {
                    m_currentState = ProgramState::Menu;
                    resetSetup();
                    renderWinner(winner);
                    break;
                }
                Character& character = m_queue.peek();
                unsigned int id = character.getPlayerId();
                auto it = std::find_if(m_players.begin(), m_players.end(), [&id](const auto& p) {
                    return p->id == id;
                });
                std::optional<Message> message = ((*it)->move(character, m_players));
                if (m_currentState != ProgramState::Game) { break; }
                if (!message.has_value()) {
                    message = Message{ character.getName(), "unavailible moves", "everyone 10 times :<" };
                } 
                renderMove(character, message.value(), id);
                break;
            }
        }
    }
    return terminate();
}

int SceneManager::playerWon() const {
    for (int i = 0; i < m_players.size(); i++) {
        bool alive = false;
        for (const Character& c : m_players.at(i)->party) {
            if (c.isAlive) {
                alive = true;
                break;
            }
        }
        if (!alive) {
            return m_players.at((i + 1) % m_players.size())->id;
        }
    }
    return -1;
}

int SceneManager::terminate() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwTerminate();
    return 0;
}
