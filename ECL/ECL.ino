#include "ECL.hpp"

void ECLNode::init(const char *ssid, const char *passward, uint16_t port)
{
  Serial.println("\n\n");
  int i = 0;
  bool flag = true;
  WiFi.begin(ssid, passward);
  while(WiFi.status() != WL_CONNECTED)
  {
    i++;
    Serial.printf(".");
    delay(50);
    if(i > 30)
    {
      flag = false;
      break;
    }
  }

  if(flag == true)
  {
    strcpy(ssid_, ssid);
    Serial.printf("[ECL]Successed connect to ");
    Serial.println(ssid_);
    wifi_udp_.begin(port);
    Serial.println("[ECL]Start UDP Client");
  }
}

const char *ECLNode::get_ssid()
{
  return ssid_;
}

void ECLNode::set_destination(const char *address, uint16_t port)
{
  server_ip_.fromString(address);
  port_ = port;
}

void ECLNode::send_message(const char *buf)
{
  wifi_udp_.beginPacket(server_ip_, port_);
  wifi_udp_.printf(buf);
  wifi_udp_.endPacket();
}