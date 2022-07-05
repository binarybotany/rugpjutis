#ifndef WINDOW_DATA_H
#define WINDOW_DATA_H

#include <GLFW/glfw3.h>

typedef struct window_data_t
{
    GLFWwindow *window;
    GLchar     *name;
    GLsizei     width;
    GLsizei     height;
    GLint       refresh_rate;
} window_data_t;

#endif