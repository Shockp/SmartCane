#include "SMSCommunicator.h"
#include "../Config/Config.h"

SMSCommunicator::SMSCommunicator(int rx, int tx) {
    rxPin = rx;
    txPin = tx;
    gsmSerial = new SoftwareSerial(rxPin, txPin);
}

void SMSCommunicator::init() {
    gsmSerial->begin(GSM_BAUD);
    delay(1000); // Wait for module to stabilize
}

void SMSCommunicator::sendSOS(double lat, double lon) {
    // Set SMS mode to text
    gsmSerial->println("AT+CMGF=1"); 
    delay(1000);
    
    // Replace with target phone number
    // In a real scenario, this might be hardcoded or configured
    gsmSerial->println("AT+CMGS=\"+1234567890\""); 
    delay(1000);
    
    gsmSerial->print("SOS! I need help. Location: https://maps.google.com/?q=");
    gsmSerial->print(lat, 6);
    gsmSerial->print(",");
    gsmSerial->print(lon, 6);
    
    delay(100);
    gsmSerial->write(26); // ASCII code of CTRL+Z to send
    delay(1000);
}
