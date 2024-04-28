#include "SceneManager.hpp"

#include "stb_image.h"

void SceneManager::renderMenu() {
    float scale = m_height / static_cast<float>(m_fullscreenHeight);
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImVec2(m_width, m_height));
    ImGui::Begin("menu", nullptr,
                 ImGuiWindowFlags_NoMove |
                 ImGuiWindowFlags_NoDecoration |
                 ImGuiWindowFlags_NoTitleBar);

    // =====

    float currScale = 0.9f * scale;
    ImGui::PushFont(m_petitFleur);
    ImGui::SetWindowFontScale(currScale);
    ImGui::SetCursorPosX((ImGui::GetWindowWidth() - ImGui::CalcTextSize("THY TURN").x) * 0.5f);
    ImGui::SetCursorPosY(m_height / 10.0f);
    ImGui::Text("THY TURN");
    ImGui::PopFont();

    // =====

    currScale = 0.5f * scale;
    ImGui::PushFont(m_theCenturion);
    ImGui::SetWindowFontScale(currScale);

    float buttonWidth = m_width / 4.0f;
    float buttonHeight = 1.5f * currScale * m_fontSize;

    ImGui::SetCursorPosX(3 * m_width / 8.0f);
    ImGui::SetCursorPosY(m_height / 2.5f);
    ImGui::BeginGroup();
    ImGuiStyle& style = ImGui::GetStyle();
    ImVec4 prevButtonColor = style.Colors[ImGuiCol_Button];
    style.Colors[ImGuiCol_Button] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
    if (ImGui::Button("START", ImVec2(buttonWidth, buttonHeight))) {
        m_currentState = ProgramState::Setup;
    };
    if (ImGui::Button("OPTIONS", ImVec2(buttonWidth, buttonHeight))) {
        m_currentState = ProgramState::Options;
    };
    if (ImGui::Button("CLOSE", ImVec2(buttonWidth, buttonHeight))) {
        glfwSetWindowShouldClose(m_window, true);
    };
    style.Colors[ImGuiCol_Button] = prevButtonColor;
    ImGui::EndGroup();

    // =====

    ImGui::PopFont();
    ImGui::End();
}

void SceneManager::renderOptions() {
    float scale = m_height / static_cast<float>(m_fullscreenHeight);
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImVec2(m_width, m_height));
    ImGui::Begin("options", nullptr,
                 ImGuiWindowFlags_NoMove |
                 ImGuiWindowFlags_NoDecoration |
                 ImGuiWindowFlags_NoTitleBar);

    // =====

    float currScale = scale;
    ImGui::PushFont(m_theCenturion);
    ImGui::SetWindowFontScale(currScale);
    ImGui::SetCursorPosX((ImGui::GetWindowWidth() - ImGui::CalcTextSize("OPTIONS").x) * 0.5f);
    ImGui::SetCursorPosY(m_height / 10.0f);
    ImGui::Text("OPTIONS");
    ImGui::PopFont();

    // =====

    currScale = 0.2f * scale;
    ImGui::PushFont(m_blackChancery);
    ImGui::SetWindowFontScale(currScale);

    float buttonWidth = m_width / 4.0f;
    float buttonHeight = currScale * m_fontSize;

    ImGui::SetCursorPosX(m_width / 4.0f);
    ImGui::SetCursorPosY(m_height / 2.5f);
    ImGui::BeginGroup();
    ImGui::SetNextItemWidth(1.5f * buttonWidth);
    ImGui::SliderInt(" Tree Depth", &m_treeDepth, 1, 10);

    ImGui::Spacing();

    ImGui::SetNextItemWidth(1.5f * buttonWidth);
    ImGui::Combo(" Evaluation Function", &m_curFucIdx, m_availibleFunctions.data(), m_availibleFunctions.size());
    ImGui::EndGroup();

    // =====

    ImGuiStyle& style = ImGui::GetStyle();
    ImVec4 prevButtonColor = style.Colors[ImGuiCol_Button];
    style.Colors[ImGuiCol_Button] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
    ImGui::SetNextItemWidth(buttonWidth);
    ImGui::SetCursorPosX(3 * m_width / 8.0f);
    ImGui::SetCursorPosY(0.85f * m_height);
    if (ImGui::Button("Back", ImVec2(buttonWidth, buttonHeight))) {
        m_currentState = ProgramState::Menu;
    };
    style.Colors[ImGuiCol_Button] = prevButtonColor;

    // =====
    ImGui::PopFont();
    ImGui::End();
}

