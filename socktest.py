import asyncio
from socket import socketpair
from cffi import FFI

ffi = FFI()
ffi.cdef("""
    int32_t set_socket(int fd);
    int32_t get_socket();
    int32_t write_something();
    int32_t send_something();
""")
lib = ffi.dlopen("libsocktest.dll")

rs, ws = socketpair()
lib.set_socket(ws.fileno())

loop = asyncio.get_event_loop()

def reader():
    msg = rs.recv(100).decode()
    print(msg)
    loop.remove_reader(rs)
    loop.stop()

loop.add_reader(rs, reader)
loop.call_soon(lib.send_something)
loop.run_forever()

rs.close()
ws.close()
loop.close()
