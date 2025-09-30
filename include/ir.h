#include <IRremote.h>

void IRinit()
{
    IrReceiver.begin(IR_RECEIVER_PIN, ENABLE_LED_FEEDBACK);
    IrSender.begin(IR_TRANSMITTER_PIN);
}

void IRreceive()
{
    if (IrReceiver.decode())
    {
        Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
        IrReceiver.printIRResultShort(&Serial);
        IrReceiver.printIRSendUsage(&Serial);
        IrReceiver.resume();
    }
}

void IRtransmit()
{
    IrSender.sendPanasonic(0x91C0, 0x9E10, 1);
    Serial.println("IR sent");
    delay(1000);
}