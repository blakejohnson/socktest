#include <unistd.h>

extern "C" {
    int32_t set_socket(int fd);
    int32_t get_socket();
    int32_t write_something();
}