#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#ifndef STASSID
#define STASSID "VIVO-0FE8"
#define STAPSK  "7AVqt9RcXX"
#endif

// Set your Static IP address
IPAddress server_IP(192, 168, 5, 10);
IPAddress gateway(192, 168, 5, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress primaryDNS(8, 8, 8, 8);   //optional
IPAddress secondaryDNS(8, 8, 4, 4);

const char* host = "192.168.5.10";
const uint16_t port = 80;

const char* ssid     = STASSID;
const char* password = STAPSK;
