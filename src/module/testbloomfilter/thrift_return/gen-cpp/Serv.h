/**
 * Autogenerated by Thrift Compiler (0.9.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef Serv_H
#define Serv_H

#include <thrift/TDispatchProcessor.h>
#include "msg_types.h"



class ServIf {
 public:
  virtual ~ServIf() {}
  virtual void send_url_list(std::vector<ITEM> & _return, const std::vector<ITEM> & list_url) = 0;
};

class ServIfFactory {
 public:
  typedef ServIf Handler;

  virtual ~ServIfFactory() {}

  virtual ServIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(ServIf* /* handler */) = 0;
};

class ServIfSingletonFactory : virtual public ServIfFactory {
 public:
  ServIfSingletonFactory(const boost::shared_ptr<ServIf>& iface) : iface_(iface) {}
  virtual ~ServIfSingletonFactory() {}

  virtual ServIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(ServIf* /* handler */) {}

 protected:
  boost::shared_ptr<ServIf> iface_;
};

class ServNull : virtual public ServIf {
 public:
  virtual ~ServNull() {}
  void send_url_list(std::vector<ITEM> & /* _return */, const std::vector<ITEM> & /* list_url */) {
    return;
  }
};

typedef struct _Serv_send_url_list_args__isset {
  _Serv_send_url_list_args__isset() : list_url(false) {}
  bool list_url;
} _Serv_send_url_list_args__isset;

class Serv_send_url_list_args {
 public:

  Serv_send_url_list_args() {
  }

  virtual ~Serv_send_url_list_args() throw() {}

  std::vector<ITEM>  list_url;

  _Serv_send_url_list_args__isset __isset;

  void __set_list_url(const std::vector<ITEM> & val) {
    list_url = val;
  }

  bool operator == (const Serv_send_url_list_args & rhs) const
  {
    if (!(list_url == rhs.list_url))
      return false;
    return true;
  }
  bool operator != (const Serv_send_url_list_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Serv_send_url_list_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Serv_send_url_list_pargs {
 public:


  virtual ~Serv_send_url_list_pargs() throw() {}

  const std::vector<ITEM> * list_url;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Serv_send_url_list_result__isset {
  _Serv_send_url_list_result__isset() : success(false) {}
  bool success;
} _Serv_send_url_list_result__isset;

class Serv_send_url_list_result {
 public:

  Serv_send_url_list_result() {
  }

  virtual ~Serv_send_url_list_result() throw() {}

  std::vector<ITEM>  success;

  _Serv_send_url_list_result__isset __isset;

  void __set_success(const std::vector<ITEM> & val) {
    success = val;
  }

  bool operator == (const Serv_send_url_list_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Serv_send_url_list_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Serv_send_url_list_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Serv_send_url_list_presult__isset {
  _Serv_send_url_list_presult__isset() : success(false) {}
  bool success;
} _Serv_send_url_list_presult__isset;

class Serv_send_url_list_presult {
 public:


  virtual ~Serv_send_url_list_presult() throw() {}

  std::vector<ITEM> * success;

  _Serv_send_url_list_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class ServClient : virtual public ServIf {
 public:
  ServClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  ServClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    piprot_(iprot),
    poprot_(oprot) {
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void send_url_list(std::vector<ITEM> & _return, const std::vector<ITEM> & list_url);
  void send_send_url_list(const std::vector<ITEM> & list_url);
  void recv_send_url_list(std::vector<ITEM> & _return);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class ServProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<ServIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (ServProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_send_url_list(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  ServProcessor(boost::shared_ptr<ServIf> iface) :
    iface_(iface) {
    processMap_["send_url_list"] = &ServProcessor::process_send_url_list;
  }

  virtual ~ServProcessor() {}
};

class ServProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  ServProcessorFactory(const ::boost::shared_ptr< ServIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< ServIfFactory > handlerFactory_;
};

class ServMultiface : virtual public ServIf {
 public:
  ServMultiface(std::vector<boost::shared_ptr<ServIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~ServMultiface() {}
 protected:
  std::vector<boost::shared_ptr<ServIf> > ifaces_;
  ServMultiface() {}
  void add(boost::shared_ptr<ServIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void send_url_list(std::vector<ITEM> & _return, const std::vector<ITEM> & list_url) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->send_url_list(_return, list_url);
    }
    ifaces_[i]->send_url_list(_return, list_url);
    return;
  }

};



#endif
