#include "SceneManager.hpp"

#include "stb_image.h"

float SceneManager::renderBegin() const {
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImVec2(m_width, m_height));
    ImGui::Begin("window", nullptr,
                 ImGuiWindowFlags_NoMove |
                 ImGuiWindowFlags_NoDecoration |
                 ImGuiWindowFlags_NoTitleBar);
    return m_height / static_cast<float>(m_fullscreenHeight);
}

void SceneManager::renderMenu() {
    float scale = renderBegin();

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
    float scale = renderBegin();

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

void SceneManager::renderPlayerSetup(float x,
                                     int* curPlyIdx,
                                     int* curPPrIdx,
                                     const std::string& num,
                                     std::array<int, Const::Sizes::MAX_PARTY_SIZE>& curChrIds) {
    ImGui::BeginGroup();
    ImGui::SetCursorPosX(x * m_width-ImGui::CalcTextSize("Player 2").x * 0.5f);
    ImGui::SetCursorPosY(0.4f * m_height);
    ImGui::Text(("Player " + num).c_str());
    if (num == "2") {
        ImGui::SetCursorPosX(0.6f * m_width);
    }
    ImGui::SetNextItemWidth(m_width / 2.5f);
    ImGui::Combo(("##PLAYER" + num).c_str(), curPlyIdx,
                 m_availiblePlayers.data(), m_availiblePlayers.size());

    ImGui::SetCursorPosX(x * m_width-ImGui::CalcTextSize("Party").x * 0.5f);
    ImGui::Text("Party");
    
    std::vector<const char*> partyNames(m_partyPresets.size());
    std::transform(m_partyPresets.begin(), m_partyPresets.end(), partyNames.begin(),
                   [](const auto& p) { return p.partyName.c_str(); });
    partyNames.push_back("Custom");

    if (num == "2") {
        ImGui::SetCursorPosX(0.6f * m_width);
    }
    ImGui::SetNextItemWidth(m_width / 2.5f);
    ImGui::Combo(("##PARTY" + num).c_str(), curPPrIdx, partyNames.data(), partyNames.size());

    std::vector<std::string> strings(m_availibleCharacters.size());
    std::transform(m_availibleCharacters.begin(), m_availibleCharacters.end(),
                   strings.begin(), [](const Character& c) { return c.getName(); });
    std::vector<const char*> characterNames(m_availibleCharacters.size());
    std::transform(strings.begin(), strings.end(),
                   characterNames.begin(), [](const std::string& s) { return s.c_str(); });
    characterNames.push_back(" - ");

    ImGui::SetCursorPosY(0.6f * m_height);
    if (partyNames.at(*curPPrIdx) == "Custom") {
        m_partyType = PartyType::Custom;
        for (int i = 0; i < Const::Sizes::MAX_PARTY_SIZE; i++) {
            ImGui::PushID(i);
            ImGui::SetNextItemWidth(m_width / 2.5f);
            if (num == "2") {
                ImGui::SetCursorPosX(0.6f * m_width);
            }
            ImGui::Combo(("##CHARACTERS" + num).c_str(), &(curChrIds[i]),
                         characterNames.data(), characterNames.size());
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
        if (num == "2") {
            ImGui::SetCursorPosX(0.6f * m_width);
        }
        int a = 0;
        ImGui::ListBox(("##CHARACTERS" + num).c_str(), &a, getter,
                       m_partyPresets.at(*curPPrIdx).characterNames.data(),
                       m_partyPresets.at(*curPPrIdx).characterNames.size());
    }
    ImGui::EndGroup();
}

void SceneManager::renderSetup() {
    float scale = renderBegin();

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

    renderPlayerSetup(0.2f, &m_curPlyIdx_1, &m_curPPrIdx_1, "1", m_curChrIds_1);
    ImGui::SameLine();
    renderPlayerSetup(0.8f, &m_curPlyIdx_2, &m_curPPrIdx_2, "2", m_curChrIds_2);
    
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

void SceneManager::renderQueue() const {
    ImVec2 imageSize(90, 90);
    ImGui::Text("NEXT   ");
    int i = 0;
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
}

void SceneManager::renderMove(const Message& message, const unsigned int& id) {
    ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);
    int i = 0;
    float scale = renderBegin();

    // ===
    float currScale = 0.2f * scale;
    ImGui::PushFont(m_blackChancery);
    ImGui::SetWindowFontScale(currScale);
    renderQueue();

    // Second row: 4 columns
    ImGui::Columns(4, "MyColumns", false);

    // Column 1
    ImVec2 imageSize = ImVec2(360, 360);
    ImGui::Text("Player 1");
    // there probably should be a better check for this
    if (id == 0) {
        auto& party = m_players.at(0)->party;
        auto it = std::find_if(party.begin(), party.end(), [&message](const Character& c) {
            return message.who == c.getName();
        });
        ImGui::Image((ImTextureID*)it->getTextureID(), imageSize,
                     ImVec2(1.0f, 0.0f), ImVec2(0.0f, 1.0f));
        ImGui::Text(it->getName().c_str());
        i = 0;
        ImGui::SetCursorPosY(0.45f * m_height);
        for (const auto& move : it->movements) {
            ImGui::PushID(i++);
            ImGui::Button(move->name.c_str());
            ImGui::Spacing();
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
        ImGui::SameLine();
        ImGui::Text(character.getName().c_str());
        ImGui::PopID();
    }
    ImGui::NextColumn();

    // Column 3
    ImGui::Text("Characters of player 2");
    i = 0;
    for (const auto& character : m_players.at(1)->party) {
        ImGui::PushID(i++);
        ImGui::ImageButton((ImTextureID*)character.getTextureID(), imageSize);
        ImGui::SameLine();
        ImGui::Text(character.getName().c_str());
        ImGui::PopID();
    }
    ImGui::NextColumn();

    // Column 4
    imageSize = ImVec2(360, 360);
    ImGui::Text("Player 2");
    if (id == 1) {
        auto& party = m_players.at(1)->party;
        auto it = std::find_if(party.begin(), party.end(), [&message](const Character& c) {
            return message.who == c.getName();
        });
        ImGui::Image((ImTextureID*)it->getTextureID(), imageSize);
        ImGui::Text(it->getName().c_str());
        i = 0;
        ImGui::SetCursorPosY(0.45f * m_height);
        for (const auto& move : it->movements) {
            ImGui::PushID(i++);
            ImGui::Button(move->name.c_str());
            ImGui::Spacing();
            ImGui::PopID();
        }
    }

    ImGui::Columns(1);

    // Third row: 2 columns
    ImGui::Columns(2, "MyColumns2", false);

    // Column 1
    ImGui::SetCursorPosY(0.7f * m_height);
    ImGui::Text("Characters of player 1");
    ImGui::Spacing();
    i = 0;
    for (const auto& character : m_players.at(0)->party) {
        ImGui::PushID(i++);
        ImGui::Text(character.getName().c_str());
        ImGui::SameLine();
        ImGui::Text(("HP: " + std::to_string(character.getHp())).c_str());
        ImGui::SameLine();
        ImGui::Text(("MP: " + std::to_string(character.getMp())).c_str());
        ImGui::Spacing();
        ImGui::PopID();
    }
    ImGui::NextColumn();

    // Column 2
    ImGui::SetCursorPosY(0.7f * m_height);
    ImGui::Text("Characters of player 2");
    ImGui::Spacing();
    i = 0;
    for (const auto& character : m_players.at(1)->party) {
        ImGui::PushID(i++);
        ImGui::Text(character.getName().c_str());
        ImGui::SameLine();
        ImGui::Text(("HP: " + std::to_string(character.getHp())).c_str());
        ImGui::SameLine();
        ImGui::Text(("MP: " + std::to_string(character.getMp())).c_str());
        ImGui::Spacing();
        ImGui::PopID();
    }

    ImGui::Columns(1);

    // End the ImGui window
    ImGui::PopFont();
    ImGui::End();
    ImGui::PopItemFlag();
}

void SceneManager::renderPopUp(const Message& message, const unsigned int& id) {
    bool close = false;
    std::string msg = message.who + " used " + message.what + " on " + message.onWhom;
    float currScale = 0.2f * m_height / static_cast<float>(m_fullscreenHeight);

    while (!close) {
        newFrame();
        renderMove(message, id);

        ImGui::PushFont(m_blackChancery);
        ImGui::SetWindowFontScale(currScale);

        ImGui::SetNextWindowPos(ImVec2(3 * m_width / 8.0f, 3 * m_height / 8.0f));

        ImGui::OpenPopup("MyPopup");
        if (ImGui::BeginPopupModal("MyPopup", nullptr,
                                   ImGuiWindowFlags_NoDecoration |
                                   ImGuiWindowFlags_NoTitleBar | 
                                   ImGuiWindowFlags_AlwaysAutoResize)) {
            ImGui::Text(msg.c_str());
            float size = ImGui::CalcTextSize(msg.c_str()).x;
            ImGui::PushFont(m_theCenturion);
            if (ImGui::Button("OK", ImVec2(size, m_height / 16.0f))) {
                close = true;
                ImGui::CloseCurrentPopup();
            }
            ImGui::PopFont();
            ImGui::EndPopup();
        }
        ImGui::PopFont();
        renderNewFrame();
    }
}

std::tuple<std::string, unsigned int, bool> SceneManager::chooseMove(Character& who) {
    std::string what;
    bool setWhat = false;
    unsigned int onWhom;
    bool setOnWhom = false;
    int i = 0;
    bool aborted = false;

    do {
        if (m_currentState != ProgramState::Game) {
            aborted = true;
            break; 
        }
        newFrame();
        float scale = renderBegin();

        // ===
        float currScale = 0.2f * scale;
        ImGui::PushFont(m_blackChancery);
        ImGui::SetWindowFontScale(currScale);
        renderQueue();

        // Second row: 4 columns
        ImGui::Columns(4, "MyColumns", false);

        // Column 1
        ImVec2 imageSize = ImVec2(360, 360);
        ImGui::Text("Player 1");
        // there probably should be a better check for this
        if (who.getPlayerId() == 0) {
            auto& party = m_players.at(0)->party;
            auto it = std::find_if(party.begin(), party.end(), [&who](const Character& c) {
                return who.getName() == c.getName();
            });
            ImGui::Image((ImTextureID*)it->getTextureID(), imageSize,
                         ImVec2(1.0f, 0.0f), ImVec2(0.0f, 1.0f));
            ImGui::Text(it->getName().c_str());
            i = 0;
            ImGui::SetCursorPosY(0.45f * m_height);
            for (const auto& move : it->movements) {
                ImGui::PushID(i++);
                if (ImGui::Button(move->name.c_str())) {
                    what = move->name;
                    setWhat = true;
                }
                ImGui::Spacing();
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
            if (ImGui::ImageButton((ImTextureID*)character.getTextureID(), imageSize,
                                   ImVec2(1.0f, 0.0f), ImVec2(0.0f, 1.0f))) {
                onWhom = character.id;
                setOnWhom = true;
            }
            ImGui::SameLine();
            ImGui::Text(character.getName().c_str());
            ImGui::PopID();
        }
        ImGui::NextColumn();

        // Column 3
        ImGui::Text("Characters of player 2");
        i = 0;
        for (const auto& character : m_players.at(1)->party) {
            ImGui::PushID(Const::Sizes::MAX_PARTY_SIZE + i++);
            if (ImGui::ImageButton((ImTextureID*)character.getTextureID(), imageSize)) {
                onWhom = character.id;
                setOnWhom = true;
            }
            ImGui::SameLine();
            ImGui::Text(character.getName().c_str());
            ImGui::PopID();
        }
        ImGui::NextColumn();

        // Column 4
        imageSize = ImVec2(360, 360);
        ImGui::Text("Player 2");
        if (who.getPlayerId() == 1) {
            auto& party = m_players.at(1)->party;
            auto it = std::find_if(party.begin(), party.end(), [&who](const Character& c) {
                return who.getName() == c.getName();
            });
            ImGui::Image((ImTextureID*)it->getTextureID(), imageSize);
            ImGui::Text(it->getName().c_str());
            i = 0;
            ImGui::SetCursorPosY(0.45f * m_height);
            for (const auto& move : it->movements) {
                ImGui::PushID(Const::Sizes::MAX_PARTY_SIZE +  i++);
                if (ImGui::Button(move->name.c_str())) {
                    what = move->name;
                    setWhat = true;
                }
                ImGui::Spacing();
                ImGui::PopID();
            }
        }

        ImGui::Columns(1);

        // Third row: 2 columns
        ImGui::Columns(2, "MyColumns2", false);

        // Column 1
        ImGui::SetCursorPosY(0.7f * m_height);
        ImGui::Text("Characters of player 1");
        ImGui::Spacing();
        i = 0;
        for (const auto& character : m_players.at(0)->party) {
            ImGui::PushID(i++);
            ImGui::Text(character.getName().c_str());
            ImGui::SameLine();
            ImGui::Text(("HP: " + std::to_string(character.getHp())).c_str());
            ImGui::SameLine();
            ImGui::Text(("MP: " + std::to_string(character.getMp())).c_str());
            ImGui::Spacing();
            ImGui::PopID();
        }
        ImGui::NextColumn();

        // Column 2
        ImGui::SetCursorPosY(0.7f * m_height);
        ImGui::Text("Characters of player 2");
        ImGui::Spacing();
        i = 0;
        for (const auto& character : m_players.at(1)->party) {
            ImGui::PushID(i++);
            ImGui::Text(character.getName().c_str());
            ImGui::SameLine();
            ImGui::Text(("HP: " + std::to_string(character.getHp())).c_str());
            ImGui::SameLine();
            ImGui::Text(("MP: " + std::to_string(character.getMp())).c_str());
            ImGui::Spacing();
            ImGui::PopID();
        }

        ImGui::Columns(1);

        // End the ImGui window
        ImGui::PopFont();
        ImGui::End();
        renderNewFrame();
    } while (!setWhat || !setOnWhom);
    return std::make_tuple(what, onWhom, aborted);
}

void SceneManager::newFrame() {
    std::ostringstream ss;
    ss << "[";
    ss.precision(0);
    ss << std::fixed << ImGui::GetIO().Framerate;
    ss << " FPS] " << m_title;
    glfwSetWindowTitle(m_window, ss.str().c_str());

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void SceneManager::renderNewFrame() {
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    glfwSwapBuffers(m_window);
    glfwPollEvents();
}