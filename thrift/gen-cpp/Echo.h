/**
 * Autogenerated by Thrift Compiler (0.13.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef Echo_H
#define Echo_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include <memory>
#include "echo_types.h"

namespace Echo {

#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class EchoIf {
 public:
  virtual ~EchoIf() {}
  virtual void echo(std::string& _return, const std::string& str) = 0;
  virtual void read(std::string& _return, const int32_t len) = 0;
};

class EchoIfFactory {
 public:
  typedef EchoIf Handler;

  virtual ~EchoIfFactory() {}

  virtual EchoIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(EchoIf* /* handler */) = 0;
};

class EchoIfSingletonFactory : virtual public EchoIfFactory {
 public:
  EchoIfSingletonFactory(const ::std::shared_ptr<EchoIf>& iface) : iface_(iface) {}
  virtual ~EchoIfSingletonFactory() {}

  virtual EchoIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(EchoIf* /* handler */) {}

 protected:
  ::std::shared_ptr<EchoIf> iface_;
};

class EchoNull : virtual public EchoIf {
 public:
  virtual ~EchoNull() {}
  void echo(std::string& /* _return */, const std::string& /* str */) {
    return;
  }
  void read(std::string& /* _return */, const int32_t /* len */) {
    return;
  }
};

typedef struct _Echo_echo_args__isset {
  _Echo_echo_args__isset() : str(false) {}
  bool str :1;
} _Echo_echo_args__isset;

class Echo_echo_args {
 public:

  Echo_echo_args(const Echo_echo_args&);
  Echo_echo_args& operator=(const Echo_echo_args&);
  Echo_echo_args() : str() {
  }

  virtual ~Echo_echo_args() noexcept;
  std::string str;

  _Echo_echo_args__isset __isset;

  void __set_str(const std::string& val);

  bool operator == (const Echo_echo_args & rhs) const
  {
    if (!(str == rhs.str))
      return false;
    return true;
  }
  bool operator != (const Echo_echo_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Echo_echo_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Echo_echo_pargs {
 public:


  virtual ~Echo_echo_pargs() noexcept;
  const std::string* str;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Echo_echo_result__isset {
  _Echo_echo_result__isset() : success(false) {}
  bool success :1;
} _Echo_echo_result__isset;

class Echo_echo_result {
 public:

  Echo_echo_result(const Echo_echo_result&);
  Echo_echo_result& operator=(const Echo_echo_result&);
  Echo_echo_result() : success() {
  }

  virtual ~Echo_echo_result() noexcept;
  std::string success;

  _Echo_echo_result__isset __isset;

  void __set_success(const std::string& val);

  bool operator == (const Echo_echo_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Echo_echo_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Echo_echo_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Echo_echo_presult__isset {
  _Echo_echo_presult__isset() : success(false) {}
  bool success :1;
} _Echo_echo_presult__isset;

class Echo_echo_presult {
 public:


  virtual ~Echo_echo_presult() noexcept;
  std::string* success;

  _Echo_echo_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Echo_read_args__isset {
  _Echo_read_args__isset() : len(false) {}
  bool len :1;
} _Echo_read_args__isset;

class Echo_read_args {
 public:

  Echo_read_args(const Echo_read_args&);
  Echo_read_args& operator=(const Echo_read_args&);
  Echo_read_args() : len(0) {
  }

  virtual ~Echo_read_args() noexcept;
  int32_t len;

  _Echo_read_args__isset __isset;

  void __set_len(const int32_t val);

  bool operator == (const Echo_read_args & rhs) const
  {
    if (!(len == rhs.len))
      return false;
    return true;
  }
  bool operator != (const Echo_read_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Echo_read_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Echo_read_pargs {
 public:


  virtual ~Echo_read_pargs() noexcept;
  const int32_t* len;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Echo_read_result__isset {
  _Echo_read_result__isset() : success(false) {}
  bool success :1;
} _Echo_read_result__isset;

class Echo_read_result {
 public:

  Echo_read_result(const Echo_read_result&);
  Echo_read_result& operator=(const Echo_read_result&);
  Echo_read_result() : success() {
  }

  virtual ~Echo_read_result() noexcept;
  std::string success;

  _Echo_read_result__isset __isset;

  void __set_success(const std::string& val);

  bool operator == (const Echo_read_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Echo_read_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Echo_read_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Echo_read_presult__isset {
  _Echo_read_presult__isset() : success(false) {}
  bool success :1;
} _Echo_read_presult__isset;

class Echo_read_presult {
 public:


  virtual ~Echo_read_presult() noexcept;
  std::string* success;

  _Echo_read_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class EchoClient : virtual public EchoIf {
 public:
  EchoClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  EchoClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void echo(std::string& _return, const std::string& str);
  void send_echo(const std::string& str);
  void recv_echo(std::string& _return);
  void read(std::string& _return, const int32_t len);
  void send_read(const int32_t len);
  void recv_read(std::string& _return);
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class EchoProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::std::shared_ptr<EchoIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (EchoProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_echo(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_read(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  EchoProcessor(::std::shared_ptr<EchoIf> iface) :
    iface_(iface) {
    processMap_["echo"] = &EchoProcessor::process_echo;
    processMap_["read"] = &EchoProcessor::process_read;
  }

  virtual ~EchoProcessor() {}
};

class EchoProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  EchoProcessorFactory(const ::std::shared_ptr< EchoIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::std::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::std::shared_ptr< EchoIfFactory > handlerFactory_;
};

class EchoMultiface : virtual public EchoIf {
 public:
  EchoMultiface(std::vector<std::shared_ptr<EchoIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~EchoMultiface() {}
 protected:
  std::vector<std::shared_ptr<EchoIf> > ifaces_;
  EchoMultiface() {}
  void add(::std::shared_ptr<EchoIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void echo(std::string& _return, const std::string& str) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->echo(_return, str);
    }
    ifaces_[i]->echo(_return, str);
    return;
  }

  void read(std::string& _return, const int32_t len) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->read(_return, len);
    }
    ifaces_[i]->read(_return, len);
    return;
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class EchoConcurrentClient : virtual public EchoIf {
 public:
  EchoConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(prot);
  }
  EchoConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void echo(std::string& _return, const std::string& str);
  int32_t send_echo(const std::string& str);
  void recv_echo(std::string& _return, const int32_t seqid);
  void read(std::string& _return, const int32_t len);
  int32_t send_read(const int32_t len);
  void recv_read(std::string& _return, const int32_t seqid);
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync_;
};

#ifdef _MSC_VER
  #pragma warning( pop )
#endif

} // namespace

#endif
