
#include "config.h"
#define PIN_SAIDA 2


// Create an instance of the server
// specify the port to listen on as an argument
WiFiServer server(port);

void setup() {
  Serial.begin(115200);

  pinMode(PIN_SAIDA, OUTPUT);
  digitalWrite(PIN_SAIDA, 0);

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print(F("Connecting to "));
  Serial.println(ssid);

  // Configures static IP address
  if (!WiFi.config(server_IP, gateway, subnet, primaryDNS, secondaryDNS)) {
    Serial.println("STA Failed to configure");
  }

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(F("."));
  }
  Serial.println();
  Serial.println(F("WiFi connected"));

  // Start the server
  server.begin();
  Serial.println(F("Server started"));

  // Print the IP address
  Serial.println(WiFi.localIP());

  // prepare LED
  pinMode(PIN_SAIDA, OUTPUT);
  digitalWrite(PIN_SAIDA, 0);
}

String code;
void loop()
{
  WiFiClient client = server.available();

  if (client) {
    if (client.connected())
    {
      Serial.println("Client Connected");
    }

    while (client.connected()) {
      code="";
      while (client.available() > 0) {
        // read data from the connected client
        char ch = client.read();
        code+=ch; 
      }

      if(code!=""){
        Serial.print("code:");
        Serial.println(code);
        digitalWrite(PIN_SAIDA, int(code[2]));
      }
   
    }
    client.stop();
    Serial.println("Client disconnected");
  }
}
