#include "SceneManager.h"

#include "stb_image.h"

void SceneManager::renderMenu() {
    float scale = m_height / static_cast<float>(m_fullscreenHeight);
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImVec2(m_width, m_height));
    ImGui::Begin("menu", nullptr,
                 ImGuiWindowFlags_NoMove |
                 ImGuiWindowFlags_NoDecoration |
                 ImGuiWindowFlags_NoTitleBar);
    // ===
    float currScale = 0.9f * scale;
    ImGui::PushFont(m_petitFleur);
    ImGui::SetWindowFontScale(currScale);
    ImGui::SetCursorPosX((ImGui::GetWindowWidth() - ImGui::CalcTextSize("THY TURN").x) * 0.5f);
    ImGui::SetCursorPosY(m_height / 10.0f);
    ImGui::Text("THY TURN");
    ImGui::PopFont();
    // ===
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
    // ===
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
    // ===
    float currScale = scale;
    ImGui::PushFont(m_theCenturion);
    ImGui::SetWindowFontScale(currScale);
    ImGui::SetCursorPosX((ImGui::GetWindowWidth() - ImGui::CalcTextSize("OPTIONS").x) * 0.5f);
    ImGui::SetCursorPosY(m_height / 10.0f);
    ImGui::Text("OPTIONS");
    ImGui::PopFont();
    // ===
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
    ImGui::Combo(" Evaluation Function", &m_currFuncIndex, m_functions.data(), m_functions.size());
    ImGui::EndGroup();
    // ===
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
    // ===
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
    // ===
    float currScale = scale;
    ImGui::PushFont(m_theCenturion);
    ImGui::SetWindowFontScale(currScale);

    ImGui::SetCursorPosX((ImGui::GetWindowWidth() - ImGui::CalcTextSize("SETUP").x) * 0.5f);
    ImGui::SetCursorPosY(m_height / 10.0f);
    ImGui::Text("SETUP");
    ImGui::PopFont();
    // ===
    currScale = 0.2f * scale;
    ImGui::PushFont(m_blackChancery);
    ImGui::SetWindowFontScale(currScale);

    ImGui::BeginGroup();
    ImGui::SetCursorPosX(0.2f * m_width - ImGui::CalcTextSize("Player 1").x * 0.5f);
    ImGui::SetCursorPosY(0.4f * m_height);
    ImGui::Text("Player 1");

    ImGui::SetCursorPosX(0.01f * m_width);
    ImGui::SetCursorPosY(0.45f * m_height);
    ImGui::Text("Party", "1");
    // TODO : real presets
    const char* items[] = { "Custom", "Konosuba", "Lord of the Rings", "Final Fantasy VII" };
    static int item_current1 = 0;
    ImGui::SetNextItemWidth(m_width / 2.5f);
    ImGui::Combo("##P1", &item_current1, items, IM_ARRAYSIZE(items));

    ImGui::SetCursorPosY(0.6f * m_height);
    for (int i = 0; i < 4; ++i) {
        ImGui::SetNextItemWidth(m_width / 2.5f);
        // TODO : real characters
        ImGui::PushID(i);
        if (ImGui::BeginCombo("##C1", "Select an option##1")) {
            ImGui::Text("Option 1");
            ImGui::Text("Option 2");
            ImGui::Text("Option 3");
            ImGui::EndCombo();
        }
        if (i < 3) {
            ImGui::Spacing();
        }
        ImGui::PopID();
    }
    ImGui::EndGroup();
    
    ImGui::SameLine();

    ImGui::BeginGroup();
    ImGui::SetCursorPosX(0.8f * m_width - ImGui::CalcTextSize("Player 2").x * 0.5f);
    ImGui::SetCursorPosY(0.4f * m_height);
    ImGui::Text("Player 2");

    ImGui::SetCursorPosX(0.61f * m_width);
    ImGui::SetCursorPosY(0.45f * m_height);
    ImGui::Text("Party", "2");
    static int item_current2 = 0;
    ImGui::SetCursorPosX(0.6f * m_width);
    ImGui::SetNextItemWidth(m_width / 2.5f);
    ImGui::Combo("##P2", &item_current2, items, IM_ARRAYSIZE(items));

    ImGui::SetCursorPosY(0.6f * m_height);
    for (int i = 0; i < 4; ++i) {
        ImGui::SetNextItemWidth(m_width / 2.5f);
        ImGui::SetCursorPosX(0.6f * m_width);
        // TODO : real characters
        ImGui::PushID(i);
        if (ImGui::BeginCombo("##C2", "Select an option##1")) {
            ImGui::Text("Option 1");
            ImGui::Text("Option 2");
            ImGui::Text("Option 3");
            ImGui::EndCombo();
        }
        if (i < 3) {
            ImGui::Spacing();
        }
        ImGui::PopID();
    }
    ImGui::EndGroup();
    // ===
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
    // ===
    ImGui::PopFont();
    ImGui::End();
}

