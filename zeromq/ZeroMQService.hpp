#pragma once

#include <string>
#include <thread>
#include <vector>
#include <zmq.hpp>

#define MAX_LEN 128 * 1024 * 1024
using std::string;
using std::vector;

class ZeroMQServer {
   public:
    explicit ZeroMQServer(int num_threads) : context(16), clients(context, ZMQ_ROUTER) {
        for (size_t i = 0; i < MAX_LEN; i++) {
            random_data.push_back(i % 255);
        }
        //  Prepare our context and sockets
        clients.bind("tcp://*:8080");
        workers = zmq::socket_t(context, ZMQ_DEALER);
        workers.bind("inproc://workers");
        for (int i = 0; i < num_threads; i++) {
            worker_tids.push_back(std::thread(&ZeroMQServer::worker_routine, this, (void *) &context));
        }
    }
    ~ZeroMQServer() {
        for (auto &t : worker_tids) {
            t.join();
        }
    }
    void serve() { zmq::proxy(static_cast<void *>(clients), static_cast<void *>(workers), nullptr); }

    void stop() {
        workers.close();
        clients.close();
        context.close();
    }

   private:
    void worker_routine(void *arg) {
        zmq::context_t *context = (zmq::context_t *) arg;

        zmq::socket_t socket(*context, ZMQ_REP);
        socket.connect("inproc://workers");
        zmq::message_t reply;
        while (true) {
            zmq::message_t request;
            //  Wait for next request from client
            socket.recv(&request);
            size_t len = std::atoll((const char *) request.data());
            // printf("recv readmsg: %d\n", len);
            assert(len > 0 && len < MAX_LEN);
            //  Send reply back to client
            if (reply.size() == 0) {
                reply = zmq::message_t(len);
                memcpy((void *) reply.data(), random_data.data(), len);
            }
            socket.send(reply, zmq::send_flags::dontwait);
        }
    }
    vector<std::thread> worker_tids;
    zmq::context_t context;
    zmq::socket_t clients;
    zmq::socket_t workers;
    vector<char> random_data;
};

class ZeroMQClient {
   public:
    explicit ZeroMQClient(const string &serverURI) : context(1), socket(context, ZMQ_REQ) { socket.connect(serverURI); }
    ~ZeroMQClient() {
        socket.close();
        context.close();
    }
    zmq::message_t readMsg(size_t len) {
        string len_str = std::to_string(len);
        zmq::message_t msg(len_str.c_str(), len_str.size() + 1);  // remember to add ending null byte
        socket.send(msg, zmq::send_flags::dontwait);
        zmq::message_t reply;
        socket.recv(&reply);
        // printf("recv len: %d\n", reply.size());
        return reply;
    }

    void close() {
        socket.close();
        context.close();
    }

   private:
    zmq::context_t context;
    zmq::socket_t socket;
};
