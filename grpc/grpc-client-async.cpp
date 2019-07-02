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
using grpc::ClientAsyncResponseReader;
using grpc::ClientContext;
using grpc::CompletionQueue;
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
    explicit EchoClient(std::shared_ptr<Channel> channel)
            : stub_(Echo::NewStub(channel)) {}

    // Assembles the client's payload, sends it and presents the response back
    // from the server.
    std::string echo(const std::string& user) {
        // Data we are sending to the server.
        Req request;
        request.set_message(user);

        // Container for the data we expect from the server.
        Rep reply;

        // Context for the client. It could be used to convey extra information to
        // the server and/or tweak certain RPC behaviors.
        ClientContext context;

        // The producer-consumer queue we use to communicate asynchronously with the
        // gRPC runtime.
        CompletionQueue cq;

        // Storage for the status of the RPC upon completion.
        Status status;

        // stub_->PrepareAsyncSayHello() creates an RPC object, returning
        // an instance to store in "call" but does not actually start the RPC
        // Because we are using the asynchronous API, we need to hold on to
        // the "call" instance in order to get updates on the ongoing RPC.
        std::unique_ptr<ClientAsyncResponseReader<Rep> > rpc(
                stub_->PrepareAsyncecho(&context, request, &cq));

        // StartCall initiates the RPC call
        rpc->StartCall();

        // Request that, upon completion of the RPC, "reply" be updated with the
        // server's response; "status" with the indication of whether the operation
        // was successful. Tag the request with the integer 1.
        rpc->Finish(&reply, &status, (void*)1);
        void* got_tag;
        bool ok = false;
        // Block until the next result is available in the completion queue "cq".
        // The return value of Next should always be checked. This return value
        // tells us whether there is any kind of event or the cq_ is shutting down.
        GPR_ASSERT(cq.Next(&got_tag, &ok));

        // Verify that the result from "cq" corresponds, by its tag, our previous
        // request.
        GPR_ASSERT(got_tag == (void*)1);
        // ... and that the request was completed successfully. Note that "ok"
        // corresponds solely to the request for updates introduced by Finish().
        GPR_ASSERT(ok);

        // Act upon the status of the actual RPC.
        if (status.ok()) {
            return reply.message();
        } else {
            return "RPC failed";
        }
    }

private:
    // Out of the passed in Channel comes the stub, stored here, our view of the
    // server's exposed services.
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