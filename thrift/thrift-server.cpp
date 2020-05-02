#include <thrift/concurrency/ThreadFactory.h>
#include <thrift/concurrency/ThreadManager.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TThreadPoolServer.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/transport/TSocket.h>
#include <memory>
#include <string>
#include <vector>
#include "gen-cpp/Echo.h"

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using namespace ::Echo;
using std::string;
using std::vector;

#define MAX_LEN 128 * 1024 * 1024
vector<char> random_text;

class EchoHandler : virtual public EchoIf {
   public:
    EchoHandler() {
        // Your initialization goes here
    }

    void echo(std::string &_return, const std::string &str) { _return.assign(str.begin(), str.end()); }
    void read(std::string &_return, const int32_t len) {
        assert(len < MAX_LEN);
        _return.assign(random_text.begin(), random_text.begin() + len);
    }
};

int main() {
    for (int i = 0; i < MAX_LEN; i++) {  // 128MB random buffer
        random_text.push_back(i % 255);
    }
    auto echoHandle = std::make_shared<EchoHandler>();
    const std::shared_ptr<EchoHandler> &handler(echoHandle);
    std::shared_ptr<::server::TProcessor> processor(new EchoProcessor(handler));
    std::shared_ptr<::TProtocolFactory> protocolFactory(new ::TBinaryProtocolFactory());
    auto threadManager = ::concurrency::ThreadManager::newSimpleThreadManager(32);
    auto threadFactory = std::make_shared<::concurrency::ThreadFactory>();
    threadManager->threadFactory(threadFactory);
    threadManager->start();
    std::shared_ptr<::TTransportFactory> transportFactory(new ::TFramedTransportFactory());
    auto server_transport = std::make_shared<::TServerSocket>("0.0.0.0", 8080);

    auto server_handle = std::make_shared<::server::TThreadPoolServer>(processor, server_transport, transportFactory,
                                                                       protocolFactory, threadManager);
    printf("server started\n");
    server_handle->serve();
    return 0;
}