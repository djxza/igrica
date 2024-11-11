#pragma once

#include <string>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "global/global.hpp"
#include "utils/utils.hpp"

namespace gfx
{
    class window_t {
        using handle_t = GLFWwindow*;
        using monitor_t = GLFWmonitor*;

        private:
            handle_t handle;
            
            monitor_t *monitors, monitor;
            glm::u16vec2 size;
            glm::i16vec2 pos;
            std::string title;

        public:
            window_t(
                const std::string& title,
                const glm::u16vec2 size);

            // this function will throw if window fails to open
            void init();

            bool is_open() const;

            void kill();
    };
} // namespace gfx
