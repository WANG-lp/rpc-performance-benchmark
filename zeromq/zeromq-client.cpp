#include <sys/time.h>
#include <string>
#include <vector>
#include <zmq.hpp>
#include "ZeroMQService.hpp"
using std::string;
using std::vector;

int64_t get_wall_time() {
    struct timeval time;
    if (gettimeofday(&time, NULL)) {
        //  Handle error
        return 0;
    }
    return time.tv_sec * 1000000 + time.tv_usec;
}

int main(int argc, char **argv) {
    ZeroMQClient client("tcp://127.0.0.1:8080");
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
        zmq::message_t msg(buff.data(), buff.size());
        auto ret = client.sendMsg(msg);
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