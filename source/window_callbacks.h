#ifndef WINDOW_CALLBACKS_H
#define WINDOW_CALLBACKS_H

#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

static void 
window_error_callback(int error, const char *description)
{
    fprintf(stderr, "[%d] %s\n", error, description);
    exit(EXIT_FAILURE);
}

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