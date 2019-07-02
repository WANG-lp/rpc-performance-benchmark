// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: echo.proto
#ifndef GRPC_echo_2eproto__INCLUDED
#define GRPC_echo_2eproto__INCLUDED

#include "echo.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/method_handler_impl.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace grpc_impl {
class Channel;
class CompletionQueue;
class ServerCompletionQueue;
}  // namespace grpc_impl

namespace grpc {
namespace experimental {
template <typename RequestT, typename ResponseT>
class MessageAllocator;
}  // namespace experimental
}  // namespace grpc_impl

namespace grpc {
class ServerContext;
}  // namespace grpc

namespace echo {

class Echo final {
 public:
  static constexpr char const* service_full_name() {
    return "echo.Echo";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status echo(::grpc::ClientContext* context, const ::echo::Req& request, ::echo::Rep* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::echo::Rep>> Asyncecho(::grpc::ClientContext* context, const ::echo::Req& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::echo::Rep>>(AsyncechoRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::echo::Rep>> PrepareAsyncecho(::grpc::ClientContext* context, const ::echo::Req& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::echo::Rep>>(PrepareAsyncechoRaw(context, request, cq));
    }
    class experimental_async_interface {
     public:
      virtual ~experimental_async_interface() {}
      virtual void echo(::grpc::ClientContext* context, const ::echo::Req* request, ::echo::Rep* response, std::function<void(::grpc::Status)>) = 0;
      virtual void echo(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::echo::Rep* response, std::function<void(::grpc::Status)>) = 0;
      virtual void echo(::grpc::ClientContext* context, const ::echo::Req* request, ::echo::Rep* response, ::grpc::experimental::ClientUnaryReactor* reactor) = 0;
      virtual void echo(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::echo::Rep* response, ::grpc::experimental::ClientUnaryReactor* reactor) = 0;
    };
    virtual class experimental_async_interface* experimental_async() { return nullptr; }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::echo::Rep>* AsyncechoRaw(::grpc::ClientContext* context, const ::echo::Req& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::echo::Rep>* PrepareAsyncechoRaw(::grpc::ClientContext* context, const ::echo::Req& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status echo(::grpc::ClientContext* context, const ::echo::Req& request, ::echo::Rep* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::echo::Rep>> Asyncecho(::grpc::ClientContext* context, const ::echo::Req& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::echo::Rep>>(AsyncechoRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::echo::Rep>> PrepareAsyncecho(::grpc::ClientContext* context, const ::echo::Req& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::echo::Rep>>(PrepareAsyncechoRaw(context, request, cq));
    }
    class experimental_async final :
      public StubInterface::experimental_async_interface {
     public:
      void echo(::grpc::ClientContext* context, const ::echo::Req* request, ::echo::Rep* response, std::function<void(::grpc::Status)>) override;
      void echo(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::echo::Rep* response, std::function<void(::grpc::Status)>) override;
      void echo(::grpc::ClientContext* context, const ::echo::Req* request, ::echo::Rep* response, ::grpc::experimental::ClientUnaryReactor* reactor) override;
      void echo(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::echo::Rep* response, ::grpc::experimental::ClientUnaryReactor* reactor) override;
     private:
      friend class Stub;
      explicit experimental_async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class experimental_async_interface* experimental_async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class experimental_async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::echo::Rep>* AsyncechoRaw(::grpc::ClientContext* context, const ::echo::Req& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::echo::Rep>* PrepareAsyncechoRaw(::grpc::ClientContext* context, const ::echo::Req& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_echo_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status echo(::grpc::ServerContext* context, const ::echo::Req* request, ::echo::Rep* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_echo : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_echo() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_echo() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status echo(::grpc::ServerContext* context, const ::echo::Req* request, ::echo::Rep* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void Requestecho(::grpc::ServerContext* context, ::echo::Req* request, ::grpc::ServerAsyncResponseWriter< ::echo::Rep>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_echo<Service > AsyncService;
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_echo : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    ExperimentalWithCallbackMethod_echo() {
      ::grpc::Service::experimental().MarkMethodCallback(0,
        new ::grpc::internal::CallbackUnaryHandler< ::echo::Req, ::echo::Rep>(
          [this](::grpc::ServerContext* context,
                 const ::echo::Req* request,
                 ::echo::Rep* response,
                 ::grpc::experimental::ServerCallbackRpcController* controller) {
                   return this->echo(context, request, response, controller);
                 }));
    }
    void SetMessageAllocatorFor_echo(
        ::grpc::experimental::MessageAllocator< ::echo::Req, ::echo::Rep>* allocator) {
      static_cast<::grpc::internal::CallbackUnaryHandler< ::echo::Req, ::echo::Rep>*>(
          ::grpc::Service::experimental().GetHandler(0))
              ->SetMessageAllocator(allocator);
    }
    ~ExperimentalWithCallbackMethod_echo() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status echo(::grpc::ServerContext* context, const ::echo::Req* request, ::echo::Rep* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual void echo(::grpc::ServerContext* context, const ::echo::Req* request, ::echo::Rep* response, ::grpc::experimental::ServerCallbackRpcController* controller) { controller->Finish(::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "")); }
  };
  typedef ExperimentalWithCallbackMethod_echo<Service > ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_echo : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_echo() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_echo() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status echo(::grpc::ServerContext* context, const ::echo::Req* request, ::echo::Rep* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_echo : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithRawMethod_echo() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_echo() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status echo(::grpc::ServerContext* context, const ::echo::Req* request, ::echo::Rep* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void Requestecho(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_echo : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    ExperimentalWithRawCallbackMethod_echo() {
      ::grpc::Service::experimental().MarkMethodRawCallback(0,
        new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
          [this](::grpc::ServerContext* context,
                 const ::grpc::ByteBuffer* request,
                 ::grpc::ByteBuffer* response,
                 ::grpc::experimental::ServerCallbackRpcController* controller) {
                   this->echo(context, request, response, controller);
                 }));
    }
    ~ExperimentalWithRawCallbackMethod_echo() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status echo(::grpc::ServerContext* context, const ::echo::Req* request, ::echo::Rep* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual void echo(::grpc::ServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response, ::grpc::experimental::ServerCallbackRpcController* controller) { controller->Finish(::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "")); }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_echo : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithStreamedUnaryMethod_echo() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler< ::echo::Req, ::echo::Rep>(std::bind(&WithStreamedUnaryMethod_echo<BaseClass>::Streamedecho, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithStreamedUnaryMethod_echo() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status echo(::grpc::ServerContext* context, const ::echo::Req* request, ::echo::Rep* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status Streamedecho(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::echo::Req,::echo::Rep>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_echo<Service > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_echo<Service > StreamedService;
};

}  // namespace echo


#endif  // GRPC_echo_2eproto__INCLUDED
