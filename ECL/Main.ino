#include "ECL.hpp"

ECLNode node;
int count = 0;

void setup()
{
  Serial.begin(115200);
  const char *ssid = "Buffalo-G-C5C0";
  const char *pass = "fbxfck3kv3asf";
  node.init(ssid, pass, 5000);
}

void loop()
{
  count++;
  Serial.printf("hello %d\n", count);
  const char *msg = "Hello, World";
  node.set_destination("192.168.11.61", 8080);
  node.send_message(msg);
  delay(1000);
}