void SceneManager::playerOneSetup() {
    ImGui::BeginGroup();
    ImGui::SetCursorPosX(0.2f * m_width-ImGui::CalcTextSize("Player 1").x * 0.5f);
    ImGui::SetCursorPosY(0.4f * m_height);
    ImGui::Text("Player 1");
    ImGui::SetNextItemWidth(m_width / 2.5f);
    ImGui::Combo("##PLAYER1", &m_curPlyIdx_1, m_availiblePlayers.data(), m_availiblePlayers.size());

    ImGui::SetCursorPosX(0.2f * m_width-ImGui::CalcTextSize("Party").x * 0.5f);
    ImGui::Text("Party");

    std::vector<const char*> partyNames(m_partyPresets.size());
    std::transform(m_partyPresets.begin(), m_partyPresets.end(), partyNames.begin(), 
                   [](const PartyPreset& p) { return p.partyName.c_str(); });
    partyNames.push_back("Custom");

    ImGui::SetNextItemWidth(m_width / 2.5f);
    ImGui::Combo("##PARTY1", &m_curPPrIdx_1, partyNames.data(), partyNames.size());

    // the amount of tries I had to spent to get a fucking working vector
    // containing const char* is fucking unmeasurable
    // look at this and tell me that God exists
    std::vector<std::string> strings(m_availibleCharacters.size());
    std::transform(m_availibleCharacters.begin(), m_availibleCharacters.end(),
                   strings.begin(), [](const Character& c) { return c.getName(); });
    std::vector<const char*> characterNames(m_availibleCharacters.size());
    std::transform(strings.begin(), strings.end(),
                   characterNames.begin(), [](const std::string& s) { return s.c_str(); });
    characterNames.push_back(" - ");

    ImGui::SetCursorPosY(0.6f * m_height);
    if (partyNames.at(m_curPPrIdx_1) == "Custom") {
        m_partyType = PartyType::Custom;
        for (int i = 0; i < 4; ++i) {
            ImGui::SetNextItemWidth(m_width / 2.5f);
            ImGui::PushID(i);
            ImGui::Combo("##C1", &(m_curChrIds_1[i]), characterNames.data(), characterNames.size());
            if (i < 3) { ImGui::Spacing(); }
            ImGui::PopID();
        }
    } else {
        m_partyType = PartyType::Preset;
        auto getter = [](void* data, int index, const char** output) {
            std::string* items = (std::string*)data;
            std::string& current = items[index];
            *output = current.c_str();
            return true;
        };
        ImGui::SetNextItemWidth(m_width / 2.5f);
        int a = 0;
        ImGui::ListBox("##CHARACTERS1", &a, getter,
                       m_partyPresets.at(m_curPPrIdx_1).characterNames.data(),
                       m_partyPresets.at(m_curPPrIdx_1).characterNames.size());
    }
    ImGui::EndGroup();
}

