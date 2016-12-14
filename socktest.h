#include <stdint.h>

// to compile:
// gcc -c -fpic socktest.cpp
// gcc -shared -o libsocket.dll socktest.o -lws2_32 (windows)
// or
// gcc -shared -o libsocket.dylib socktest.o (macOS)

extern "C" {
    int32_t set_socket(int fd);
    int32_t get_socket();
    int32_t write_something();
    int32_t send_something();
}
