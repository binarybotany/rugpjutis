#include "window.h"

int main(int argc, char **argv)
{
    window_data_t window_data;
    
    window_initialize(&window_data);
    window_run_loop();
    window_terminate(&window_data);

    return (0);
}