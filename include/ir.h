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
    IrSender.sendSamsung(0x7, 0x2, 1);
    Serial.println("IR sent");
}

void IRmanager()
{
    for (int i = 0; i <= 3; i++)
    {
        if ((clock_time[i] == 0) and power[i] and (clock_time_original != 0))
        {
            IRtransmit();
            power[i] = false;
        }
    }
}

void IRmanager(int bay)
{
    IRtransmit();
    power[bay] = !power[bay];
}