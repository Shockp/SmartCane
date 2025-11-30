#ifndef GPS_LOCATION_H
#define GPS_LOCATION_H

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h> // Requires TinyGPSPlus library

class GPSLocation {
private:
    int rxPin;
    int txPin;
    SoftwareSerial* gpsSerial;
    TinyGPSPlus gps;

public:
    GPSLocation(int rx, int tx);
    void init();
    void update();
    bool isValid();
    double getLatitude();
    double getLongitude();
};

#endif
