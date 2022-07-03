#ifndef WINDOW_DATA_H
#define WINDOW_DATA_H

#include <GLFW/glfw3.h>

static GLFWwindow *g_window;

/**
 * @brief Contains the most generic window data.
 */
typedef struct window_data_t
{
    char    *name;          /* Name displayed in the window */ 
    int     width,          /* Width of the window          */
            height,         /* Height of the window         */
            refresh_rate;   /* Window refresh rate          */
} window_data_t;

#endif