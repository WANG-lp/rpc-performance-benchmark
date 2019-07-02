#pragma once

#include <string>
#include <thread>
#include <vector>
#include <zmq.hpp>

using std::string;
using std::vector;

class ZeroMQServer {
   public:
    explicit ZeroMQServer() : context(1), clients(context, ZMQ_REP) { clients.bind("tcp://*:8080"); }
    int serve() {
        while (1) {
            zmq::message_t request;
            bool recv_ok;
            try {
                recv_ok = clients.recv(&request);
            } catch (zmq::error_t &e) {
                break;
            }
            if (!recv_ok) {
                continue;
            }
            clients.send(request);
        }
        return 0;
    }

    void stop() {
        clients.close();
        context.close();
    }

    int getListenPort() {
        char port[1024];
        size_t size = sizeof(port);
        clients.getsockopt(ZMQ_LAST_ENDPOINT, &port, &size);
        string uri(port, size);
        if (uri.rfind(':') == string::npos) {
            return 0;
        }
        return std::strtol(uri.substr(uri.rfind(':') + 1, string::npos).c_str(), nullptr, 10);
    }

   private:
    zmq::context_t context;
    zmq::socket_t clients;
};

class ZeroMQClient {
   public:
    explicit ZeroMQClient(const string &serverURI) : context(1), socket(context, ZMQ_REQ) { socket.connect(serverURI); }
    zmq::message_t sendMsg(zmq::message_t &message) {
        socket.send(message);
        //  Get the reply.
        zmq::message_t reply;
        socket.recv(&reply);
        return reply;
    }

    void close() {
        socket.close();
        context.close();
    }

    ~ZeroMQClient() = default;

   private:
    zmq::context_t context;
    zmq::socket_t socket;
};
