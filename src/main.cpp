#include <GLFW/glfw3.h>
#include <stdio.h>

#include "gfx/window.hpp"
#include "utils/utils.hpp"

using namespace global;

int main(void) {
    if (!glfwInit()) {
        utils::_throw("Failure", "Failed to initialize GLFW");
        return -1;
    }

    global::init_settings();

    gfx::window_t window("Project", settings.window_size);
    window.init();

    // Main loop: poll for events until the user closes the window
    while (window.is_open()) {
        glfwPollEvents();
    }

    window.kill();  // Clean up resources
    return 0;
}