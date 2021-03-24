#include "config.h"
#define PIN_ENTRADA 2
#define TIME_INTERVAL 5

int statePinEntrada;
ESP8266WiFiMulti WiFiMulti;
WiFiClient client;


void setup() {
  Serial.begin(115200);

  // We start by connecting to a WiFi network
  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP(ssid, password);

  Serial.print("Wait for WiFi... ");
  while (WiFiMulti.run() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

 // setup pins
  pinMode(PIN_ENTRADA, INPUT);
  statePinEntrada = digitalRead(PIN_ENTRADA);
  sendState();
  
  delay(500);
}



void sendState() {
  Serial.print("connecting to ");
  Serial.print(host);
  Serial.print(':');
  Serial.println(port);

  int stateTemp = digitalRead(PIN_ENTRADA);

  // Use WiFiClient class to create TCP connections
  WiFiClient client;

  if (client.connect(host, port)) {
    // This will send the request to the server
    String msg =  "#" + String(PIN_ENTRADA) + String(stateTemp) + String("#");

    client.println(msg);
    Serial.println("data sent");

    statePinEntrada = stateTemp;

    Serial.println("closing connection");
    client.stop();
  } else {
    Serial.print("Not Connected.");
  }
}

unsigned long previousMillis = 0;        // will store last time LED was updated
const long interval = TIME_INTERVAL;

void loop() {


  if (digitalRead(PIN_ENTRADA) != statePinEntrada) {
    sendState();
  }


  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    sendState();
  }
}
