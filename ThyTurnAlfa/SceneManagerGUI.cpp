#include "SceneManager.h"

bool stringTableGetter(void* data, int index, const char** output) {
    std::string* function = static_cast<std::string*>(data);
    std::string& currentFunction = function[index];
    *output = currentFunction.c_str();
    return true;
}

void SceneManager::renderMenu() {
    float scale = m_height / static_cast<float>(m_fullscreenHeight);
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImVec2(m_width, m_height));
    ImGui::Begin("menu", nullptr,
                 ImGuiWindowFlags_NoMove |
                 ImGuiWindowFlags_NoDecoration |
                 ImGuiWindowFlags_NoTitleBar);
    ImGui::PushFont(m_petitFleur);
    float currScale = 0.9f * scale;
    ImGui::SetWindowFontScale(currScale);

    ImGui::SetCursorPosX((ImGui::GetWindowWidth() - ImGui::CalcTextSize("THY TURN").x) * 0.5f);
    ImGui::SetCursorPosY(m_height / 10.0f);
    ImGui::Text("THY TURN");

    ImGui::PopFont();
    ImGui::End();

    ImGui::SetNextWindowPos(ImVec2(3 * m_width / 8, m_height / 2.5f));
    float windowWidth = m_width / 4.0f;
    ImGui::SetNextWindowSize(ImVec2(windowWidth, m_height));
    ImGui::Begin("buttons", nullptr,
                 ImGuiWindowFlags_NoMove |
                 ImGuiWindowFlags_NoDecoration |
                 ImGuiWindowFlags_NoTitleBar |
                 ImGuiWindowFlags_NoBackground);
    ImGui::SetWindowFocus();
    ImGui::PushFont(m_theCenturion);
    currScale = 0.5f * scale;
    ImGui::SetWindowFontScale(currScale);

    ImGuiStyle& style = ImGui::GetStyle();
    ImVec4 prevButtonColor = style.Colors[ImGuiCol_Button];
    style.Colors[ImGuiCol_Button] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
    float buttonHeight = 1.5f * currScale * m_fontSize;
    if (ImGui::Button("START", ImVec2(windowWidth, buttonHeight))) {
        m_currentState = ProgramState::Setup;
    };
    if (ImGui::Button("OPTIONS", ImVec2(windowWidth, buttonHeight))) {
        m_currentState = ProgramState::Options;
    };
    if (ImGui::Button("CLOSE", ImVec2(windowWidth, buttonHeight))) {
        glfwSetWindowShouldClose(m_window, true);
    };
    style.Colors[ImGuiCol_Button] = prevButtonColor;

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
    ImGui::PushFont(m_theCenturion);
    float currScale = scale;
    ImGui::SetWindowFontScale(currScale);

    ImGui::SetCursorPosX((ImGui::GetWindowWidth() - ImGui::CalcTextSize("OPTIONS").x) * 0.5f);
    ImGui::SetCursorPosY(m_height / 10.0f);
    ImGui::Text("OPTIONS");

    ImGui::PopFont();
    ImGui::End();

    ImGui::SetNextWindowPos(ImVec2(m_width / 4, m_height / 2.5f));
    float windowWidth = m_width / 2.0f;
    ImGui::SetNextWindowSize(ImVec2(windowWidth, m_height));
    ImGui::Begin("buttons", nullptr,
                 ImGuiWindowFlags_NoMove |
                 ImGuiWindowFlags_NoDecoration |
                 ImGuiWindowFlags_NoTitleBar |
                 ImGuiWindowFlags_NoBackground);
    ImGui::SetWindowFocus();
    ImGui::PushFont(m_blackChancery);
    currScale = 0.2f * scale;
    ImGui::SetWindowFontScale(currScale);
    if (ImGui::TreeNode("Tree Depth")) {
        ImGui::SliderInt("##1", &m_treeDepth, 1, 10);
        ImGui::TreePop();
    }
    ImGui::Spacing();
    if (ImGui::TreeNode("Evaluation Function")) {
        auto v = std::views::values(m_functions);
        std::vector<std::string> values(v.begin(), v.end());
        ImGui::ListBox("##2", &m_currFuncIndex, stringTableGetter, values.data(), values.size());
        ImGui::TreePop();
    }
    ImGui::Spacing();
    ImGuiStyle& style = ImGui::GetStyle();
    ImVec4 prevButtonColor = style.Colors[ImGuiCol_Button];
    style.Colors[ImGuiCol_Button] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
    if (ImGui::Button("Back", ImVec2(windowWidth, currScale * m_fontSize))) {
        m_currentState = ProgramState::Menu;
    };
    style.Colors[ImGuiCol_Button] = prevButtonColor;
    ImGui::PopFont();
    ImGui::End();
}
void SceneManager::renderSetup() {
    float scale = m_height / static_cast<float>(m_fullscreenHeight);
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImVec2(m_width, m_height));
    ImGui::Begin("setup", nullptr,
                 ImGuiWindowFlags_NoMove |
                 ImGuiWindowFlags_NoDecoration |
                 ImGuiWindowFlags_NoTitleBar);
    ImGui::PushFont(m_theCenturion);
    float currScale = scale;
    ImGui::SetWindowFontScale(currScale);

    ImGui::SetCursorPosX((ImGui::GetWindowWidth() - ImGui::CalcTextSize("SETUP").x) * 0.5f);
    ImGui::SetCursorPosY(m_height / 10.0f);
    ImGui::Text("SETUP");

    ImGui::PopFont();
    ImGui::End();

    ImGui::PushFont(m_blackChancery);
    currScale = 0.2f * scale;
    float windowWidth = m_width / 2.0f;

    ImGui::SetNextWindowPos(ImVec2(0, m_height / 2.5f));
    ImGui::SetNextWindowSize(ImVec2(windowWidth, m_height / 2.0f));
    ImGui::Begin("party1", nullptr,
                 ImGuiWindowFlags_NoMove |
                 ImGuiWindowFlags_NoDecoration |
                 ImGuiWindowFlags_NoTitleBar |
                 ImGuiWindowFlags_NoBackground);
    ImGui::SetWindowFontScale(currScale);
    ImGui::SetCursorPosX((ImGui::GetWindowWidth() - ImGui::CalcTextSize("Player 1").x) * 0.5f);
    ImGui::Text("Player 1");
    if (ImGui::TreeNode("##1", "Party")) {
        ImGui::TreePop();
    }
    ImGui::End();

    ImGui::SetNextWindowPos(ImVec2(windowWidth, m_height / 2.5f));
    ImGui::SetNextWindowSize(ImVec2(windowWidth, m_height / 2.0f));
    ImGui::Begin("party2", nullptr,
                 ImGuiWindowFlags_NoMove |
                 ImGuiWindowFlags_NoDecoration |
                 ImGuiWindowFlags_NoTitleBar |
                 ImGuiWindowFlags_NoBackground);
    ImGui::SetWindowFontScale(currScale);
    ImGui::SetCursorPosX((ImGui::GetWindowWidth() - ImGui::CalcTextSize("Player 2").x) * 0.5f);
    ImGui::Text("Player 2");
    if (ImGui::TreeNode("##1", "Party")) {
        ImGui::TreePop();
    }
    ImGui::End();

    windowWidth = windowWidth / 2;
    ImGui::SetNextWindowPos(ImVec2(3 * m_width / 8, 0.85f * m_height));
    ImGui::SetNextWindowSize(ImVec2(windowWidth, m_height / 10.0f));
    ImGui::Begin("buttons", nullptr,
                 ImGuiWindowFlags_NoMove |
                 ImGuiWindowFlags_NoDecoration |
                 ImGuiWindowFlags_NoTitleBar |
                 ImGuiWindowFlags_NoBackground);
    ImGui::SetWindowFocus();
    ImGui::SetWindowFontScale(currScale);
    float buttonHeight = 1.2f * currScale * m_fontSize;
    ImGuiStyle& style = ImGui::GetStyle();
    ImVec4 prevButtonColor = style.Colors[ImGuiCol_Button];
    style.Colors[ImGuiCol_Button] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
    if (ImGui::Button("Play", ImVec2(windowWidth, buttonHeight))) {
        m_currentState = ProgramState::Game;
    };
    ImGui::Spacing();
    if (ImGui::Button("Back", ImVec2(windowWidth, buttonHeight))) {
        m_currentState = ProgramState::Menu;
    };
    style.Colors[ImGuiCol_Button] = prevButtonColor;
    ImGui::End();
    ImGui::PopFont();
}

void renderGame() {
    // TODO
}