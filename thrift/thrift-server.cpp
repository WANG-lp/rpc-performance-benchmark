#include <memory>
#include <thrift/concurrency/PosixThreadFactory.h>
#include <thrift/concurrency/ThreadManager.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TThreadPoolServer.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/transport/TSocket.h>
#include "gen-cpp/Echo.h"
#include <vector>
#include <string>


using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using namespace ::Echo;
using std::vector;
using std::string;

class EchoHandler : virtual public EchoIf {
   public:
    EchoHandler() {
        // Your initialization goes here
    }

    void echo(std::string &_return, const std::string &str) {
        _return.assign(str.begin(), str.end());
    }
};

int main() {
    auto echoHandle = std::make_shared<EchoHandler>();
    const std::shared_ptr<EchoHandler> &handler(echoHandle);
    std::shared_ptr<::server::TProcessor> processor(new EchoProcessor(handler));
    std::shared_ptr<::TProtocolFactory> protocolFactory(new ::TBinaryProtocolFactory());
    auto threadManager = ::concurrency::ThreadManager::newSimpleThreadManager(1);
    auto threadFactory = std::make_shared<::concurrency::PosixThreadFactory>();
    threadManager->threadFactory(threadFactory);
    threadManager->start();
    std::shared_ptr<::TTransportFactory> transportFactory(new ::TFramedTransportFactory());
    auto server_transport = std::make_shared<::TServerSocket>(8080);

    auto server_handle = std::make_shared<::server::TThreadPoolServer>(processor, server_transport, transportFactory,
                                                                       protocolFactory, threadManager);
    server_handle->serve();
    return 0;
}