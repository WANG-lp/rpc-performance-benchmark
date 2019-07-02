#include <string>
#include <vector>
#include <zmq.hpp>
#include "ZeroMQService.hpp"

int main() {
    ZeroMQServer server;
    while (server.getListenPort() == 0) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    printf("listen on: %d\n", server.getListenPort());
    server.serve();
    return 0;
}