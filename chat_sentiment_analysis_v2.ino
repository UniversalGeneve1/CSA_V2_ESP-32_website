#include <ESPAsyncWebServer.h>
#include <FS.h>
#include "SPIFFS.h"
#include "secrets.h"
#include <WiFi.h>
#include <TimeLib.h>
#include <Wire.h> 
#include "SSD1306Wire.h"
#include "OLEDDisplayUi.h"
#include "images.h"

// Initialize the OLED display using Wire library
SSD1306Wire display(0x3c, SDA, SCL);
OLEDDisplayUi ui ( &display );

const char* ssid = SECRET_SSID;
const char* password = SECRET_SSID_PW;

AsyncWebServer server(80);

void setup(){
  Serial.begin(115200);

  // if (SPIFFS.begin(true)) {
  //   Serial.println("SPIFFS mounted successfully.");
  // } else {
  //   Serial.println("SPIFFS mount failed. Check your filesystem.");
  // }

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  Serial.println(WiFi.localIP());


  // server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
  //   request->send(LittleFS, "/index.html");
  // });

    // Define a route to serve the HTML page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest* request) {
    Serial.println("ESP32 Web Server: New request received:");  // for debugging
    Serial.println("GET /");        // for debugging
    request->send(200, "text/html", "<html><body><h1>Hello, ESP32!</h1></body></html>");
  });



  server.begin();



}


void loop(){
  
}