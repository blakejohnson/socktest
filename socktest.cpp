#include <sys/socket.h>

#include "socktest.h"

int my_socket = -1;

int32_t set_socket(int fd) {
    my_socket = fd;
    return 0;
}

int32_t get_socket() {
    return my_socket;
}

int32_t write_something() {
    return write(my_socket, "hello", 6);
}
