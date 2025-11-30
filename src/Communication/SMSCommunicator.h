#ifndef SMS_COMMUNICATOR_H
#define SMS_COMMUNICATOR_H

#include <Arduino.h>
#include <SoftwareSerial.h>

class SMSCommunicator {
private:
    int rxPin;
    int txPin;
    SoftwareSerial* gsmSerial;

public:
    SMSCommunicator(int rx, int tx);
    void init();
    void sendSOS(double lat, double lon);
};

#endif
