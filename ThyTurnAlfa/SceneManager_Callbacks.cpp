#include "SceneManager.hpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);

    SceneManager* context = static_cast<SceneManager*>(glfwGetWindowUserPointer(window));
    context->m_width = width;
    context->m_height = height;

    if (width || height) {
        if (context->m_gameIsPaused) {
            context->resumeAudio();
            context->m_gameIsPaused = false;
        }
    } else {
        if (!context->m_gameIsPaused) {
            context->pauseAudio();
            context->m_gameIsPaused = true;
        }

    }
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action != GLFW_PRESS) { return; }
    SceneManager* context = static_cast<SceneManager*>(glfwGetWindowUserPointer(window));

    switch (key) {
        case GLFW_KEY_ESCAPE: {
            context->m_currentState = ProgramState::Menu;
            context->resetSetup();
            break;
        }
        case GLFW_KEY_TAB: {
            if (mods & GLFW_MOD_CONTROL) {
                const GLFWvidmode* mode = glfwGetVideoMode(context->m_monitor);
                if (context->m_mode == WindowMode::Fullscreen) {
                    context->m_mode = WindowMode::Windowed;
                    glfwSetWindowMonitor(window, nullptr, 200, 200,
                                         mode->width / 2, mode->height / 2, GLFW_DONT_CARE);
                } else {
                    context->m_mode = WindowMode::Fullscreen;
                    glfwSetWindowMonitor(window, context->m_monitor, 0, 0,
                                         mode->width, mode->height, mode->refreshRate);
                }
            }
            break;
        }
    }
}