void SceneManager::playerTwoSetup() {
    ImGui::BeginGroup();
    ImGui::SetCursorPosX(0.8f * m_width-ImGui::CalcTextSize("Player 2").x * 0.5f);
    ImGui::SetCursorPosY(0.4f * m_height);
    ImGui::Text("Player 2");
    ImGui::SetCursorPosX(0.6f * m_width);
    ImGui::SetNextItemWidth(m_width / 2.5f);
    ImGui::Combo("##PLAYER2", &m_curPlyIdx_2, m_availiblePlayers.data(), m_availiblePlayers.size());

    ImGui::SetCursorPosX(0.8f * m_width-ImGui::CalcTextSize("Party").x * 0.5f);
    ImGui::Text("Party");
    
    std::vector<const char*> partyNames(m_partyPresets.size());
    std::transform(m_partyPresets.begin(), m_partyPresets.end(), partyNames.begin(),
                   [](const auto& p) { return p.partyName.c_str(); });
    partyNames.push_back("Custom");

    ImGui::SetCursorPosX(0.6f * m_width);
    ImGui::SetNextItemWidth(m_width / 2.5f);
    ImGui::Combo("##P2", &m_curPPrIdx_2, partyNames.data(), partyNames.size());

    std::vector<std::string> strings(m_availibleCharacters.size());
    std::transform(m_availibleCharacters.begin(), m_availibleCharacters.end(),
                   strings.begin(), [](const Character& c) { return c.getName(); });
    std::vector<const char*> characterNames(m_availibleCharacters.size());
    std::transform(strings.begin(), strings.end(),
                   characterNames.begin(), [](const std::string& s) { return s.c_str(); });
    characterNames.push_back(" - ");

    ImGui::SetCursorPosY(0.6f * m_height);
    if (partyNames.at(m_curPPrIdx_1) == "Custom") {
        m_partyType = PartyType::Custom;
        for (int i = 0; i < 4; ++i) {
            ImGui::SetNextItemWidth(m_width / 2.5f);
            ImGui::SetCursorPosX(0.6f * m_width);
            ImGui::PushID(i);
            ImGui::Combo("##C2", &(m_curChrIds_2[i]), characterNames.data(), characterNames.size());
            if (i < 3) { ImGui::Spacing(); }
            ImGui::PopID();
        }
    } else {
        m_partyType = PartyType::Preset;
        auto getter = [](void* data, int index, const char** output) {
            std::string* items = (std::string*)data;
            std::string& current = items[index];
            *output = current.c_str();
            return true;
        };
        ImGui::SetNextItemWidth(m_width / 2.5f);
        ImGui::SetCursorPosX(0.6f * m_width);
        int a = 0;
        ImGui::ListBox("##CHARACTERS2", &a, getter,
                       m_partyPresets.at(m_curPPrIdx_2).characterNames.data(),
                       m_partyPresets.at(m_curPPrIdx_2).characterNames.size());
    }
    ImGui::EndGroup();
}

void SceneManager::renderSetup() {
    float scale = m_height / static_cast<float>(m_fullscreenHeight);
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImVec2(m_width, m_height));
    ImGui::Begin("setup", nullptr,
                 ImGuiWindowFlags_NoMove |
                 ImGuiWindowFlags_NoDecoration |
                 ImGuiWindowFlags_NoTitleBar);

    // =====

    float currScale = scale;
    ImGui::PushFont(m_theCenturion);
    ImGui::SetWindowFontScale(currScale);

    ImGui::SetCursorPosX((ImGui::GetWindowWidth() - ImGui::CalcTextSize("SETUP").x) * 0.5f);
    ImGui::SetCursorPosY(m_height / 10.0f);
    ImGui::Text("SETUP");
    ImGui::PopFont();

    // =====

    currScale = 0.2f * scale;
    ImGui::PushFont(m_blackChancery);
    ImGui::SetWindowFontScale(currScale);

    playerOneSetup();
    ImGui::SameLine();
    playerTwoSetup();
    
    // =====

    float buttonWidth = m_width / 4.0f;
    float buttonHeight = 1.2f * currScale * m_fontSize;

    ImGui::SetCursorPosX(3 * m_width / 8.0f);
    ImGui::SetCursorPosY(0.85f * m_height);
    ImGui::BeginGroup();
    ImGuiStyle& style = ImGui::GetStyle();
    ImVec4 prevButtonColor = style.Colors[ImGuiCol_Button];
    style.Colors[ImGuiCol_Button] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
    if (ImGui::Button("Play", ImVec2(buttonWidth, buttonHeight))) {
        m_currentState = ProgramState::Game;
    };
    ImGui::Spacing();
    if (ImGui::Button("Back", ImVec2(buttonWidth, buttonHeight))) {
        m_currentState = ProgramState::Menu;
    };
    style.Colors[ImGuiCol_Button] = prevButtonColor;
    ImGui::EndGroup();

    // =====

    ImGui::PopFont();
    ImGui::End();
}

