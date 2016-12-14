#include <stdint.h>

// to compile:
// gcc -fpic -shared -o libsocket.dll -lws2_32 socktest.cpp (windows)
// or
// clang -fpic -shared -o libsocket.dylib socktest.cpp (macOS)

extern "C" {
    int32_t set_socket(int fd);
    int32_t get_socket();
    int32_t write_something();
    int32_t send_something();
}
