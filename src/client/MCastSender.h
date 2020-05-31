#pragma once

#include "../common/common.h"
#include <functional>
#include <memory>
#include <string>
#include <string_view>
#include <asio/io_service.hpp>

namespace mcbridge {

class MCastSender {
 public:
   MCastSender();
   MCastSender(MCastSender &&);
   MCastSender &operator=(MCastSender &&);
   MCastSender(asio::io_service &io, EndPoint destination);
   ~MCastSender();
   void send_bytes(std::string_view const &bytes);
 private:
   struct PImpl;
   std::unique_ptr<PImpl> me;
};

} // namespace mcbridge