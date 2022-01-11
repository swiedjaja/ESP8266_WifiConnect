#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ArduinoOTA.h>
#include "wifi_id.h"
#define HOSTNAME "esp8266_ota1"
void setup() {
  Serial.begin(115200);
  while (!Serial)
  {
    delay(10);
    continue;
  }
  Serial.println("Booting...");
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.waitForConnectResult() != WL_CONNECTED)
  {
    Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }
  Serial.print("System online with IP address: ");
  Serial.println(WiFi.localIP());  
  Serial.printf("Signal rssi: %d\n", WiFi.RSSI());  

  ArduinoOTA.setHostname(HOSTNAME);
  // ArduinoOTA.setPassword(OTA_PASSWORD);
  ArduinoOTA.begin();
}

void loop() {
    ArduinoOTA.handle();
}