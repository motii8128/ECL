#include <WiFi.h>
#include <WiFiUdp.h>

const char ssid[] = "ESP32_Server";       // SSID
const char password[] = "1234567890";     // password
const int localPort = 10000;              // ポート番号
const IPAddress ip(127, 0, 0, 1);       // ServerのIPアドレス
const IPAddress gateway(192, 168, 4, 1);  // gatewayのIPアドレス
const IPAddress subnet(255, 255, 255, 0); // サブネットマスク

WiFiUDP udp;
char packetBuffer[256];

void setup() {
  Serial.begin(115200);

  WiFi.softAP(ssid, password);
  delay(100);
  WiFi.softAPConfig(ip, gateway, subnet);

  Serial.println("Starting UDP");
  udp.begin(localPort);
}

void loop() {
  while (1) {
    int packetSize = udp.parsePacket();
    if (packetSize) {
      for (int i = 0 ; i < 256 ; i++ ) packetBuffer[i] = 0;
      udp.read(packetBuffer, 256);
      Serial.println(packetBuffer);
    }
  }
}