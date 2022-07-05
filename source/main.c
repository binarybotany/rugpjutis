#include "window.h"

int main(int argc, char **argv)
{
    window_data_t window_data;
    window_initialize(&window_data, "Rugpjutis", 1024, 768, GL_FALSE);
    window_run_loop(&window_data);
    window_terminate(&window_data);

    return (0);
}