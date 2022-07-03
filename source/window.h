#ifndef WINDOW_H
#define WINDOW_H

#include <stdlib.h>
#include <string.h>
#include "window_data.h"
#include "window_callbacks.h"

/**
 * @brief Initializes the window.
 * 
 * @param window_data   Make sure to pass a reference to an empty window_data_t
 * fields will be initialized with default values in this function.
 */
static void 
window_initialize(window_data_t *window_data)
{
    int is_initialized = glfwInit();
    if (is_initialized == 0) return;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

    glfwSetErrorCallback(window_error_callback);

    window_data->name = (char*)malloc(sizeof(char*));
    strcpy(window_data->name, "Rugpjutis");

    window_data->width      = 1024;
    window_data->height     = 768;

    g_window = glfwCreateWindow(
        window_data->width,
        window_data->height, 
        window_data->name, 
        NULL, NULL);

    const GLFWvidmode *video_mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    window_data->refresh_rate = video_mode->refreshRate;

    glfwSetKeyCallback(g_window, window_key_callback);
    glfwMakeContextCurrent(g_window);
    glfwSwapInterval(1);
}

/**
 * @brief Disposes of all data allocated on the heap for window initialization.
 * 
 * @param window_data A pointer to the window_data_t structure used to 
 * initialize the window.
 */
static void 
window_terminate(window_data_t *window_data)
{
    glfwDestroyWindow(g_window);
    glfwTerminate();
    free(window_data->name);
}

/**
 * @brief Runs the windows render loop.
 */
static void
window_run_loop()
{
    // Possible optimization here
    while (!glfwWindowShouldClose(g_window))
    {
        glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glfwSwapBuffers(g_window);
        glfwPollEvents();
    }
}

#endif