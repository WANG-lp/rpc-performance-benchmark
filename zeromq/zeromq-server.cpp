#include <string>
#include <vector>
#include <zmq.hpp>
#include "ZeroMQService.hpp"

int main() {
    ZeroMQServer server(16);
    server.serve();
    return 0;
}