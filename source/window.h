#ifndef WINDOW_H
#define WINDOW_H

#include <stdlib.h>
#include <string.h>
#include "window_data.h"
#include "window_callbacks.h"

static void 
window_initialize(window_data_t *window_data, 
                  const GLchar *name,
                  GLsizei width, 
                  GLsizei height, 
                  GLboolean fullscreen)
{
    int is_initialized = glfwInit();
    if (is_initialized == 0) return;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

    glfwSetErrorCallback(window_error_callback);

    window_data->name = (GLchar*)malloc(sizeof(GLchar*));
    strcpy(window_data->name, name);

    window_data->width      = width;
    window_data->height     = height;

    window_data->window = glfwCreateWindow(
        window_data->width,
        window_data->height, 
        window_data->name, 
        fullscreen ? glfwGetPrimaryMonitor() : NULL, 
        NULL);

    const GLFWvidmode *video_mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    window_data->refresh_rate = video_mode->refreshRate;

    glfwSetKeyCallback(window_data->window, window_key_callback);
    glfwMakeContextCurrent(window_data->window);
    glfwSwapInterval(1);
}

static void 
window_terminate(window_data_t *window_data)
{
    glfwDestroyWindow(window_data->window);
    glfwTerminate();
    free(window_data->name);
}

static void
window_run_loop(window_data_t *window_data)
{
    while (!glfwWindowShouldClose(window_data->window))
    {
        glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glfwSwapBuffers(window_data->window);
        glfwPollEvents();
    }
}

#endif