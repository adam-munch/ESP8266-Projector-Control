#include <IRremote.h>

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
    delay(1000);
}