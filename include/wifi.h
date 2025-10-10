#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>

#include "config.h"

void connectWiFi_AP()
{

    Serial.println("Entering AP Mode");

    WiFi.mode(WIFI_AP);
    ap_mode = true;

    WiFi.softAP(ap_ssid, ap_password);

    Serial.print("IP address for network ");
    Serial.print(ap_ssid);
    Serial.print(" : ");
    Serial.println(WiFi.softAPIP());
}

void connectWiFi_STA()
{

    Serial.println("Entering STA Mode");
    WiFi.mode(WIFI_STA);
    Serial.print("Connecting to ");
    Serial.println(wifi_ssid);
    WiFi.begin(wifi_ssid, wifi_password);

    int connection_timer = 0;
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
        connection_timer++;
        if (connection_timer == 50)
        {
            Serial.println("\nFailed to connect to network, switching to access point mode");
            connectWiFi_AP();
            break;
        }
    }

    if (WiFi.status() == WL_CONNECTED)
    {
        Serial.println("");
        Serial.println("WiFi connected.");
        Serial.println("IP address: ");
        Serial.println(WiFi.localIP());
    }
}

void startMDNS()
{
    if (MDNS.begin(DEVICE_NAME))
    {
        Serial.println("mDNS responder started");
    }
}

void manageWifi()
{
    MDNS.update();

    if (WiFi.status() != WL_CONNECTED and ap_mode == false)
    {
        Serial.println("Wifi Disconnected");
        connectWiFi_AP();
    }

    if (change_wifi == true)
    {
        change_wifi = false;
        ap_mode = false;
        connectWiFi_STA();
    }
}