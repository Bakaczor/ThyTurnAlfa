#include <iostream>

#include "SceneManager.hpp"

int main() {
    try {
        SceneManager scene;
        if (0 == scene.init()) {
            return scene.run();
        }
    } catch (std::exception& e) {
        std::cerr << e.what();
    }
    return 1;
}

