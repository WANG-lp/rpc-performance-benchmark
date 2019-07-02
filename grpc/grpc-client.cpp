#include <sys/time.h>
#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#include "gen/echo.grpc.pb.h"


using echo::Echo;
using echo::Rep;
using echo::Req;
using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using std::string;

int64_t get_wall_time() {
    struct timeval time;
    if (gettimeofday(&time, NULL)) {
        //  Handle error
        return 0;
    }
    return time.tv_sec * 1000000 + time.tv_usec;
}

class EchoClient {
   public:
    EchoClient(std::shared_ptr<Channel> channel) : stub_(Echo::NewStub(channel)) {}

    // Assembles the client's payload, sends it and presents the response back
    // from the server.
    std::string echo(const std::string& msg) {
        // Data we are sending to the server.
        Req request;
        request.set_message(msg);

        // Container for the data we expect from the server.
        Rep reply;

        // Context for the client. It could be used to convey extra information to
        // the server and/or tweak certain RPC behaviors.
        ClientContext context;

        // The actual RPC.
        Status status = stub_->echo(&context, request, &reply);

        // Act upon its status.
        if (status.ok()) {
            return reply.message();
        } else {
            std::cout << status.error_code() << ": " << status.error_message() << std::endl;
            return "RPC failed";
        }
    }

   private:
    std::unique_ptr<Echo::Stub> stub_;
};

int main(int argc, char** argv) {
    EchoClient client(grpc::CreateChannel("127.0.0.1:8080", grpc::InsecureChannelCredentials()));

    size_t buff_size = 4 * 1024;
    size_t REQNUM = 500000;
    if (argc == 3) {
        buff_size = std::atoll(argv[1]);
        REQNUM = std::atoll(argv[2]);
    }
    printf("buff size is %ld\n", buff_size);
    printf("req num is %ld\n", REQNUM);
    string buff(buff_size, 'x');

    int64_t start_time = get_wall_time();
    for (size_t i = 0; i < REQNUM; i++) {
        auto ret = client.echo(buff);
        // printf("ret: %d, buf: %.*s\n", ret, (int) out_length, out_buf);
        if (ret.size() != buff.size()) {
            printf("error");
        }
    }
    int64_t end_time = get_wall_time();

    double total_time_in_ms = (end_time - start_time) / 1000.0;

    printf("Requests: %ld, Total time: %.3lfms, qps: %.3f\n", REQNUM, total_time_in_ms,
           ((double) REQNUM / (total_time_in_ms / 1000.0)));

    return 0;
}