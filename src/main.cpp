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

    IrReceiver.begin(IR_RECEIVER_PIN, ENABLE_LED_FEEDBACK);
    IrSender.begin(IR_TRANSMITTER_PIN);
}

void loop()
{
    server.handleClient();
    manageWifi();

    
}