#include <Arduino.h>

#include "wifi.h"
#include "webserver.hpp"

void setup()
{
    Serial.begin(115200);
    Serial.println("");
    connectWiFi_STA();
    startMDNS();
    initServer();
    timer();
}

void loop()
{
    server.handleClient();
    manageWifi();
    IRmanager();
}