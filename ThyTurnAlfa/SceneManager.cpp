#include "SceneManager.h"

SceneManager::SceneManager(): m_title("Thy Turn v1.0 Alpha") { }

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
    // TODO : read config data, creating state and queue etc.

    return 0;
}

int SceneManager::run() {
    while (!glfwWindowShouldClose(m_window)) {
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
        switch (m_currentState) {
            case ProgramState::Menu: {
                m_roundsCount = 0;
                renderMenu();
                break; 
            }
            case ProgramState::Options: {
                renderOptions();
                break;
            }
            case ProgramState::Setup: {
                renderSetup();
                break;
            }
            case ProgramState::Game: {
                if (m_roundsCount == 0) {
                    //m_queue = Queue(m_players);
                }
                // m_currentCharacter = m_queue.pop() ?
                renderGame();
                // m_roundsCount++;
                break;
            }
        }
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }
    return terminate();
}

int SceneManager::terminate() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwTerminate();
    return 0;
}