void SceneManager::renderGame() {
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

    // TODO : This is just a preview
    // This is how to load images
    // I think the image should be loaded while creating character and the textureID should be stored in character class

    unsigned int textureID;
    glGenTextures(1, &textureID);
    int width, height, nrComponents;
    unsigned char* data = stbi_load("images/megumin.png", &width, &height, &nrComponents, 0);
    if (data) {
        GLenum format;
        if (nrComponents == 1) {
            format = GL_RED;
        } else if (nrComponents == 3) {
            format = GL_RGB;
        } else if (nrComponents == 4) {
            format = GL_RGBA;
        }

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    stbi_image_free(data);

    ImVec2 imageSize(90, 90);

    ImGui::Text("NEXT   ");
    ImGui::SameLine();
    ImGui::Image((ImTextureID*)textureID, imageSize);
    ImGui::SameLine();
    ImGui::Image((ImTextureID*)textureID, imageSize);
    ImGui::SameLine();
    ImGui::Image((ImTextureID*)textureID, imageSize);
    ImGui::SameLine();
    ImGui::Image((ImTextureID*)textureID, imageSize);

    // Second row: 4 columns
    ImGui::Columns(4, "MyColumns");

    imageSize = ImVec2(360, 360);

    // Column 1
    ImGui::Text("Player 1");
    ImGui::Image((ImTextureID*)textureID, imageSize, ImVec2(1.0f, 0.0f), ImVec2(0.0f, 1.0f));
    ImGui::Button("Move 1##1");
    ImGui::Button("Move 2##1");
    ImGui::Button("Move 3##1");
    ImGui::NextColumn();

    imageSize = ImVec2(180, 180);

    // Column 2
    ImGui::Text("Characters of player 1");
    ImGui::ImageButton((ImTextureID*)textureID, imageSize, ImVec2(1.0f, 0.0f), ImVec2(0.0f, 1.0f));
    ImGui::ImageButton((ImTextureID*)textureID, imageSize, ImVec2(1.0f, 0.0f), ImVec2(0.0f, 1.0f));
    ImGui::ImageButton((ImTextureID*)textureID, imageSize, ImVec2(1.0f, 0.0f), ImVec2(0.0f, 1.0f));
    ImGui::ImageButton((ImTextureID*)textureID, imageSize, ImVec2(1.0f, 0.0f), ImVec2(0.0f, 1.0f));
    ImGui::NextColumn();

    // Column 3
    ImGui::Text("Characters of player 2");
    ImGui::ImageButton((ImTextureID*)textureID, imageSize);
    ImGui::ImageButton((ImTextureID*)textureID, imageSize);
    ImGui::ImageButton((ImTextureID*)textureID, imageSize);
    ImGui::ImageButton((ImTextureID*)textureID, imageSize);
    ImGui::NextColumn();

    // Column 4
    ImGui::Text("Player 2");
    imageSize = ImVec2(360, 360);
    ImGui::Image((ImTextureID*)textureID, imageSize);
    ImGui::Button("Move 1##2");
    ImGui::Button("Move 2##2");
    ImGui::Button("Move 3##2");

    ImGui::Columns(1);

    // Third row: 2 columns
    ImGui::Columns(2, "MyColumns2");

    // Column 1
    ImGui::Text("Characters of player 1");
    ImGui::Text("Character 1");
    ImGui::Text("Character 2");
    ImGui::Text("Character 3");
    ImGui::Text("Character 4");
    ImGui::NextColumn();

    // Column 2
    ImGui::Text("Characters of player 2");
    ImGui::Text("Character 1");
    ImGui::Text("Character 2");
    ImGui::Text("Character 3");
    ImGui::Text("Character 4");

    ImGui::Columns(1);

    // End the ImGui window
    ImGui::PopFont();
    ImGui::End();
}