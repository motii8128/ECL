#ifndef SERVER_HANDLER_HPP_
#define SERVER_HANDLER_HPP_

#include <WiFi.h>
#include <WiFiUdp.h>

namespace ESCL
{
  class ServerHandler
  {
    public:
      ServerHandler()

    private:
      const IPAddress ip(127, 0, 0, 1);
      const IPAddress gateway(127, 0, 0, 1);
      const IPAddress subnet(255, 255, 255, 0);
  }
}

#endif