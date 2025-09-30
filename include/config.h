#include <ArduinoJson.h>

#define DEVICE_NAME "sim1"

#define IR_RECEIVER_PIN 13
#define IR_TRANSMITTER_PIN 14

// STA Connection Info
const char* wifi_ssid = "ssid";
const char* wifi_password = "password";

// Change Wifi
JsonDocument wifi_data;
JsonDocument wifiJSON() {
    wifi_data["ssid"] = wifi_ssid;
    return wifi_data;
}
bool change_wifi = false;

// Access Point Info
const char* ap_ssid = "Sim1";
const char* ap_password = "password";
bool ap_mode = false;
