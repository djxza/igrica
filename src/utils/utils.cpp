#include "utils.hpp"

void utils::_throw(
    const std::string& title,
    const std::string& msg) {
        MessageBoxA(
            NULL,               // Handle to the owner window, NULL if no owner
            msg.c_str(), // Message text
            title.c_str(),            // Title of the message box
            MB_OK | MB_ICONERROR // Message box type: OK button and exclamation icon
        );

    std::exit(EXIT_FAILURE);
}