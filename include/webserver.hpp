#include <ESP8266WebServer.h>

#include "webpages.h"
#include "status.h"
#include "ir.h"

ESP8266WebServer server(80);

void serverRouting()
{
    server.on("/", HTTP_GET, []()
        { server.send(200, "text/html", indexHTML); });

    server.on("/config", HTTP_GET, []()
        { server.send(200, "text/html", configHTML); });

    server.on("/status", HTTP_GET, []()
        {
        char output[265];
        serializeJson(updateStatus(), output);

        server.send(201, "application/json", output); });

    server.on("/control", HTTP_POST, []()
        {
        String input = server.arg("plain");
        
        JsonDocument doc;
        deserializeJson(doc, input);

        for (int i = 0; i <= 3; i++) {
            if (doc["bay"] == i + 1) {
                clock_time_original[i] = doc["time"];
                clock_time[i] = doc["time"];
            }
        }

        server.send(201, "text/plain", "Request received"); });

    server.on("/wifi", HTTP_GET, []()
        {
        char output[265];
        serializeJson(wifiJSON(), output);

        server.send(201, "application/json", output); });

    server.on("/changewifi", HTTP_POST, []()
        {

        String input = server.arg("plain");
        
        JsonDocument doc;
        deserializeJson(doc, input);

        wifi_ssid = doc["ssid"];
        wifi_password = doc["password"];

        change_wifi = true;
    
        server.send(201, "text/plain", "Request received"); });
}

void initServer()
{
    server.begin();
    serverRouting();
    Serial.println("HTTP server started on port 80");
}