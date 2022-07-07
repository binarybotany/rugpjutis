#ifndef WINDOW_DATA_H
#define WINDOW_DATA_H

#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct window_data_t
{
    GLFWwindow         *window;
    const GLchar       *name;
    GLsizei             width;
    GLsizei             height;
    GLint               refresh_rate;
} window_data_t;

static struct window_data_t window_data;
static const GLchar *window_name = "Rugpjutis";

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

static void 
window_create(window_data_t *window_data,
              GLsizei width, 
              GLsizei height, 
              GLboolean fullscreen)
{
    int is_initialized = glfwInit();
    if (is_initialized == 0) return;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

    glfwSetErrorCallback(window_error_callback);

    window_data->width       = width;
    window_data->height      = height;
    window_data->name        = window_name;

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
window_destroy(window_data_t *window_data)
{
    glfwDestroyWindow(window_data->window);
    glfwTerminate();
}

static void
window_run_loop(window_data_t *window_data)
{
    while (!glfwWindowShouldClose(window_data->window))
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glColor3f(1.0f, 1.0f, 0.0f);
        glRectf(0.0f, 0.0f, 2.0f, 2.0f);

        glfwSwapBuffers(window_data->window);
        glfwPollEvents();
    }
}

#endif