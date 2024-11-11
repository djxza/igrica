#include "window.hpp"
#include <GLFW/glfw3.h> // Ensure GLFW is included

using namespace global;

gfx::window_t::window_t(const std::string& title, const glm::u16vec2 size) {
    this->size = size;
    this->title = title;
    this->pos = { -1, -1 }; // Initialize default position values
}

void gfx::window_t::init() {
        // GLFW error callback to diagnose issues
    glfwSetErrorCallback([](int error, const char* description) {
        utils::_throw(
            "Error",
            std::string(
                "glfw error " + error
                + std::string("; glfw says ")
                + description));
    });


    glfwDefaultWindowHints(); // Call this first to reset hints
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);  // Vulkan compatibility
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    // Get monitor info
    int num_monitors;
    this->monitors = glfwGetMonitors(&num_monitors);
    if (settings.monitor_index >= num_monitors) {
        utils::_throw("Failure", "Monitor index out of range");
    } else {
        this->monitor = monitors[settings.monitor_index];
    }

    const GLFWvidmode* video_mode = glfwGetVideoMode(monitor);
    glm::ivec2 monitor_pos;
    glfwGetMonitorPos(monitor, &monitor_pos.x, &monitor_pos.y);

    // Create the window
    this->handle = glfwCreateWindow(
        this->size.x,
        this->size.y,
        this->title.c_str(),
        nullptr,
        nullptr
    );

    if (!this->handle) {
        utils::_throw("Failure", "Failed to initialize window!");
    }

    // Set window position to center if default values are used
    if (this->pos.x == -1) {
        this->pos.x = monitor_pos.x + (video_mode->width - this->size.x) / 2;
    }
    if (this->pos.y == -1) {
        this->pos.y = monitor_pos.y + (video_mode->height - this->size.y) / 2;
    }

    glfwSetWindowPos(this->handle, this->pos.x, this->pos.y);
    glfwSetWindowUserPointer(this->handle, this);

    // Show the window
    glfwShowWindow(this->handle);
}

bool gfx::window_t::is_open() const {
    return !glfwWindowShouldClose(this->handle);
}

void gfx::window_t::kill() {
    glfwDestroyWindow(this->handle);
    glfwTerminate();  // Cleanly terminate GLFW
}