#include <thrift/concurrency/ThreadFactory.h>
#include <thrift/concurrency/ThreadManager.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TThreadPoolServer.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/transport/TSocket.h>
#include <string>
#include "gen-cpp/Echo.h"

#include <algorithm>
#include <thread>
#include <vector>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;
using std::string;
using std::vector;
using namespace ::Echo;

vector<std::thread> threads;
size_t thread_num = 1;
size_t buff_size = 4 * 1024;
size_t REQNUM = 500000;
string server_addr = "127.0.0.1";
int server_port = 8080;
vector<vector<size_t>> rep_times;

int64_t get_wall_time() {
    struct timeval time;
    if (gettimeofday(&time, NULL)) {
        //  Handle error
        return 0;
    }
    return time.tv_sec * 1000000 + time.tv_usec;
}

void client_func(int tid) {
    // printf("worker %d start\n", tid);
    std::shared_ptr<::TSocket> socket;
    std::shared_ptr<::TTransport> transport;
    std::shared_ptr<::TProtocol> protocol;
    std::shared_ptr<Echo::EchoClient> client;
    socket = std::make_shared<::TSocket>(server_addr, server_port);
    transport = std::shared_ptr<::TTransport>(new ::TFramedTransport(socket));
    protocol = std::shared_ptr<::TProtocol>(new ::TBinaryProtocol(transport));
    client = std::make_shared<Echo::EchoClient>(protocol);
    transport->open();
    string ret_buff;
    for (size_t i = 0; i < REQNUM; i++) {
        auto t1 = get_wall_time();
        client->read(ret_buff, buff_size);
        // printf("ret: %d, buf: %.*s\n", ret, (int) out_length, out_buf);
        if (ret_buff.size() != buff_size) {
            printf("error");
        }
        auto t2 = get_wall_time();
        rep_times[tid].push_back(t2 - t1);
    }
}

int main(int argc, char **argv) {

    if (argc == 6) {
        server_addr = string(argv[1]);
        server_port = std::atol(argv[2]);
        buff_size = std::atoll(argv[3]) * 1024;
        REQNUM = std::atoll(argv[4]);
        thread_num = std::atoll(argv[5]);
    }
    printf("server addr %s, port %d\n", server_addr.c_str(), server_port);
    printf("buff size is %ld\n", buff_size);
    printf("req num is %ld\n", REQNUM);
    printf("thread num is %ld\n", thread_num);

    rep_times.resize(thread_num);

    int64_t start_time = get_wall_time();
    for (size_t i = 0; i < thread_num; i++) {
        threads.push_back(std::thread(client_func, i));
    }
    for (size_t i = 0; i < thread_num; i++) {
        threads[i].join();
    }
    int64_t end_time = get_wall_time();

    double total_time_in_ms = (end_time - start_time) / 1000.0;

    REQNUM *= thread_num;
    printf("Requests: %ld, Total time: %.3lfms, qps: %.3f\n", REQNUM, total_time_in_ms,
           ((double) REQNUM / (total_time_in_ms / 1000.0)));
    printf("Transfer bytes: %.3lfMB, Total time: %.3lfms, bandwidth: %.3fMB/s\n", REQNUM * buff_size / (1024 * 1024.0),
           total_time_in_ms, ((double) (REQNUM * buff_size / (1024.0 * 1024)) / (total_time_in_ms / 1000.0)));

    vector<size_t> all_times;
    for (size_t i = 0; i < thread_num; i++) {
        for (const auto &t : rep_times[i]) {
            all_times.push_back(t);
        }
    }
    std::sort(all_times.begin(), all_times.end());
    size_t all_ave = 0;
    size_t first_ten_ave = 0;
    size_t latest_ten_ave = 0;
    for (size_t i = 0; i < all_times.size(); i++) {
        if (i < all_times.size() / 100.0 * 10) {  // first 10%
            first_ten_ave += all_times[i];
        }
        if (i >= all_times.size() / 100.0 * 90) {  // last 10%
            latest_ten_ave += all_times[i];
        }
        all_ave += all_times[i];
    }
    first_ten_ave /= (all_times.size()) / 100.0 * 10;
    latest_ten_ave /= (all_times.size()) / 100.0 * 10;
    all_ave /= all_times.size();

    // for (size_t i = 1; i <= 100; i++) {
    //     size_t off = (all_times.size() / 100.0) * i;
    //     if (off >= all_times.size()) off = all_times.size() - 1;
    //     printf("%ld ===> %ld\n", i, all_times[off]);
    // }
    printf("first 10%% ave latency: %ld\n", first_ten_ave);
    printf("last 10%% ave latency: %ld\n", latest_ten_ave);
    printf("all ave latency: %ld\n", all_ave);
    return 0;
}