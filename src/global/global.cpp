#include "global/global.hpp"

void global::init_settings() {
    if(!settings.vsync_enabled) {
        /* vsync enabled by default */
        glfwSwapInterval(0);
    }
}