#include "window.h"

int main(int argc, char **argv)
{
    window_create(&window_data, 1024, 768, GL_FALSE);
    window_run_loop(&window_data);
    window_destroy(&window_data);

    return (0);
}