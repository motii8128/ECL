#ifndef ECL_HPP_
#define ECL_HPP_

#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiUdp.h>
#include <string>

class ECLNode
{
  public:
    void init(const char *ssid, const char *passward, uint16_t port);
    const char *get_ssid();
    void set_destination(const char* address, uint16_t port);
    void send_message(const char *buf);


  private:
    WiFiUDP wifi_udp_;
    char ssid_[20];
    IPAddress server_ip_;
    uint16_t port_;
};

#endif