void SceneManager::renderMove(const Message& message, const unsigned int& id) {
    int i = 0;
    float scale = m_height / static_cast<float>(m_fullscreenHeight);
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImVec2(m_width, m_height));
    ImGui::Begin("game", nullptr,
                 ImGuiWindowFlags_NoMove |
                 ImGuiWindowFlags_NoDecoration |
                 ImGuiWindowFlags_NoTitleBar);
    // ===
    float currScale = 0.2f * scale;
    ImGui::PushFont(m_blackChancery);
    ImGui::SetWindowFontScale(currScale);

    ImVec2 imageSize(90, 90);
    ImGui::Text("NEXT   ");

    i = 0;
    const auto& queue = m_queue.getQueue();
    for (const auto& tuple : queue) {
        ImGui::PushID(i++);
        ImGui::SameLine();
        if (tuple.character->getPlayerId() == 0) {
            ImGui::Image((ImTextureID*)tuple.character->getTextureID(), imageSize,
                         ImVec2(1.0f, 0.0f), ImVec2(0.0f, 1.0f));
        } else {
            ImGui::Image((ImTextureID*)tuple.character->getTextureID(), imageSize);
        }
        ImGui::PopID();
    }

    // Second row: 4 columns
    ImGui::Columns(4, "MyColumns");

    // Column 1
    imageSize = ImVec2(360, 360);
    ImGui::Text("Player 1");
    // there probably should be a better check for this
    {
        std::string search = id == 0 ? message.who : message.onWhom;
        auto& party = m_players.at(id)->party;
        auto it = std::find_if(party.begin(), party.end(), [&search](const Character& c) {
            return search == c.getName();
        });
        ImGui::Image((ImTextureID*)it->getTextureID(), imageSize,
                     ImVec2(1.0f, 0.0f), ImVec2(0.0f, 1.0f));
        i = 0;
        for (const auto& move : it->movements) {
            ImGui::PushID(i++);
            ImGui::Button(move->name.c_str());
            ImGui::PopID();
        }
    }
    
    ImGui::NextColumn();

    imageSize = ImVec2(180, 180);

    // Column 2
    ImGui::Text("Characters of player 1");
    i = 0;
    for (const auto& character : m_players.at(0)->party) {
        ImGui::PushID(i++);
        ImGui::ImageButton((ImTextureID*)character.getTextureID(), imageSize,
                           ImVec2(1.0f, 0.0f), ImVec2(0.0f, 1.0f));
        ImGui::PopID();
    }
    ImGui::NextColumn();

    // Column 3
    ImGui::Text("Characters of player 2");
    i = 0;
    for (const auto& character : m_players.at(1)->party) {
        ImGui::PushID(i++);
        ImGui::ImageButton((ImTextureID*)character.getTextureID(), imageSize);
        ImGui::PopID();
    }
    ImGui::NextColumn();

    // Column 4
    imageSize = ImVec2(360, 360);
    ImGui::Text("Player 2");
    {
        std::string search = id == 1 ? message.who : message.onWhom;
        auto& party = m_players.at(id)->party;
        auto it = std::find_if(party.begin(), party.end(), [&search](const Character& c) {
            return search == c.getName();
        });
        ImGui::Image((ImTextureID*)it->getTextureID(), imageSize);
        i = 0;
        for (const auto& move : it->movements) {
            ImGui::PushID(i++);
            ImGui::Button(move->name.c_str());
            ImGui::PopID();
        }
    }

    ImGui::Columns(1);

    // Third row: 2 columns
    ImGui::Columns(2, "MyColumns2");

    // TODO : display statistics too, not just names

    // Column 1
    ImGui::Text("Characters of player 1");
    i = 0;
    for (const auto& character : m_players.at(0)->party) {
        ImGui::PushID(i++);
        ImGui::Text(character.getName().c_str());
        ImGui::PopID();
    }
    ImGui::NextColumn();

    // Column 2
    ImGui::Text("Characters of player 2");
    i = 0;
    for (const auto& character : m_players.at(1)->party) {
        ImGui::PushID(i++);
        ImGui::Text(character.getName().c_str());
        ImGui::PopID();
    }

    ImGui::Columns(1);

    // End the ImGui window
    ImGui::PopFont();
    ImGui::End();
}