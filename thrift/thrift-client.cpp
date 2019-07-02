#include <thrift/concurrency/PosixThreadFactory.h>
#include <thrift/concurrency/ThreadManager.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TThreadPoolServer.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/transport/TSocket.h>
#include <string>
#include "gen-cpp/Echo.h"

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;
using std::string;
using namespace ::Echo;

int64_t get_wall_time() {
    struct timeval time;
    if (gettimeofday(&time, NULL)) {
        //  Handle error
        return 0;
    }
    return time.tv_sec * 1000000 + time.tv_usec;
}
int main(int argc, char **argv) {
    std::shared_ptr<::TSocket> socket;
    std::shared_ptr<::TTransport> transport;
    std::shared_ptr<::TProtocol> protocol;
    std::shared_ptr<Echo::EchoClient> client;
    socket = std::make_shared<::TSocket>("127.0.0.1", 8080);
    transport = std::shared_ptr<::TTransport>(new ::TFramedTransport(socket));
    protocol = std::shared_ptr<::TProtocol>(new ::TBinaryProtocol(transport));
    client = std::make_shared<Echo::EchoClient>(protocol);
    transport->open();

    size_t buff_size = 4 * 1024;
    size_t REQNUM = 500000;
    if (argc == 3) {
        buff_size = std::atoll(argv[1]);
        REQNUM = std::atoll(argv[2]);
    }
    printf("buff size is %ld\n", buff_size);
    printf("req num is %ld\n", REQNUM);
    string buff(buff_size, 'x');

    string ret_buff;
    int64_t start_time = get_wall_time();
    for (size_t i = 0; i < REQNUM; i++) {
        client->echo(ret_buff, buff);
        // printf("ret: %d, buf: %.*s\n", ret, (int) out_length, out_buf);
        if (ret_buff.size() != buff.size()) {
            printf("error");
        }
    }
    int64_t end_time = get_wall_time();

    double total_time_in_ms = (end_time - start_time) / 1000.0;

    printf("Requests: %ld, Total time: %.3lfms, qps: %.3f\n", REQNUM, total_time_in_ms, ((double) REQNUM / (total_time_in_ms / 1000.0)));
    return 0;
}