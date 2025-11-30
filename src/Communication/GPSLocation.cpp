#include "GPSLocation.h"
#include "../Config/Config.h"

GPSLocation::GPSLocation(int rx, int tx) {
    rxPin = rx;
    txPin = tx;
    gpsSerial = new SoftwareSerial(rxPin, txPin);
}

void GPSLocation::init() {
    gpsSerial->begin(GPS_BAUD);
}

void GPSLocation::update() {
    while (gpsSerial->available() > 0) {
        gps.encode(gpsSerial->read());
    }
}

bool GPSLocation::isValid() {
    return gps.location.isValid();
}

double GPSLocation::getLatitude() {
    return gps.location.lat();
}

double GPSLocation::getLongitude() {
    return gps.location.lng();
}
