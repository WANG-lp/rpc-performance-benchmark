#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include <grpcpp/grpcpp.h>
#include "gen/echo.grpc.pb.h"
#include "gen/echo.pb.h"

using echo::Echo;
using echo::Rep;
using echo::Req;
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using std::string;
using std::vector;
#define MAX_LEN 128 * 1024 * 1024
vector<char> random_text;
class EchoImpl final : public Echo::Service {
    Status echo(ServerContext* context, const Req* req, Rep* rep) override {
        rep->set_message(req->message());
        return Status::OK;
    }
    Status read(ServerContext* context, const ::echo::ReqLen* request, ::echo::Rep* response) {
        int32_t len = request->message();
        assert(len < MAX_LEN);
        response->set_message(string(random_text.begin(), random_text.begin() + len));
        return Status::OK;
    }
};
void RunServer() {
    for (int i = 0; i < MAX_LEN; i++) {  // 128MB random buffer
        random_text.push_back(i % 255);
    }
    std::string server_address("0.0.0.0:8080");
    EchoImpl service;

    ServerBuilder builder;
    // Listen on the given address without any authentication mechanism.
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    // Register "service" as the instance through which we'll communicate with
    // clients. In this case it corresponds to an *synchronous* service.
    builder.RegisterService(&service);
    builder.SetSyncServerOption(grpc::ServerBuilder::SyncServerOption::MAX_POLLERS, 32);
    // builder.SetSyncServerOption(grpc::ServerBuilder::SyncServerOption::MIN_POLLERS, 32);
    builder.SetSyncServerOption(grpc::ServerBuilder::SyncServerOption::NUM_CQS, 16);

    // Finally assemble the server.
    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;

    // Wait for the server to shutdown. Note that some other thread must be
    // responsible for shutting down the server for this call to ever return.
    server->Wait();
}
int main() {
    RunServer();
    return 0;
}