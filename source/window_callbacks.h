#ifndef WINDOW_CALLBACKS_H
#define WINDOW_CALLBACKS_H

#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Callback called by GLFW on error.
 * 
 * @param error         An error code.
 * @param description   The error message.
 */
static void 
window_error_callback(int error, const char *description)
{
    fprintf(stderr, "[%d] %s\n", error, description);
    exit(EXIT_FAILURE);
}

/**
 * @brief Callback called by GLFW on key.
 * 
 * @param window    A pointer to a GLFWwindow.
 * @param key       The key pressed.
 * @param scancode  The platform-specific scancode.
 * @param action    Whether the key is pressed, released, etc.
 * @param mods      A possible modifier key.
 */
static void
window_key_callback(GLFWwindow* window, 
                    int key, 
                    int scancode, 
                    int action, 
                    int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

#endif