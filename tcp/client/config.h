#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#ifndef STASSID
#define STASSID "VIVO-0FE8"
#define STAPSK  "7AVqt9RcXX"
#endif

const char* host = "192.168.0.10";
const uint16_t port = 80;
const char* ssid     = STASSID;
const char* password = STAPSK;
