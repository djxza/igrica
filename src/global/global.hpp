#pragma once

#include <string>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "utils/utils.hpp"

namespace global {
    struct settings_t {
        glm::u16vec2 window_size;
        int monitor_index;
        bool vsync_enabled;
    };

    void init_settings();

    inline constexpr const settings_t settings = {{1280, 720}};
}